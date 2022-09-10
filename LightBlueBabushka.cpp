#include "LightBlueBabushka.h"

#include "OverflowException.h"
#include "UnderflowException.h"

LightBlueBabushka::LightBlueBabushka(const unsigned char* id, unsigned int amount) : BlueBabushka(id, amount) {}

void LightBlueBabushka::encrypt(unsigned char* data, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (data[i] + amount > MAX_VALUE_INCLUSIVE)
        {
            throw OverflowException();
        }
        else if (data[i] + amount < MIN_VALUE_INCLUSIVE)
        {
            throw UnderflowException();
        }
        else
        {
            data[i] += amount;
        }
    }
}

void LightBlueBabushka::decrypt(unsigned char* data, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (data[i] - amount > MAX_VALUE_INCLUSIVE)
        {
            throw OverflowException();
        }
        else if (data[i] - amount < MIN_VALUE_INCLUSIVE)
        {
            throw UnderflowException();
        }
        else
        {
            data[i] -= amount;
        }
    }
}

// :)