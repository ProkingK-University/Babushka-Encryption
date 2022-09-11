#include "GoldBabushka.h"

#include "OverflowException.h"
#include "UnderflowException.h"

GoldBabushka::GoldBabushka(const unsigned char* id, unsigned char xorValue) : Babushka(id), xorValue(xorValue) {}

void GoldBabushka::encrypt(unsigned char* data, int size)
{
    for (int i = 0; i < size; i++)
    {
        if ((data[i] ^ xorValue) > MAX_VALUE_INCLUSIVE)
        {
            throw OverflowException();
        }
        else if ((data[i] ^ xorValue) < MIN_VALUE_INCLUSIVE)
        {
            throw UnderflowException();
        }
        else
        {
            data[i] ^= xorValue;
        }
    }
}

void GoldBabushka::decrypt(unsigned char* data, int size)
{
    for (int i = 0; i < size; i++)
    {
        if ((data[i] ^ xorValue) > MAX_VALUE_INCLUSIVE)
        {
            throw OverflowException();
        }
        else if ((data[i] ^ xorValue) < MIN_VALUE_INCLUSIVE)
        {
            throw UnderflowException();
        }
        else
        {
            data[i] ^= xorValue;
        }
    }
}

// :)