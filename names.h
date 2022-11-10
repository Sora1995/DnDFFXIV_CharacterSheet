#ifndef NAMES_H
#define NAMES_H
#include <iostream>
using namespace std;

class names
{
public:
    names(); //constructor

    void displayNameGenerator();

    string getCharacterName();
    void setCharacterName(string);

    string randomName();
private:
    string name;
};

#endif // NAMES_H
