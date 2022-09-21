#include <afe.h>

void AFE::configureSensor(FT_HANDLE& ftHandle)
{
	// Check the chip ID to make sure its matching
	uint8 readBuf[3];
	FTDI::readRegister(ftHandle, 0x28, readBuf, 3);

	int chipID = (readBuf[1] * 256 + readBuf[2]) >> 7;

	if (chipID != 0x0E && chipID != 0x1E)
	{
		ErrorHandler::logError("Invalid sensor. Sensor Id found was: " + chipID);
		return;
	}

	std::cout << "Sensor found! Configuring registers..." << std::endl;

	FTDI::writeRegister(ftHandle, 0x00, 0x000008);
	FTDI::writeRegister(ftHandle, 0x01, 0x000000);
	FTDI::writeRegister(ftHandle, 0x00, 0x000002);
	FTDI::writeRegister(ftHandle, 0x42, 0x000460);
	FTDI::writeRegister(ftHandle, 0x02, 0x640000);
	FTDI::writeRegister(ftHandle, 0x03, 0x000000);
	FTDI::writeRegister(ftHandle, 0x04, 0x000000);
	FTDI::writeRegister(ftHandle, 0x1E, 0x000000);
	FTDI::writeRegister(ftHandle, 0x23, 0x068000);
	FTDI::writeRegister(ftHandle, 0x24, 0x006000);
	FTDI::writeRegister(ftHandle, 0x25, 0x000000);
	FTDI::writeRegister(ftHandle, 0x28, 0x000000);
	FTDI::writeRegister(ftHandle, 0x29, 0x000000);
	FTDI::writeRegister(ftHandle, 0x30, 0x000000);
	FTDI::writeRegister(ftHandle, 0x31, 0x000000);
	FTDI::writeRegister(ftHandle, 0x42, 0x000460);
	FTDI::writeRegister(ftHandle, 0x4B, 0x000000);
	FTDI::writeRegister(ftHandle, 0x4E, 0x00C004);
	FTDI::writeRegister(ftHandle, 0x50, 0x000000);
	FTDI::writeRegister(ftHandle, 0x51, 0x000000);
	FTDI::writeRegister(ftHandle, 0x57, 0x000000);
	FTDI::writeRegister(ftHandle, 0x58, 0x000000);
	FTDI::writeRegister(ftHandle, 0x62, 0x000000);
	FTDI::writeRegister(ftHandle, 0x6C, 0x028000);
	FTDI::writeRegister(ftHandle, 0x6D, 0x000000);
	FTDI::writeRegister(ftHandle, 0x72, 0x000000);
	FTDI::writeRegister(ftHandle, 0x73, 0x003C3C);
	FTDI::writeRegister(ftHandle, 0x74, 0x000000);
	FTDI::writeRegister(ftHandle, 0x75, 0x000000);
	FTDI::writeRegister(ftHandle, 0x78, 0x80E005);
	FTDI::writeRegister(ftHandle, 0x79, 0x00E00E);
	FTDI::writeRegister(ftHandle, 0x7C, 0x000300);
	FTDI::writeRegister(ftHandle, 0x7D, 0x000004);
	FTDI::writeRegister(ftHandle, 0x80, 0x000000);
	FTDI::writeRegister(ftHandle, 0x81, 0x000000);
	FTDI::writeRegister(ftHandle, 0x88, 0x000048);
	FTDI::writeRegister(ftHandle, 0x8A, 0x026016);
	FTDI::writeRegister(ftHandle, 0x8B, 0x000100);
	FTDI::writeRegister(ftHandle, 0x8C, 0x000000);
	FTDI::writeRegister(ftHandle, 0x8D, 0x000003);
	FTDI::writeRegister(ftHandle, 0x8E, 0x005001);
	FTDI::writeRegister(ftHandle, 0x8F, 0x000000);
	FTDI::writeRegister(ftHandle, 0x92, 0x000000);
	FTDI::writeRegister(ftHandle, 0x93, 0x000000);
	FTDI::writeRegister(ftHandle, 0x94, 0x000084);
	FTDI::writeRegister(ftHandle, 0x95, 0x000050);
	FTDI::writeRegister(ftHandle, 0x96, 0x001111);
	FTDI::writeRegister(ftHandle, 0x97, 0x000000);
	FTDI::writeRegister(ftHandle, 0x98, 0x000000);
	FTDI::writeRegister(ftHandle, 0x99, 0x000000);
	FTDI::writeRegister(ftHandle, 0x9A, 0x000000);
	FTDI::writeRegister(ftHandle, 0x9C, 0x000000);
	FTDI::writeRegister(ftHandle, 0x9D, 0x000000);
	FTDI::writeRegister(ftHandle, 0x9E, 0x000000);
	FTDI::writeRegister(ftHandle, 0xA0, 0x000000);
	FTDI::writeRegister(ftHandle, 0xA1, 0x000000);
	FTDI::writeRegister(ftHandle, 0xA2, 0x000000);
	FTDI::writeRegister(ftHandle, 0xA4, 0x000000);
	FTDI::writeRegister(ftHandle, 0xA5, 0x000000);
	FTDI::writeRegister(ftHandle, 0xA6, 0x000000);
	FTDI::writeRegister(ftHandle, 0xA9, 0x001111);
	FTDI::writeRegister(ftHandle, 0xAA, 0x000000);
	FTDI::writeRegister(ftHandle, 0xAE, 0x000000);
	FTDI::writeRegister(ftHandle, 0xB0, 0x200000);
	FTDI::writeRegister(ftHandle, 0xB4, 0x000000);
	FTDI::writeRegister(ftHandle, 0xB5, 0x000000);
	FTDI::writeRegister(ftHandle, 0xB6, 0x000000);
	FTDI::writeRegister(ftHandle, 0xB7, 0x018005);
	FTDI::writeRegister(ftHandle, 0xB9, 0x2EA063);
	FTDI::writeRegister(ftHandle, 0xBA, 0x000064);
	FTDI::writeRegister(ftHandle, 0xBB, 0x000000);
	FTDI::writeRegister(ftHandle, 0xBC, 0x000000);
	FTDI::writeRegister(ftHandle, 0xBE, 0x000301);
	FTDI::writeRegister(ftHandle, 0xC0, 0xAA0100);
	FTDI::writeRegister(ftHandle, 0xC1, 0x092491);
	FTDI::writeRegister(ftHandle, 0xC2, 0x000000);
	FTDI::writeRegister(ftHandle, 0xC3, 0x100300);
	FTDI::writeRegister(ftHandle, 0xC4, 0x000102);
	FTDI::writeRegister(ftHandle, 0xC5, 0x000000);
	FTDI::writeRegister(ftHandle, 0xC7, 0x000000);
	FTDI::writeRegister(ftHandle, 0xCA, 0x024880);
	FTDI::writeRegister(ftHandle, 0xCB, 0x00004F);
	FTDI::writeRegister(ftHandle, 0xCF, 0x008E08);
	FTDI::writeRegister(ftHandle, 0xD0, 0x000100);
	FTDI::writeRegister(ftHandle, 0xD1, 0x000001);
	FTDI::writeRegister(ftHandle, 0xD2, 0x000000);
	FTDI::writeRegister(ftHandle, 0xD3, 0x000000);
	FTDI::writeRegister(ftHandle, 0xD5, 0x000000);
	FTDI::writeRegister(ftHandle, 0xD7, 0x0A7200);
	FTDI::writeRegister(ftHandle, 0xD8, 0x0A7276);
	FTDI::writeRegister(ftHandle, 0xD9, 0x00004D);
	FTDI::writeRegister(ftHandle, 0x01, 0x000001);
	FTDI::writeRegister(ftHandle, 0x20, 0x120010);
	FTDI::writeRegister(ftHandle, 0x21, 0x000CB0);
	FTDI::writeRegister(ftHandle, 0x22, 0xC01001); //C0100E
	FTDI::writeRegister(ftHandle, 0x23, 0x0005C0);
	FTDI::writeRegister(ftHandle, 0x24, 0x000000);
	FTDI::writeRegister(ftHandle, 0x25, 0x120010);
	FTDI::writeRegister(ftHandle, 0x26, 0x000DB0);
	FTDI::writeRegister(ftHandle, 0x27, 0xC01001); //C0100E
	FTDI::writeRegister(ftHandle, 0x28, 0x0004C0);
	FTDI::writeRegister(ftHandle, 0x29, 0x000006);
	FTDI::writeRegister(ftHandle, 0x2A, 0x120080);
	FTDI::writeRegister(ftHandle, 0x2B, 0x000DB0);
	FTDI::writeRegister(ftHandle, 0x2C, 0xC01001); //C0100E
	FTDI::writeRegister(ftHandle, 0x2D, 0x0004C0);
	FTDI::writeRegister(ftHandle, 0x2E, 0x000006);
	FTDI::writeRegister(ftHandle, 0x2F, 0x120040);
	FTDI::writeRegister(ftHandle, 0x30, 0x000DB0);
	FTDI::writeRegister(ftHandle, 0x31, 0xC01001); //C0100E
	FTDI::writeRegister(ftHandle, 0x32, 0x0004C0);
	FTDI::writeRegister(ftHandle, 0x33, 0x000006);
	FTDI::writeRegister(ftHandle, 0x34, 0x120020);
	FTDI::writeRegister(ftHandle, 0x35, 0x000CB0);
	FTDI::writeRegister(ftHandle, 0x36, 0xC01001); //C0100E
	FTDI::writeRegister(ftHandle, 0x37, 0x0004C0);
	FTDI::writeRegister(ftHandle, 0x38, 0x000006);
	FTDI::writeRegister(ftHandle, 0x39, 0x120001);
	FTDI::writeRegister(ftHandle, 0x3A, 0x000DB0);
	FTDI::writeRegister(ftHandle, 0x3B, 0xC01001); //C0100E
	FTDI::writeRegister(ftHandle, 0x3C, 0x0004C0);
	FTDI::writeRegister(ftHandle, 0x3D, 0x000006);
	FTDI::writeRegister(ftHandle, 0x3E, 0x120002);
	FTDI::writeRegister(ftHandle, 0x3F, 0x000CB0);
	FTDI::writeRegister(ftHandle, 0x40, 0xC01001); //C0100E
	FTDI::writeRegister(ftHandle, 0x41, 0x0004C0);
	FTDI::writeRegister(ftHandle, 0x42, 0x000006);
	FTDI::writeRegister(ftHandle, 0x43, 0x120004);
	FTDI::writeRegister(ftHandle, 0x44, 0x000DB0);
	FTDI::writeRegister(ftHandle, 0x45, 0xC01001); //C0100E
	FTDI::writeRegister(ftHandle, 0x46, 0x0004C0);
	FTDI::writeRegister(ftHandle, 0x47, 0x000006);
	FTDI::writeRegister(ftHandle, 0x48, 0x120008);
	FTDI::writeRegister(ftHandle, 0x49, 0x000DB0);
	FTDI::writeRegister(ftHandle, 0x4A, 0xC01001); //C0100E
	FTDI::writeRegister(ftHandle, 0x4B, 0x0004C0);
	FTDI::writeRegister(ftHandle, 0x4C, 0x000006);
	FTDI::writeRegister(ftHandle, 0x4D, 0x000000);
	FTDI::writeRegister(ftHandle, 0x4E, 0x000000);
	FTDI::writeRegister(ftHandle, 0x4F, 0x000000);
	FTDI::writeRegister(ftHandle, 0x50, 0x000000);
	FTDI::writeRegister(ftHandle, 0x51, 0x000000);
	FTDI::writeRegister(ftHandle, 0x52, 0x000000);
	FTDI::writeRegister(ftHandle, 0x53, 0x000000);
	FTDI::writeRegister(ftHandle, 0x54, 0x000000);
	FTDI::writeRegister(ftHandle, 0x55, 0x000000);
	FTDI::writeRegister(ftHandle, 0x56, 0x000000);
	FTDI::writeRegister(ftHandle, 0x57, 0x020000);
	FTDI::writeRegister(ftHandle, 0x58, 0x004000);
	FTDI::writeRegister(ftHandle, 0x59, 0x000000);
	FTDI::writeRegister(ftHandle, 0x5A, 0x000000);
	FTDI::writeRegister(ftHandle, 0x5B, 0x000000);
	FTDI::writeRegister(ftHandle, 0x5C, 0x020000);
	FTDI::writeRegister(ftHandle, 0x5D, 0x004000);
	FTDI::writeRegister(ftHandle, 0x5E, 0x000000);
	FTDI::writeRegister(ftHandle, 0x5F, 0x000000);
	FTDI::writeRegister(ftHandle, 0x60, 0x000000);
	FTDI::writeRegister(ftHandle, 0x61, 0x020000);
	FTDI::writeRegister(ftHandle, 0x62, 0x004000);
	FTDI::writeRegister(ftHandle, 0x63, 0x000000);
	FTDI::writeRegister(ftHandle, 0x64, 0x000000);
	FTDI::writeRegister(ftHandle, 0x65, 0x000000);
	FTDI::writeRegister(ftHandle, 0x66, 0x020000);
	FTDI::writeRegister(ftHandle, 0x67, 0x004000);
	FTDI::writeRegister(ftHandle, 0x68, 0x000000);
	FTDI::writeRegister(ftHandle, 0x69, 0x000000);
	FTDI::writeRegister(ftHandle, 0x6A, 0x000000);
	FTDI::writeRegister(ftHandle, 0x6B, 0x020000);
	FTDI::writeRegister(ftHandle, 0x6C, 0x004000);
	FTDI::writeRegister(ftHandle, 0x6D, 0x000000);
	FTDI::writeRegister(ftHandle, 0x6E, 0x000000);
	FTDI::writeRegister(ftHandle, 0x6F, 0x000000);
	FTDI::writeRegister(ftHandle, 0x70, 0x020000);
	FTDI::writeRegister(ftHandle, 0x71, 0x004000);
	FTDI::writeRegister(ftHandle, 0x72, 0x000000);
	FTDI::writeRegister(ftHandle, 0x73, 0x000000);
	FTDI::writeRegister(ftHandle, 0x74, 0x000000);
	FTDI::writeRegister(ftHandle, 0x75, 0x020000);
	FTDI::writeRegister(ftHandle, 0x76, 0x002000);
	FTDI::writeRegister(ftHandle, 0x77, 0x000000);
	FTDI::writeRegister(ftHandle, 0x78, 0x000000);
	FTDI::writeRegister(ftHandle, 0x79, 0x000000);
	FTDI::writeRegister(ftHandle, 0x7A, 0x020000);
	FTDI::writeRegister(ftHandle, 0x7B, 0x002000);
	FTDI::writeRegister(ftHandle, 0x7C, 0x000000);
	FTDI::writeRegister(ftHandle, 0x7D, 0x000000);
	FTDI::writeRegister(ftHandle, 0x7E, 0x000000);
	FTDI::writeRegister(ftHandle, 0x7F, 0x020000);
	FTDI::writeRegister(ftHandle, 0x80, 0x002000);
	FTDI::writeRegister(ftHandle, 0x81, 0x000000);
	FTDI::writeRegister(ftHandle, 0x82, 0x000000);
	FTDI::writeRegister(ftHandle, 0x83, 0x000000);
	FTDI::writeRegister(ftHandle, 0x84, 0x020000);
	FTDI::writeRegister(ftHandle, 0x85, 0x002000);
	FTDI::writeRegister(ftHandle, 0x86, 0x000000);
	FTDI::writeRegister(ftHandle, 0x87, 0x000000);
	FTDI::writeRegister(ftHandle, 0x88, 0x000000);
	FTDI::writeRegister(ftHandle, 0x89, 0x020000);
	FTDI::writeRegister(ftHandle, 0x8A, 0x002000);
	FTDI::writeRegister(ftHandle, 0x8B, 0x000000);
	FTDI::writeRegister(ftHandle, 0x8C, 0x000000);
	FTDI::writeRegister(ftHandle, 0x8D, 0x000000);
	FTDI::writeRegister(ftHandle, 0x8E, 0x020000);
	FTDI::writeRegister(ftHandle, 0x8F, 0x002000);
	FTDI::writeRegister(ftHandle, 0x90, 0x000000);
	FTDI::writeRegister(ftHandle, 0x91, 0x000000);
	FTDI::writeRegister(ftHandle, 0x92, 0x000000);
	FTDI::writeRegister(ftHandle, 0x93, 0x020000);
	FTDI::writeRegister(ftHandle, 0x94, 0x002000);
	FTDI::writeRegister(ftHandle, 0x95, 0x000000);
	FTDI::writeRegister(ftHandle, 0x96, 0x000000);
	FTDI::writeRegister(ftHandle, 0x97, 0x000000);
	FTDI::writeRegister(ftHandle, 0x01, 0x000000);
	FTDI::writeRegister(ftHandle, 0x00, 0x000002);
	FTDI::writeRegister(ftHandle, 0x00, 0x000040);


	std::cout << "Register configuration completed!" << std::endl;

}


