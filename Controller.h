#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>

#include "Babushka.h"
#include "ReturnStruct.h"

class Controller
{
private:
    Babushka** babushkaArr;
    int numBabushkas;

    ReturnStruct expandArray(unsigned char* array, int currentSize, const unsigned char* id, int idSize);
    ReturnStruct reduceArray(unsigned char* array, int currentSize, const unsigned char* expectedId, int idSize);
public:
    Controller(std::string filePath);

    ReturnStruct encrypt(const unsigned char* array, int size);
    ReturnStruct decrypt(const unsigned char* array, int size);

    void printArray(unsigned char* array, int size);

    ~Controller();
};

#endif
