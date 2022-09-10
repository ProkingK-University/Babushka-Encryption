#ifndef BLUE_BABUSHKA_H
#define BLUE_BABUSHKA_H

#include "Babushka.h"

class BlueBabushka : public Babushka
{
protected:
    unsigned int amount;
public:
    BlueBabushka(const unsigned char* id, unsigned int amount);

    virtual void encrypt(unsigned char* data, int size) = 0;
    virtual void decrypt(unsigned char* data, int size) = 0;
};

#endif