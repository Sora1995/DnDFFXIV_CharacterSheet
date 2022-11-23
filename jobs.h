#ifndef JOBS_H
#define JOBS_H
#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class jobs
{
public:
    jobs();

    int jobSelection;
    int confirmJob;
    string finalJob;
    string hitDice;
    int hitPoints;
    string savingThrows1;
    string savingThrows2;
    int conPoints;
    string skills;
    string startingEquipment;
    string proficiencyBonus;



    int confirmation(int);

    void displayJobs();

    void viewList(int);

    void setJob(string);
    string getJob();

    void setHitDice(string);
    string getHitDice();

    void setHitPoints(int);
    int getHitPoints();

    void setSavingThrows(string, string);
    string getSavingThrows();

    void setSkills(string string);
    string getSkills();

    void setConPoints(int);
    int getConPoints();

    string getStartingEquipment();

    string astEquipmentChoices();
    string blackMageEquipmentChoices();
    string dancerEquipmentChoices();
    string gunbreakerEquipmentChoices();
    string reaperEquipmentChoices();

    string getProfiencyBonus();

    string astSkills();
    string blmSkills();
    string dncSkills();
    string gnbSkills();
    string rprSkills();


};

#endif // JOBS_H
