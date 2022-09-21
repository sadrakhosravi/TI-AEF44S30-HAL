
#include "errorhandler.h"

void ErrorHandler::logError(std::string message)
{
	std::cout << "Error: " << message << std::endl;
}

void ErrorHandler::logErrorAndExit(std::string message)
{
	ErrorHandler::logError(message);
	exit(1);
}