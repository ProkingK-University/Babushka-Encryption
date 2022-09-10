#ifndef RED_BABUSHKA_H
#define RED_BABUSHKA_H

#include "Babushka.h"

class RedBabushka : public Babushka
{
protected:
    unsigned int rotationAmount;
public:
    RedBabushka(const unsigned char* id, unsigned int rotationAmount);

    void encrypt(unsigned char* data, int size);
    void decrypt(unsigned char* data, int size);
};

#endif