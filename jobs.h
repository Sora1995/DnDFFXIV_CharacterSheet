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

    int confirmation(int);

    void displayJobs();

    void viewList(int);


};

#endif // JOBS_H
