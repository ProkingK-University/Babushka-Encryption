#include "DarkBlueBabushka.h"

#include "OverflowException.h"
#include "UnderflowException.h"

DarkBlueBabushka::DarkBlueBabushka(const unsigned char* id, unsigned int amount) : BlueBabushka(id, amount) {}

void DarkBlueBabushka::encrypt(unsigned char* data, int size)
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

void DarkBlueBabushka::decrypt(unsigned char* data, int size)
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

// :)