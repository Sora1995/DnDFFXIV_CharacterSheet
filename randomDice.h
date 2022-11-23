#ifndef RANDOMDICE_H
#define RANDOMDICE_H
#include <random>
#include <string>
#define MAX_STAT
using namespace std;


class randomDice
{
    enum {
        STR, DEX, INT, CON, WIS, CHA, MAX_STAT
    };
    struct Character {
        int level = 1;
        int stats[MAX_STAT];
    };

    struct Character myCharacter;
public:

    randomDice();
    void printStat();
    void roll_stat(int*);
};

#endif // RANDOMDICE_H
