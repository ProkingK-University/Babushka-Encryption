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

}

ReturnStruct Controller::decrypt(const unsigned char* array, int size)
{

}

ReturnStruct Controller::expandArray(unsigned char* array, int currentSize, const unsigned char* id, int idSize)
{

}

ReturnStruct Controller::reduceArray(unsigned char* array, int currentSize, const unsigned char* expectedId, int idSize)
{

}

void Controller::printArray(unsigned char* array, int size)
{

}

Controller::~Controller()
{

}