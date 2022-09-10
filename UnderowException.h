#ifndef UNDERFLOW_EXCEPTION_H
#define UNDERFLOW_EXCEPTION_H

#include "BabushkaException.h"

class UnderflowException : public BabushkaException
{
public:
    void printMessage();
};

#endif