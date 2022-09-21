#include "ftdi.h"


/// <summary>
/// Converts device flags to hardware type as string.
/// </summary>
/// <param name="flags"></param>
/// <returns>The string of converted flags</returns>
inline std::string DeviceFlagToString(DWORD flags)
{
	std::string msg;
	msg += (flags & 0x1) ? "DEVICE_OPEN" : "DEVICE_CLOSED";
	msg += ", ";
	msg += (flags & 0x2) ? "High-speed USB" : "Full-speed USB";
	return msg;
}

/// <summary>
/// Lists all FTDI USB devices.
/// </summary>
std::vector<FT_DEVICE_LIST_INFO_NODE> FTDI::listFtUSBDevices()
{
	std::vector<FT_DEVICE_LIST_INFO_NODE> g_FT4222DevList;

	FT_STATUS ftStatus = 0;

	DWORD numOfDevices = 0;
	ftStatus = FT_CreateDeviceInfoList(&numOfDevices);

	for (DWORD iDev = 0; iDev < numOfDevices; ++iDev)
	{
		FT_DEVICE_LIST_INFO_NODE devInfo;
		memset(&devInfo, 0, sizeof(devInfo));

		ftStatus = FT_GetDeviceInfoDetail(iDev, &devInfo.Flags, &devInfo.Type, &devInfo.ID, &devInfo.LocId,
			devInfo.SerialNumber,
			devInfo.Description,
			&devInfo.ftHandle);

		if (FT_OK == ftStatus)
		{
			printf("Dev %d:\n", iDev);
			printf("  Flags= 0x%x, (%s)\n", devInfo.Flags, DeviceFlagToString(devInfo.Flags).c_str());
			printf("  Type= 0x%x\n", devInfo.Type);
			printf("  ID= 0x%x\n", devInfo.ID);
			printf("  LocId= 0x%x\n", devInfo.LocId);
			printf("  SerialNumber= %s\n", devInfo.SerialNumber);
			printf("  Description= %s\n", devInfo.Description);
			printf("  ftHandle= 0x%x\n", devInfo.ftHandle);

			const std::string desc = devInfo.Description;



			g_FT4222DevList.push_back(devInfo);

		}
	}

	return g_FT4222DevList;
}


void FTDI::openDevice(FT_HANDLE& ftHandle)
{
	// Get a list of devices and return if no devices found.
	auto deviceList = listFtUSBDevices();
	if (deviceList.empty())
	{
		ErrorHandler::logError("No device found!");
		return;
	}

	// Open the device and check its status
	auto deviceStatus = FT_OpenEx((PVOID)deviceList[0].LocId, FT_OPEN_BY_LOCATION, &ftHandle);
	if (deviceStatus != FT_OK)
	{
		ErrorHandler::logErrorAndExit("Could not open the device");
		return;
	}
}


void FTDI::initFTAsI2CMaster(FT_HANDLE& ftHandle)
{
	auto ftStatus = FT4222_I2CMaster_Init(ftHandle, 400);
	if (ftStatus != FT4222_OK)
	{
		ErrorHandler::logErrorAndExit("Could not initialize FTDI as master");
	}
}

void FTDI::I2CWrite(FT_HANDLE& ftHandle, uint8 data[], uint8 bytesToWrite, uint16* bytesWritten)
{
	auto status = FT4222_I2CMaster_Write(ftHandle, SLAVE_ADDR, data, bytesToWrite, bytesWritten);
	if (status != FT4222_OK)
	{
		ErrorHandler::logError("Failed to write I2C Device");
	}
}

void FTDI::readRegister(FT_HANDLE& ftHandle, byte regAddr, uint8* readBuf, uint16 readBuffSize)
{
	uint16 bytesTransferred;

	auto status = FT4222_I2CMaster_WriteEx(ftHandle, SLAVE_ADDR, START, &regAddr, 1, &bytesTransferred);
	if (status != FT4222_OK)
	{
		ErrorHandler::logError("Could not request a read from the register");	
	}

	status = FT4222_I2CMaster_ReadEx(ftHandle, SLAVE_ADDR, START_AND_STOP, readBuf, readBuffSize, &bytesTransferred);
	if (status != FT4222_OK)
	{
		ErrorHandler::logError("Could not read the data from the sensor register");
	}


}


void FTDI::writeRegister(FT_HANDLE& ftHandle, byte regAddr, int data, uint8 dataLen, uint16* bytesWritten)
{
	// Check for total bytes to write to not be more than 4
	if (dataLen > 3) {
		ErrorHandler::logError("Cannot write more than 4 bytes to the slave at one time.");
		return;
	}

	byte writeData[4] = { regAddr, (byte)(data >> 16), (byte)(data >> 8), (byte)data };
	FTDI::I2CWrite(ftHandle, writeData, dataLen + 1, bytesWritten);
}


void FTDI::writeRegister(FT_HANDLE& ftHandle, byte regAddr, int data)
{
	uint16 bytesWritten;
	byte writeData[4] = { regAddr, (byte)(data >> 16), (byte)(data >> 8), (byte)data };
	FTDI::I2CWrite(ftHandle, writeData, 4, &bytesWritten);
}

void FTDI::printDeviceStatus(FT_HANDLE& ftHandle)
{
	uint8 controllerStatus;
	FT4222_I2CMaster_GetStatus(ftHandle, &controllerStatus);
	printf("Status: %d \n ", controllerStatus);
}



void FTDI::closeDevice(FT_HANDLE& ftHandle)
{
	FT4222_I2CMaster_ResetBus(ftHandle); // Debug only for now
	FT4222_I2CMaster_Reset(ftHandle);
	FT4222_UnInitialize(ftHandle);
	FT_Close(ftHandle);
}
