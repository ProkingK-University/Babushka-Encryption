#include <fstream>
#include <sstream>
#include <string.h>

#include "Controller.h"

#include "DarkBlueBabushka.h"
#include "LightBlueBabushka.h"
#include "GoldBabushka.h"
#include "GreenBabushka.h"
#include "RedBabushka.h"
#include "YellowBabushka.h"

#include "ControllerException.h"

Controller::Controller(std::string filePath)
{
    int i = 0;

    std::string txt;
    std::string line;
    std::string text;

    std::stringstream ss(line);
    std::ifstream file(filePath);

    if(!file.is_open())
    {
        std::cout<< "File failed to open" <<std::endl;
    }

    getline(file, line);

    getline(ss, text, ':');
    getline(ss, text, ':');

    numBabushkas = stoi(text);

    babushkaArr = new Babushka*[numBabushkas];

    while (getline(file, line))
    {
        getline(ss, text, ':');

        if (text == "darkblue")
        {
            getline(ss, txt, ':');
            getline(ss, text, ':');

            unsigned char* t = (unsigned char*) txt.c_str();    

            babushkaArr[i] = new DarkBlueBabushka(t, stoi(text));
        }
        else if (text == "lightblue")
        {
            getline(ss, txt, ':');
            getline(ss, text, ':');

            unsigned char* t = (unsigned char*) txt.c_str();    

            babushkaArr[i] = new LightBlueBabushka(t, stoi(text));
        }
        else if (text == "gold")
        {
            getline(ss, txt, ':');
            getline(ss, text, ':');

            unsigned char* t = (unsigned char*) txt.c_str();    

            babushkaArr[i] = new GoldBabushka(t, *text.c_str());
        }
        else if (text == "green")
        {
            getline(ss, txt, ':');
            getline(ss, text, ':');

            unsigned char* t = (unsigned char*) txt.c_str();    

            babushkaArr[i] = new GreenBabushka(t, stoi(text));
        }
        else if (text == "red")
        {
            getline(ss, txt, ':');
            getline(ss, text, ':');

            unsigned char* t = (unsigned char*) txt.c_str();    

            babushkaArr[i] = new RedBabushka(t, stoi(text));
        }
        else if (text == "yellow")
        {
            getline(ss, text, ':');

            unsigned char* t = (unsigned char*) text.c_str();    

            babushkaArr[i] = new YellowBabushka(t);
        }

        i++;
    }
}

ReturnStruct Controller::encrypt(const unsigned char* array, int size)
{
    try
    {
        ReturnStruct rs;

        unsigned char* arr = new unsigned char[size];

        for (int i = 0; i < size; i++)
        {
            arr[i] = array[i];
        }

        printArray(arr, size);

        for (int i = 0; i < numBabushkas; i++)
        {
            rs = expandArray(arr, size, babushkaArr[i]->getID(), babushkaArr[i]->getIdLength());

            babushkaArr[i]->encrypt(rs.returnArray, rs.arraySize);

            printArray(rs.returnArray, rs.arraySize);
        }
        
        return rs;
    }
    catch(BabushkaException& b)
    {
        throw ControllerException(b, "encrypt exception");
    }
}

ReturnStruct Controller::decrypt(const unsigned char* array, int size)
{
    try
    {
        ReturnStruct rs;

        unsigned char* arr = new unsigned char[size];

        for (int i = 0; i < size; i++)
        {
            arr[i] = array[i];
        }

        printArray(arr, size);

        for (int i = 0; i < numBabushkas; i++)
        {
            rs = reduceArray(arr, size, babushkaArr[i]->getID(), babushkaArr[i]->getIdLength());

            babushkaArr[i]->decrypt(rs.returnArray, rs.arraySize);

            printArray(rs.returnArray, rs.arraySize);
        }
        
        return rs;
    }
    catch(BabushkaException& b)
    {
        throw ControllerException(b, "decrypt exception");
    }
}

ReturnStruct Controller::expandArray(unsigned char* array, int currentSize, const unsigned char* id, int idSize)
{
    int j = 0;

    unsigned char* arr = new unsigned char[(2*idSize)+currentSize];

    for (int i = 0; i < idSize; i++)
    {
        arr[i] = id[i];
    }

    for (int i = idSize; i < idSize+currentSize; i++)
    {
        arr[i] = array[j];
        j++;
    }

    j = 0;

    for (int i = idSize+currentSize; i < (2*idSize)+currentSize; i++)
    {
        arr[i] = id[j];
        j++;
    }

    delete [] array;

    ReturnStruct rs;
    rs.arraySize = (2*idSize)+currentSize;
    rs.returnArray = arr;

    return rs;
}

ReturnStruct Controller::reduceArray(unsigned char* array, int currentSize, const unsigned char* expectedId, int idSize)
{
    int size = currentSize-(2*idSize);

    if(size < 0)
    {
        throw ControllerException("size exception");
    }
    else
    {
        unsigned char* arr = new unsigned char[size];

        for (int i = 0; i < idSize; i++)
        {
            if (array[i] != expectedId[i] || array[i+idSize+size] != expectedId[i])
            {
                throw ControllerException("id mismatch exception");
            }
            else
            {
                for (int i = 0; i < size; i++)
                {
                    arr[i] = array[i+idSize];
                }
            }
        }

        delete [] array;

        ReturnStruct rs;
        rs.arraySize = size;
        rs.returnArray = arr;

        return rs;
    }
}

void Controller::printArray(unsigned char* array, int size)
{
    for (int i = 0; i < size; i++)
    {
        if(i == 0)
        {
            std::cout<< "[" <<array[i]-48 << ",";
        }
        else if ( i == size-1)
        {
            std::cout<< array[i]-48 << "]" <<std::endl;
        }
        else
        {
            std::cout<<array[i]-48 << ",";
        }
    }
}

Controller::~Controller()
{
    for (int i = 0; i < numBabushkas; i++)
    {
        delete babushkaArr[i];
        babushkaArr[i] = NULL;
    }

    delete [] babushkaArr;
    babushkaArr = NULL;
}