#ifndef GREEN_BABUSHKA_H
#define GREEN_BABUSHKA_H

#include "Babushka.h"

class GreenBabushka : public Babushka
{
protected:
    unsigned int displacement;
public:
    GreenBabushka(const unsigned char* id, unsigned int displacement);

    void encrypt(unsigned char* data, int size);
    void decrypt(unsigned char* data, int size);
};

#endif