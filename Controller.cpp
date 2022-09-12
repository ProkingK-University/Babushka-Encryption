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

    std::string line;
    std::string text;
    std::string darkBlueId;
    std::string db;
    std::string lightBlueId;
    std::string lb;
    std::string goldId;
    std::string g;
    std::string greenId;
    std::string gr;
    std::string redId;
    std::string r;
    std::string yellowId;
    
    std::ifstream file(filePath);

    if(!file.is_open())
    {
        std::cout<< "File failed to open" <<std::endl;
    }

    //Gets number of babushkas
    getline(file, line);

    std::stringstream ss(line);

    getline(ss, text, ':');
    getline(ss, text, ':');

    numBabushkas = stoi(text);

    babushkaArr = new Babushka*[numBabushkas];

    //Populates the babushka array
    while (getline(file, line))
    {
        std::stringstream ss(line);

        getline(ss, text, ':');

        if (text == "darkblue")
        {
            getline(ss, darkBlueId, ':');
            getline(ss, db, ':');

            unsigned char* t = new unsigned char[10];

            for (int i = 0; i < 10; i++)
            {
                t[i] = darkBlueId[i];
            } 

            babushkaArr[i] = new DarkBlueBabushka(t, stoi(db));
        }
        else if (text == "lightblue")
        {
            getline(ss, lightBlueId, ':');
            getline(ss, lb, ':');

            unsigned char* t = new unsigned char[10];

            for (int i = 0; i < 10; i++)
            {
                t[i] = lightBlueId[i];
            }    

            babushkaArr[i] = new LightBlueBabushka(t, stoi(lb));
        }
        else if (text == "gold")
        {
            getline(ss, goldId, ':');
            getline(ss, g, ':');

            unsigned char* t = new unsigned char[10];

            for (int i = 0; i < 10; i++)
            {
                t[i] = goldId[i];
            }    

            babushkaArr[i] = new GoldBabushka(t, *g.c_str());
        }
        else if (text == "green")
        {
            getline(ss, greenId, ':');
            getline(ss, gr, ':');

            unsigned char* t = new unsigned char[10];

            for (int i = 0; i < 10; i++)
            {
                t[i] = greenId[i];
            }

            babushkaArr[i] = new GreenBabushka(t, stoi(gr));
        }
        else if (text == "red")
        {
            getline(ss, redId, ':');
            getline(ss, r, ':');

            unsigned char* t = new unsigned char[10];

            for (int i = 0; i < 10; i++)
            {
                t[i] = redId[i];
            }    

            babushkaArr[i] = new RedBabushka(t, stoi(r));
        }
        else
        {
            getline(ss, yellowId, ':');

            unsigned char* t = new unsigned char[10];

            for (int i = 0; i < 10; i++)
            {
                t[i] = yellowId[i];
            }

            babushkaArr[i] = new YellowBabushka(t);
        }

        i++;
    }
}

//Encrypts the message
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

        rs.arraySize = size;
        rs.returnArray = arr;

        for (int i = 0; i < numBabushkas; i++)
        {
            rs = expandArray(rs.returnArray, rs.arraySize, babushkaArr[i]->getID(), babushkaArr[i]->getIdLength());

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

//Decrypts the messages
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

        rs.arraySize = size;
        rs.returnArray = arr;

        for (int i = numBabushkas-1; i >= 0; i--)
        {
            babushkaArr[i]->decrypt(rs.returnArray, rs.arraySize);
            
            rs = reduceArray(rs.returnArray, rs.arraySize, babushkaArr[i]->getID(), babushkaArr[i]->getIdLength()); 

            printArray(rs.returnArray, rs.arraySize);
        }
        
        return rs;
    }
    catch(BabushkaException& b)
    {
        throw ControllerException(b, "decrypt exception");
    }
}

//Adds ID to the front and back
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

//Removes ID from the ends
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
                for (int j = 0; j < size; j++)
                {
                    arr[j] = array[j+idSize];
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
            std::cout<< "[" <<array[i] << ",";
        }
        else if ( i == size-1)
        {
            std::cout<< array[i] << "]" <<std::endl;
        }
        else
        {
            std::cout<<array[i] << ",";
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