#ifndef OVERFLOW_EXCEPTION_H
#define OVERFLOW_EXCEPTION_H

#include "BabushkaException.h"

class OverflowException : public BabushkaException
{
public:
    void printMessage();
};

#endif