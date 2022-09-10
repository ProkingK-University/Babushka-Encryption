#include "YellowBabushka.h"

YellowBabushka::YellowBabushka(const unsigned char* id) : Babushka(id) {}

void YellowBabushka::encrypt(unsigned char* data, int size)
{
    int start = 0;
    int end = size-1;

    while (start < end)
    {
        unsigned char temp = data[start];
        data[start] = data[end];
        data[end] = temp;
        
        start++;
        end--;
    }
}

void YellowBabushka::decrypt(unsigned char* data, int size)
{
    int start = 0;
    int end = size-1;

    while (start < end)
    {
        unsigned char temp = data[start];
        data[start] = data[end];
        data[end] = temp;

        start++;
        end--;
    }
}