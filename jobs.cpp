#include "jobs.h"


jobs::jobs()
{
    jobSelection = -1;
}

void jobs::displayJobs() {
    cout << "Please select a job from the list below: " << endl;
    cout << "1. Astrologian" << endl;
    cout << "2. Black Mage" << endl;
    cout << "3. Dancer" << endl;
    cout << "4. Gunbreaker" << endl;
    cout << "5. Reaper" << endl;

    cin >> jobSelection;
    while(jobSelection < 1 || jobSelection > 5) {
        cout << "Invalid selection, please try again." << endl;
        cin >> jobSelection;
    }
}

void jobs::viewList(int job) {
    switch(job) {
    case 1:
        cout << "You have chosen Astrologian. A brief summary: A spellcaster who uses tarot cards and draws power from the stars. Astrologians are proficient in Wisdom and Charisma. \nIs this what you want? Type 1 for yes or 2 for no." << endl;;
        switch(confirmation()){
        case 1:
            cout << "Your job is Astrologian." << endl;
            //ARE - Need the logic to set this as the correct job
            break;
        case 2:
            cout << "Returning to the list..." << endl;
            break;

        default :
            cout << "Invalid selection" << endl;
            break;
        }
        break;

    case 2:
        cout << "You have chosen Black Mage. A brief summary: A mage who calls upon the power of the void to empower their spells. Black Mages are proficient in Inteligence and Wisdom. \nIs this what you want? Type 1 for yes or 2 for no." << endl;
        switch(confirmation()){
        case 1:
            cout << "Your job is Black Mage." << endl;
             //ARE - Need the logic to set this as the correct job
            break;
        case 2:
            cout << "Returning to the list..." << endl;
            break;
        default :
            cout << "Invalid selection" << endl;
            break;
        }
        break;
    case 3:
        cout << "You have chosen Dancer. A brief summary: A supportive fighter who uses both magic and martial arts to control the battle field. Dancers are proficient in Dexterity and Charisma. \nIs this what you want? Type 1 for yes or 2 for no." << endl;
        switch(confirmation()){
        case 1:
            cout << "Your job is Dancer." << endl;
             //ARE - Need the logic to set this as the correct job
            break;
        case 2:
            cout << "Returning to the list..." << endl;
            break;
        default:
            cout << "Invalid selection" << endl;
            break;
        }
        break;
    case 4:
        cout << "You have chosen Gunbreaker. A brief summary: A bodyguard who augments their weaponry with manatriggers to deliver powerful attacks.Gunbreakers are proficient in Strength and Dexterity. \nIs this what you want? Type 1 for yes or 2 for no." << endl;
        switch(confirmation()){
        case 1:
            cout << "Your job is Gunbreaker." << endl;
             //ARE - Need the logic to set this as the correct job
            break;
        case 2:
            cout << "Returning to the list..." << endl;
            break;
        default:
            cout << "Invalid selection" << endl;
            break;
        }
        break;
    case 5:
        cout << "You have chosen Reaper. A brief summary: A fighter who calls on an ally from the void to aide them in battle. Reapers are proficient in Strength and Wisdom. \nIs this what you want? Type 1 for yes or 2 for no." << endl;
        switch(confirmation()){
        case 1:
            cout << "Your job is Reaper." << endl;
             //ARE - Need the logic to set this as the correct job
            break;
        case 2:
            cout << "Returning to the list..." << endl;
            break;
        default:
            cout << "Invalid selection" << endl;
            break;
        }
        break;

    default :
        cout << "Invalid selection" << endl;
        break;
    }
}
