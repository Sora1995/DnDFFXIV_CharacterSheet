#ifndef JOBS_H
#define JOBS_H
#include <string>
#include <iostream>
using namespace std;

class jobs
{
public:
    jobs();

    int jobSelection;
    int confirmJob;
    string finalJob;

    int confirmation(int);

    void displayJobs();

    void viewList(int);

    void setJob(string);
    string getJob();

};

#endif // JOBS_H
