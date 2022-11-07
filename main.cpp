#include <iostream>
#include "jobs.h"
#include "randomDice.h"
#include "races.h"
using namespace std;

int main() {
    races Race;
    jobs job;

    cout << "Hello! Welcome to the Dungons and Dragons x Final Fantasy XIV Character Creator! To get started, first pick your race from the list below:" << endl;
    Race.displayRaces();

    cout << "Great! Next, pick your job from the list below." << endl;
    job.displayJobs();

    cout << "Now, let's pick our name." << endl;
    //displayNameGenerator();

    cout << "Finally, let's roll the dice to see what your stats will be." << endl;
    randomDice();

    //AMB- add a summary print of the character's information in the future
}
