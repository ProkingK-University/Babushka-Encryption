#include "Babushka.h"

Babushka::Babushka(const unsigned char* id) : id(id) {}

const int Babushka::getIdLength() { return ID_LENGTH;}

const unsigned char* Babushka::getID() {return id;}

Babushka::~Babushka() {delete [] id;}