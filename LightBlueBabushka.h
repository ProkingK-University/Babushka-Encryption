#ifndef LIGHT_BLUE_BABUSHKA_H
#define LIGHT_BLUE_BABUSHKA_H

#include "BlueBabushka.h"

class LightBlueBabushka : public BlueBabushka
{
public:
    LightBlueBabushka(const unsigned char* id, unsigned int amount);

    void encrypt(unsigned char* data, int size);
    void decrypt(unsigned char* data, int size);
};

#endif