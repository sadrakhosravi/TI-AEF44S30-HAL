#pragma once

#include <string>
#include <iostream>

class ErrorHandler {
public:
	static void logError(std::string message);
	static void logErrorAndExit(std::string message);


};