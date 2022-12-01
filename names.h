#ifndef NAMES_H
#define NAMES_H
#include <iostream>
using namespace std;

class names
{
public:
    names(); //constructor

    int displayNameGenerator();

    string getCharacterName();
    void setCharacterName(string, string);
    void setCharacterName(string);

    void randomName(string, string, string);
    string chosenName();
private:
    string name;
};

#endif // NAMES_H
