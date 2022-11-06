#include <iostream>
#include "jobs.h"
#include "randomDice.h"
using namespace std;

void displayJobs();

int main() {
    cout << "Hello! Welcome to the Dungons and Dragons x Final Fantasy XIV Character Creator! To get started, first pick your race from the list below:"
            " \n1. Hyur \n2. Miqo'te \n3. Au ra \n4. Lalafell \n5. Viera \n" << endl; // THIS ENTIRE LINE IS TEMPORARY UNTIL THE RACE CPP AND HEADER ARE CREATED. PLEASE DELETE WHEN THEY ARE DONE.
    displayRace();

    cout << "Great! Next, pick your job from the list below." << endl;
    displayJobs();

    cout << "Now, let's pick our name." << endl;
    displayNameGenerator();

    cout << "Finally, let's roll the dice to see what your stats will be." << endl;
    randomDice();
}
