#ifndef RACES_H
#define RACES_H
#include <iostream>
using namespace std;

class races
{
public:
    int raceSelection;
    string clanSelection;
    int increaseChoice;

    races();

    int raceConfirmation();

    void displayRaces();

    void listRaces(int);
};

#endif // RACES_H
