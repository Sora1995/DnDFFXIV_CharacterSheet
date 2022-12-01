#ifndef RANDOMDICE_H
#define RANDOMDICE_H
#include <random>
#include <string>
#define MAX_STAT
using namespace std;


class randomDice
{
public:

    string strStat;
    string dexStat;
    string intStat;
    string conStat;
    string wisStat;
    string chaStat;

    void setStrStat(string);
    string getStrStat();

    void setDexStat(string);
    string getDexStat();

    void setIntStat(string);
    string getIntStat();

    void setConStat(string);
    string getConStat();

    void setWisStat(string);
    string getWisStat();

    void setChaStat(string);
    string getChaStat();

    randomDice();
    void printStat();
    int roll_stat();
};

#endif // RANDOMDICE_H
