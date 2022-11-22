#ifndef RANDOMDICE_H
#define RANDOMDICE_H
#include <random>
#include <string>
#define MAX_STAT
using namespace std;


class randomDice
{
    enum {
        STR, DEX, INT, CON, WIS, CHA, LEVEL, MAX_STAT
    };
    struct Character {
        int level = 1;
        int jobs;
        int HP;
        int bonus[8];
        int stats[MAX_STAT];
    };

    struct Character myCharacter;
public:

    randomDice();
    int printStat();
    int roll_hp(int);
    void get_bonus(int*, int);
    void roll_stat(int*);
};

#endif // RANDOMDICE_H
