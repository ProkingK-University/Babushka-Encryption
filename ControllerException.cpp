#include <iostream>

#include "ControllerException.h"

ControllerException::ControllerException(std::string customMessage)
{

}

ControllerException::ControllerException(BabushkaException& babushkaException, std::string customMessage)
{

}

void ControllerException::printMessage()
{

}