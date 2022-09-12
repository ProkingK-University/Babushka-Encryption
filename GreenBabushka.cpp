#include "GreenBabushka.h"

#include "DisplacementException.h"

GreenBabushka::GreenBabushka(const unsigned char* id, unsigned int displacement) : Babushka(id), displacement(displacement) {}

void GreenBabushka::encrypt(unsigned char* data, int size)
{
    if (displacement > size-2)
    {
        throw DisplacementException();
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            if (i+displacement < size-1)
            {
                unsigned char temp = data[i];
                data[i] = data[i+displacement+1];
                data[i+displacement+1] = temp;

                i += displacement+1;
            }
        }
    }
}

void GreenBabushka::decrypt(unsigned char* data, int size)
{
    if (displacement > size-2)
    {
        throw DisplacementException();
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            if (i+displacement < size-1)
            {
                unsigned char temp = data[i];
                data[i] = data[i+displacement+1];
                data[i+displacement+1] = temp;

                i += displacement+1;
            }
        }
    }
}

// :)