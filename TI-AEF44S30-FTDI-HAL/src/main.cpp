// main.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <thread>
#include <chrono>
#include <sstream>
#include <bitset>

// Include files
#include "errorhandler.h";
#include "ftdi.h";
#include "afe.h"

// include FTDI libraries
#include "ftd2xx.h"
#include "LibFT4222.h"


// Global variables
FT_HANDLE ftHandle = NULL;
uint16 bytesTransferred = 0;


int main()
{

	using namespace std::this_thread; // sleep_for, sleep_until
	using namespace std::chrono; // nanoseconds, system_clock, seconds


	ErrorHandler::logError("Example Error Logger");


	// Open and initialze the USB dongle (FTDI Chip)
	FTDI::openDevice(ftHandle);
	FTDI::initFTAsI2CMaster(ftHandle);

	AFE::configureSensor(ftHandle);

	uint8 ledIntensities[] = { 255, 255, 255, 255, 255, 255, 255, 255 };
	AFE::setLEDIntensities(ftHandle, ledIntensities);

	// Start Sampling
	
	sleep_for(seconds(2));
	std::cout << "Starting..." << std::endl;
	AFE::startSampling(ftHandle);


	sleep_for(seconds(7));

	std::cout << "Ending..." << std::endl;
	AFE::stopSampling(ftHandle);


	// Close USB
	FTDI::closeDevice(ftHandle);
	std::cin.get();
}

