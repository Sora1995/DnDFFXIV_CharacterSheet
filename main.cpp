#include <QString>
#include "jobs.h"
#include "randomDice.h"
#include "races.h"
#include "names.h"
using namespace std;


int main() {
    races Race;
    jobs job;
    names name;
    string characterName;
    string characterSex;
    randomDice diceRolls;

    cout << "Hello! Welcome to the Dungons and Dragons x Final Fantasy XIV Character Creator! To get started, first pick your race from the list below:" << endl;
    Race.displayRaces();
    string characterRace = Race.getRace(); //set local variables
    string characterClan = Race.getClan(); //set local variables

    cout << "Great! Next, pick your job from the list below." << endl;
    job.displayJobs();

    cin.ignore();
    cout << "Is your character male or female?" << endl << "M for male " << endl << "F for Female" << endl;
    cin >> characterSex;

    while(characterSex != "F" && characterSex != "M" ){
        cout << "Invalid selection, try again..." << endl;
        cin >> characterSex;
    }


    cout << "Now, let's pick our name." << endl;
    int nameChoice = name.displayNameGenerator();

    if(nameChoice == 1){
        cout << "Enter the name of your character: ";
        cin >> characterName;
        name.setCharacterName(characterName);
    } else if(nameChoice == 2){
        cout << "Generating random name." << endl;
        characterName = name.randomName(characterRace, characterClan, characterSex);
        name.setCharacterName(characterName);
    } else {
        cout << "Invalid choice" << endl;
    }

    cout << "Finally, let's roll the dice to see what your stats will be." << endl;
    diceRolls.printStat();



    //AMB- 11/9 added a summary print of the character's information in the future
    cout << endl << "Here is your character: " << endl;
    cout << "Character name: " << name.getCharacterName() << endl;
    cout << "Character sex: " << characterSex << endl;
    cout << "Race: " << Race.getRace() << endl;
    cout << "Job: " << job.getJob() << endl;
    cout << "Level: 1" << endl;
    cout << endl;

    cout << "Character stats: " << endl << endl;
    cout << endl << "Strength: ";
    if(Race.getClanAbilityScore() == "Strength"){
            cout << " +" << Race.getClanASIncreaseAmount() << " (clan)";
    }
    if(Race.getRaceAbilityScore() == "Strength"){
        cout << " +" << Race.getRaceASIncreaseAmount() << " (race)";
    }

    cout << endl << "Dexterity: ";
    if(Race.getClanAbilityScore() == "Dexterity"){
            cout << " +" << Race.getClanASIncreaseAmount() << " (clan)";
    }
    if(Race.getRaceAbilityScore() == "Dexterity"){
        cout << " +" << Race.getRaceASIncreaseAmount() << " (race)";
    }

    cout << endl << "Constitution: ";
    if(Race.getClanAbilityScore() == "Constitution"){
            cout << " +" << Race.getClanASIncreaseAmount() << " (clan)";
    }
    if(Race.getRaceAbilityScore() == "Constitution"){
        cout << " +" << Race.getRaceASIncreaseAmount() << " (race)";
    }

    cout << endl << "Intelligence: ";
    if(Race.getClanAbilityScore() == "Intelligence"){
            cout << " +" << Race.getClanASIncreaseAmount() << " (clan)";
    }
    if(Race.getRaceAbilityScore() == "Intelligence"){
        cout << " +" << Race.getRaceASIncreaseAmount() << " (race)";
    }

    cout << endl << "Wisdom: ";
    if(Race.getClanAbilityScore() == "Wisdom"){
            cout << " +" << Race.getClanASIncreaseAmount() << " (clan)";
    }
    if(Race.getRaceAbilityScore() == "Wisdom"){
        cout << " +" << Race.getRaceASIncreaseAmount() << " (race)";
    }

    cout << endl << "Charisma: ";
    if(Race.getClanAbilityScore() == "Charisma"){
            cout << " +" << Race.getClanASIncreaseAmount() << " (clan)";
    }
    if(Race.getRaceAbilityScore() == "Charisma"){
        cout << " +" << Race.getRaceASIncreaseAmount() << " (race)";
    }

    cout << endl << "Profiency bonus: " << endl;

    cout << endl << "Saving throw: " << endl;
    cout << "Strength: " << endl;
    cout << "Dexterity: " << endl;
    cout << "Constitution: " << endl;
    cout << "Intelligence: " << endl;
    cout << "Wisdom: " << endl;
    cout << "Charisma: " << endl;

    cout << endl << "Spells" << endl;
    //list spells here

    cout << endl << "Skills: " << endl;
    //list skills here

    cout << endl << "Armor class: " << endl;
    cout << endl << "Initiative: " << endl;
    cout << endl << "Speed: " << Race.getWalkingSpeed() << "ft " << endl;

    cout << endl << "Equipment: " << endl;
    //list equipment here

}


