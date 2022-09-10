#ifndef BABUSHKA_H
#define BABUSHKA_H

class Babushka
{
protected:
    const unsigned char* id;

    static const int ID_LENGTH;

    static const char MAX_VALUE_INCLUSIVE;
    static const char MAX_VALUE_INCLUSIVE;
public:
    Babushka(const unsigned char* id);

    const int getIdLength();
    const unsigned char* getID();

    virtual void encrypt(unsigned char* data, int size) = 0;
    virtual void decrypt(unsigned char* data, int size) = 0;

    ~Babushka();
};

#endif