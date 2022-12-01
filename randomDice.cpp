#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <randomDice.h>
#include <map>
#include <algorithm>

randomDice::randomDice() {

}

void randomDice::setStrStat(string strStat){ this->strStat = strStat;}
string randomDice::getStrStat() {return strStat;}

void randomDice::setDexStat(string dexStat){ this->dexStat = dexStat;}
string randomDice::getDexStat() {return dexStat;}

void randomDice::setIntStat(string intStat){ this->intStat = intStat;}
string randomDice::getIntStat() {return intStat;}

void randomDice::setConStat(string conStat) {this->conStat = conStat;}
string randomDice::getConStat() {return conStat;}

void randomDice::setWisStat(string wisStat) {this->wisStat = wisStat;}
string randomDice::getWisStat(){return wisStat;}

void randomDice::setChaStat(string chaStat){this->chaStat = chaStat;}
string randomDice::getChaStat(){return chaStat;}

void randomDice::printStat()
{
    cout << "Rolling dice" << endl;
    //int userInput;
    /* Declare stat variables */
    map<int, string> stats {  {1, "Str"}, {2, "Dex"}, {3, "Con"}, {4, "Int"}, {5, "Wis"}, {6, "Cha"} };

    /* Declare control variables */
    int numOfRolls = 6; //number of rolls for each stat
    vector<int> diceRollValues = {0, 0, 0, 0, 0, 0}; //vector to store each dice roll

    //choice variables
    vector<int> choices = {-1, -1, -1, -1, -1, -1};

    /* Seed the random number generator */
    srand((unsigned) time(NULL));

    /* roll stats */
    for(int i = 0; i < numOfRolls; i++){
       diceRollValues.at(i) = roll_stat();
    }

    cout << "First, let's print out the random dice rolls." << endl;
    for(unsigned int i = 0; i < diceRollValues.size(); i++){
        cout << "Roll " << i + 1 << ": " << diceRollValues.at(i) << ", ";
    }

    cout << "Now, let's pick where you want your stat allocated. You cannot adjust your stats once you accept, so be sure you pick the one you want!" << endl;

    int rollChoice = 0;
    for(unsigned int i = 0; i < diceRollValues.size(); i++){
        cout << "Pick where you want roll " << i + 1 << " (" << diceRollValues.at(i) << ") to go from the following list: " << endl;
        map<int, string>::iterator j;
        int c = 1;
        for(j = stats.begin(); j != stats.end(); j++){
            cout << c << ": " << j->second << endl;
            c++;
        }
        cin >> rollChoice;

        //checks to see if the choice is in the range, and it hasn't been chosen already
        while((rollChoice < 1 || rollChoice > 6) || (count(choices.begin(), choices.end(), rollChoice)) == true){
            cout << "Invalid choice, choose a number in range, or make sure you haven't already chosen it." << endl;
            cin >> rollChoice;
        }

        while(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Invalid input, please use digits." << endl;;
            cin >> rollChoice;
        }

        choices.at(i) = rollChoice;


        map<int, string>::iterator it = stats.find(rollChoice);
        if (it != stats.end()){
            it->second = to_string(diceRollValues.at(i));
            if(rollChoice == 1){
                setStrStat(it->second);
            } else if(rollChoice == 2){
                setDexStat(it->second);
            } else if(rollChoice == 3){
                setConStat(it->second);
            } else if(rollChoice == 4){
                setIntStat(it->second);
            } else if(rollChoice == 5){
                setWisStat(it->second);
            } else if(rollChoice == 6){
                setChaStat(it->second);
            } else {
                cout << "invalid Choice" << endl;
            }
        }



    }
}

/* Roll 4d6 and drop lowest */
int randomDice::roll_stat()
{
    int dice1, dice2, dice3, dice4, total;
    /* Roll 4d6 */
    dice1 = (rand() % 6 + 1);
    dice2 = (rand() % 6 + 1);
    dice3 = (rand() % 6 + 1);
    dice4 = (rand() % 6 + 1);
    /* Find lowest dice and add result of the other 3 */
    if ((dice1 < dice2) && (dice1 < dice3) && (dice1 < dice4))
    total = dice2 + dice3 + dice4;
    else if ((dice2 < dice1) && (dice2 < dice3) && (dice2 < dice4))
    total = dice1 + dice3 + dice4;
    else if ((dice3 < dice1) && (dice3 < dice2) && (dice3 < dice4))
    total = dice1 + dice2 + dice4;
    else
    total = dice1 + dice2 + dice3;
    /* assign total value to the memory location we were given */
    return total;
}
