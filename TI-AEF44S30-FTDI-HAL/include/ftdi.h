#pragma once

#include <vector>
#include <stdio.h>
#include <string>

// Files
#include "errorhandler.h";

// Libraries
#include "ftd2xx.h"
#include "LibFT4222.h"

// Constants definitions
#define SLAVE_ADDR 0x5B 

class FTDI {

public:
	static std::vector<FT_DEVICE_LIST_INFO_NODE> listFtUSBDevices();


	// ----------------- FTDI chip setup -----------------//

	/// <summary>
	/// Opens the FTDI device by the reference handle.
	/// </summary>
	static void openDevice(FT_HANDLE& ftHandle);

	/// <summary>
	/// Initializes the FT4222 chips as GPIO comms.
	/// </summary>
	static void initFTAsI2CMaster(FT_HANDLE& ftHandle);


	// ----------------- Sensor operations -----------------//
	static void I2CWrite(FT_HANDLE& ftHandle, uint8 data[], uint8 bytesToWrite, uint16* bytesWritten);


	static void readRegister(FT_HANDLE& ftHandle, byte regAddr, uint8* readBuf, uint16 readBuffSize);

	static void writeRegister(FT_HANDLE& ftHandle, uint8 regAddr, int data, uint8 dataLen, uint16* bytesWritten);
	static void writeRegister(FT_HANDLE& ftHandle, uint8 regAddr, int data);



	// ----------------- Device status -----------------//

	/// <summary>
	/// Prints the Master device status to the console (stdout).
	/// </summary>
	/// <param name="ftHandle"></param>
	static void printDeviceStatus(FT_HANDLE& ftHandle);


	// ----------------- FTDI chip destruction -----------------//

	/// <summary>
	/// Resets I2C Master Bus, uninitializes and closes the device by the reference handle.
	/// </summary>
	static void closeDevice(FT_HANDLE& ftHandle);



};

