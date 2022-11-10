#include "names.h"
#include <iostream>
using namespace std;

//default constructor
names::names()
{
    string name = " ";
}

//AMB 11/9- added displaying name function, user chooses from inputting their own name or choosing a random name based off their clan/race
void names::displayNameGenerator(){
    int nameChoice = 0;
    cout << "Choose an option below: " << endl;
    cout << "1. Input your own name." << endl;
    cout << "2. Random name - based off race and clan." << endl;

    cin >> nameChoice;

    while(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Invalid input, please use digits." << endl;;
        cin >> nameChoice;
    }

    while(nameChoice < 1 || nameChoice > 2){
        cout <<"Invalid choice, please try again" << endl;
        cin >> nameChoice;
    }

    if(nameChoice == 1){
        cout << "Enter the name of your character: ";
        cin >> name;
    } else if(nameChoice == 2){
        cout << "Generating random name." << endl;
        name = randomName();
    } else {
        cout << "Invalid choice" << endl;
    }

}

//needs to have randomization added based on clan/race.
string names::randomName(){
    //temperary randonName string to let user know that this will be a randomized name
    string randomName = "this will be a random name";

    return randomName;
}

//returns character's name, whether random or inputted by user
string names::getCharacterName(){
    return name;
}


//sets character's name.
void names::setCharacterName(string selectedName){
    name = selectedName;
}
