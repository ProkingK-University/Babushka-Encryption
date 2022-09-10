#ifndef ROTATE_EXCEPTION_H
#define ROTATE_EXCEPTION_H

#include "BabushkaException.h"

class RotateException : public BabushkaException
{
public:
    void printMessage();
};

#endif