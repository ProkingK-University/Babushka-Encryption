#include <iostream>

#include "ControllerException.h"

ControllerException::ControllerException(std::string customMessage) : customMessage(customMessage)
{
    hasBabushka = false;
}

ControllerException::ControllerException(BabushkaException& babushkaException, std::string customMessage) : babushkaException(&babushkaException), customMessage(customMessage)
{
    hasBabushka = true;
}

void ControllerException::printMessage()
{
    if (hasBabushka)
    {
        babushkaException->printMessage();
    }
    else
    {
        std::cout<< customMessage <<std::endl;
    }
}