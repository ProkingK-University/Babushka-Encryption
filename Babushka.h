#ifndef BABUSHKA_H
#define BABUSHKA_H

class Babushka
{
protected:
    const unsigned char* id;

    static const int ID_LENGTH = 10;

    static const char MAX_VALUE_INCLUSIVE = 126;
    static const char MIN_VALUE_INCLUSIVE = 32;
public:
    Babushka(const unsigned char* id);

    const int getIdLength();
    const unsigned char* getID();

    virtual void encrypt(unsigned char* data, int size) = 0;
    virtual void decrypt(unsigned char* data, int size) = 0;

    virtual ~Babushka();
};

#endif