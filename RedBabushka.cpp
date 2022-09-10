#include "RedBabushka.h"

#include "RotateException.h"

RedBabushka::RedBabushka(const unsigned char* id, unsigned int rotationAmount) : Babushka(id), rotationAmount(rotationAmount) {}

void RedBabushka::encrypt(unsigned char* data, int size)
{
    if (rotationAmount >= size)
    {
        throw RotateException();
    }
    else
    {
        unsigned char* arr = new unsigned char[rotationAmount];

        for (int i = 0; i < rotationAmount; i++)
        {
            arr[i] = data[i + (size-rotationAmount)];
        }

        for (int i = size-rotationAmount-1; i >= 0; i--)
        {
            data[i+rotationAmount] = data[i];
        }

        for (int i = 0; i < rotationAmount; i++)
        {
            data[i] = arr[i];
        }
    }
}

void RedBabushka::decrypt(unsigned char* data, int size)
{
    if (rotationAmount >= size)
    {
        throw RotateException();
    }
    else
    {
        unsigned char* arr = new unsigned char[rotationAmount];

        for (int i = 0; i < rotationAmount; i++)
        {
            arr[i] = data[i];
        }

        for (int i = rotationAmount; i < size; i++)
        {
            data[i-rotationAmount] = data[i];
        }
        
        for (int i = 0; i < rotationAmount; i++)
        {
            data[i+(size-rotationAmount)] = arr[i];
        }
    }
}