#pragma once

#include <ftdi.h>

class AFE {

public:
	// ----------------- Initial Sensor Configuration -----------------//

	/// <summary>
	/// Configures the sensors and writes the initial registers.
	/// </summary>
	static void configureSensor(FT_HANDLE& ftHandle);

	static void setLEDIntensities(FT_HANDLE& ftHandle, uint8 intensities[]);


	// Start and Stop functions
	static void startSampling(FT_HANDLE& ftHandle);
	static void stopSampling(FT_HANDLE& ftHandle);


};