#ifndef DISPLACEMENT_EXCEPTION_H
#define DISPLACEMENT_EXCEPTION_H

#include "BabushkaException.h"

class DisplacementException : public BabushkaException
{
public:
    void printMessage();
};

#endif