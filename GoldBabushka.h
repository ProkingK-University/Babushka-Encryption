#ifndef GOLD_BABUSHKA_H
#define GOLD_BABUSHKA_H

#include "Babushka.h"

class GoldBabushka : public Babushka
{
protected:
    unsigned char xorValue;
public:
    GoldBabushka(const unsigned char* id, unsigned char xorValue);

    void encrypt(unsigned char* data, int size);
    void decrypt(unsigned char* data, int size);
};

#endif