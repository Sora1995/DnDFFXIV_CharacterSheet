#include "jobs.h"


jobs::jobs()
{
    jobSelection = -1;
    finalJob = "-";
    confirmJob = -1;
}

void jobs::setJob(string chosenJob){
    finalJob = chosenJob;
}

string jobs::getJob(){
    return finalJob;
}

void jobs::displayJobs() {
    cout << "Please select a job from the list below: " << endl;
    cout << "1. Astrologian" << endl;
    cout << "2. Black Mage" << endl;
    cout << "3. Dancer" << endl;
    cout << "4. Gunbreaker" << endl;
    cout << "5. Reaper" << endl;

    cin >> jobSelection;

    //checks to see if input is the right type
    while(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Invalid input, please use digits." << endl;;
        cin >> jobSelection;
    }
    //checks to see if input is in range
    while(jobSelection < 1 || jobSelection > 5) {
        cout << "Invalid selection, please try again." << endl;
        cin >> jobSelection;
    }

    viewList(jobSelection);
}

void jobs::viewList(int job) {
    if(job == 1){
        cout << "You have chosen Astrologian. A brief summary: A spellcaster who uses tarot cards and draws power from the stars. Astrologians are proficient in Wisdom and Charisma. \nIs this what you want? Type 1 for yes or 2 for no." << endl;;
        confirmJob = confirmation(jobSelection);
        switch(confirmJob){
        case 1:
            cout << "Your job is Astrologian." << endl;
            finalJob = "Astrologian";
            //ARE - Need the logic to set this as the correct job
            break;
        case 2:
            cout << "Returning to the list..." << endl;
            displayJobs();
            break;

        default :
            cout << "Invalid selection" << endl;
            break;
        }
    } else if(job == 2){
        cout << "You have chosen Black Mage. A brief summary: A mage who calls upon the power of the void to empower their spells. Black Mages are proficient in Inteligence and Wisdom. \nIs this what you want? Type 1 for yes or 2 for no." << endl;
        confirmJob = confirmation(jobSelection);
        switch(confirmJob){
        case 1:
            cout << "Your job is Black Mage." << endl;
            finalJob = "Black Mage";
             //ARE - Need the logic to set this as the correct job
            break;
        case 2:
            cout << "Returning to the list..." << endl;
            displayJobs();
            break;
        default :
            cout << "Invalid selection" << endl;
            break;
        }
    } else if (job == 3){
        cout << "You have chosen Dancer. A brief summary: A supportive fighter who uses both magic and martial arts to control the battle field. Dancers are proficient in Dexterity and Charisma. \nIs this what you want? Type 1 for yes or 2 for no." << endl;
        confirmJob = confirmation(jobSelection);
        switch(confirmJob){
        case 1:
            cout << "Your job is Dancer." << endl;
            finalJob = "Dancer";
             //ARE - Need the logic to set this as the correct job
            break;
        case 2:
            cout << "Returning to the list..." << endl;
            displayJobs();
            break;
        default:
            cout << "Invalid selection" << endl;
            break;
        }
    } else if(job == 4){
        cout << "You have chosen Gunbreaker. A brief summary: A bodyguard who augments their weaponry with manatriggers to deliver powerful attacks.Gunbreakers are proficient in Strength and Dexterity. \nIs this what you want? Type 1 for yes or 2 for no." << endl;
        confirmJob = confirmation(jobSelection);
        switch(confirmJob){
        case 1:
            cout << "Your job is Gunbreaker." << endl;
            finalJob = "Gunbreaker";
             //ARE - Need the logic to set this as the correct job
            break;
        case 2:
            cout << "Returning to the list..." << endl;
            displayJobs();
            break;
        default:
            cout << "Invalid selection" << endl;
            break;
        }

    } else if(job == 5){
        cout << "You have chosen Reaper. A brief summary: A fighter who calls on an ally from the void to aide them in battle. Reapers are proficient in Strength and Wisdom. \nIs this what you want? Type 1 for yes or 2 for no." << endl;
        confirmJob = confirmation(jobSelection);
        switch(confirmJob){
        case 1:
            cout << "Your job is Reaper." << endl;
            finalJob = "Reaper";
             //ARE - Need the logic to set this as the correct job
            break;
        case 2:
            cout << "Returning to the list..." << endl;
            displayJobs();
            break;
        default:
            cout << "Invalid selection" << endl;
            break;
        }
    } else{
        cout << "Invalid selection" << endl;
    }
}

//AMB 11/8- Added job confirmation
int jobs::confirmation(int jobSelect){
    int confirmJob = 3;
    string jobSelectString = " ";

    switch(jobSelect){
    case 1: jobSelectString = "Astrologian"; break;
    case 2: jobSelectString = "Black Mage"; break;
    case 3: jobSelectString = "Dancer"; break;
    case 4: jobSelectString = "Gunbreaker"; break;
    case 5: jobSelectString = "Reaper"; break;
    }

    cout << "Confirm your selection of " << jobSelectString << " as your job." << endl;
    cout << "1. Yes I want to be a " << jobSelectString <<endl << "2. No, I want to reselect my job." << endl;
    cin >> confirmJob;

    //checks if the input is the correct input type
    while(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Invalid input, please use digits." << endl;
        cin >> confirmJob;
    }


    while(confirmJob < 1 || confirmJob > 2){
        cout << "Invalid selection, please try again.";
        cin >> confirmJob;
    }

    return confirmJob;
}
