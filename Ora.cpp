#include "Ora.h"

using namespace std;

Ora::Ora(int szamlalo)
{
    this->orgSzamlalo = szamlalo;
    this->szamlalo = szamlalo;
    sec = 0;
}

Ora::~Ora()
{
}

void Ora::changeSzamlalo(int szamlalo){
    orgSzamlalo = szamlalo;
    this->szamlalo = szamlalo;
}

void Ora::tick(){
    szamlalo--;
    if (szamlalo == 0){
        szamlalo = orgSzamlalo;
        sec++;
    }
}

