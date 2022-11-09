#ifndef RACES_H
#define RACES_H
#include <iostream>

using namespace std;

class races{
private:
    string clanSelection; //clanSelection
    string raceString; //raceSelection as a string
    int raceSelection; //raceSelection

    int walkingSpeed;
    string raceAbilityScore; //ability score boose for race
    int raceASIncreaseAmount; //abililty score increase amount for raceAbilityScore

    string clanAbilityScore; //ability score boost for clan
    int clanASIncreaseAmount; //ability score increase amount for the clanAbilityscore

public:


    int increaseChoice; //increaseChoice (hyur race)
    int raceConfirm; //confirmation for selection of race/clan

    races();

    //getterSetters
    void setRace(string);
    string getRace();

    void setClan(string);
    string getClan();

    void setRaceAbilityScore(string);
    string getRaceAbilityScore();

    void setRaceASIncreaseAmount(int);
    int getRaceASIncreaseAmount();

    void setClanAbilityScore(string);
    string getClanAbilityScore();

    void setClanASIncreaseAmount(int);
    int getClanASIncreaseAmount();

    void setWalkingSpeed(int);
    int getWalkingSpeed();

    //other functions
    int raceConfirmation(string, string);

    void displayRaces();

    void listRaces(int);
};

#endif // RACES_H