void AFE::setLEDIntensities(FT_HANDLE& ftHandle, uint8 intensities[])
{
	FTDI::writeRegister(ftHandle, 0x01, 0x000001);

	// LED values
	FTDI::writeRegister(ftHandle, 0x20 + 9, intensities[0] & 0xFF);
	FTDI::writeRegister(ftHandle, 0x20 + 14, intensities[1] & 0xFF);
	FTDI::writeRegister(ftHandle, 0x20 + 19, intensities[2] & 0xFF);
	FTDI::writeRegister(ftHandle, 0x20 + 24, intensities[3] & 0xFF);
	FTDI::writeRegister(ftHandle, 0x20 + 29, intensities[4] & 0xFF);
	FTDI::writeRegister(ftHandle, 0x20 + 34, intensities[5] & 0xFF);
	FTDI::writeRegister(ftHandle, 0x20 + 39, intensities[6] & 0xFF);
	FTDI::writeRegister(ftHandle, 0x20 + 44, intensities[7] & 0xFF);

	FTDI::writeRegister(ftHandle, 0x01, 0x000000);

}

void AFE::startSampling(FT_HANDLE& ftHandle)
{
	uint16 bytesWritten;
	uint8 data[] = { 0x07, 1, 0x11 }; // Sampling rate = 50Hz - 0x11
	FTDI::I2CWrite(ftHandle, data, 2, &bytesWritten);


	FTDI::writeRegister(ftHandle, 0x00, 0x000040);
	FTDI::writeRegister(ftHandle, 0x1D, (0xC0 << 16) | (3200 & 0xFFFF));
}


void AFE::stopSampling(FT_HANDLE& ftHandle)
{
	FTDI::writeRegister(ftHandle, 0x1D, 0x000000);
	FTDI::writeRegister(ftHandle, 0x00, 0x000002);

	uint16 bytesWritten;
	uint8 data[] = {0x07 , 0};
	FTDI::I2CWrite(ftHandle, data, 2, &bytesWritten);

}