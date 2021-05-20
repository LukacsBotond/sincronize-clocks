#ifndef Ora_H
#define Ora_H

class Ora
{
private:
    int orgSzamlalo; 
    int szamlalo;
    int sec;
public:
    Ora(int szamlalo);
    ~Ora();
    void tick();
    int getTime();
    void changeSzamlalo(int szamlalo);
};
#endif