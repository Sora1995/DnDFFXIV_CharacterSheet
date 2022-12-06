#include "jobs.h"
#include <limits>
#include <algorithm>
#include <exception>


jobs::jobs()
{
    jobSelection = -1;
    finalJob = "N/A";
    confirmJob = -1;
    hitDice = "N/A";
    hitPoints = 0;
    savingThrows1 = "N/A";
    savingThrows2 = "N/A";
    conPoints = 0;
    skills = "N/A";
    startingEquipment = "N/A";
    proficiencyBonus = "N/A";
    spells = "N/A";
    cantrips = "N/A";
    cardDraw = "N/A";
}


void jobs::setJob(string chosenJob){finalJob = chosenJob;}
string jobs::getJob(){return finalJob;}

void jobs::setSavingThrows(string savingThrow1, string savingThrow2){
    this->savingThrows1 = savingThrow1;
    this->savingThrows2 = savingThrow2;
}

string jobs::getSavingThrows(){
    return savingThrows1 + ", " + savingThrows2;
}

void jobs::setHitDice(string hitDice){ this->hitDice = hitDice;}
string jobs::getHitDice(){ return hitDice;}

void jobs::setHitPoints(int hitPoints) { this->hitPoints = hitPoints;}
int jobs::getHitPoints(){int updatedHitPoints = hitPoints + conPoints; return updatedHitPoints;}

void jobs::setConPoints(int conPoints){this->conPoints = conPoints;}
int jobs::getConPoints(){return conPoints;}

string jobs::getStartingEquipment(){return startingEquipment;}

string jobs::getProfiencyBonus(){return proficiencyBonus;}

string jobs::getSkills(){return skills;}

void jobs::setCantrips(string cantrips){this->cantrips = cantrips;}
void jobs::setSpells(string spells){this->spells = spells;}
void jobs::setCardDraw(string cardDraw){this->cardDraw = cardDraw;}

void jobs::displayJobs() {
    cout << "Please select a job from the list below: " << endl;
    cout << "1. Astrologian" << endl;
    cout << "2. Black Mage" << endl;
    cout << "3. Dancer" << endl;
    cout << "4. Gunbreaker" << endl;
    cout << "5. Reaper" << endl;

    bool validInput = false;
    while(!validInput){
        try{
            cin >> jobSelection;

            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                throw "Please input a digit number";
            }
            if(jobSelection < 1 || jobSelection > 5){
                throw "Invalid range, please try again";
            }
            else{
                viewList(jobSelection);
                validInput = true;
            }
        } catch(const char *e){
            cin.clear();
            cout << e << endl;
            continue;
        }
    }


}

void jobs::viewList(int job) {
    if(job == 1){
        cout << "You have chosen Astrologian. A brief summary: A spellcaster who uses tarot cards and draws power from the stars. Astrologians are proficient in Wisdom and Charisma. \nIs this what you want? Type 1 for yes or 2 for no." << endl;;
        confirmJob = confirmation(jobSelection);
        if (confirmJob == 1){
            cout << "Your job is Astrologian." << endl;
            //AMB 11/22 - added confirmation stats
            finalJob = "Astrologian";
            hitDice = "1d8";
            setHitPoints(8);
            savingThrows1 = "WIS";
            savingThrows2 = "CHA";
            proficiencyBonus = "+2";

            startingEquipment = astEquipmentChoices();
            cout << "Your starting equipment is: " + startingEquipment << endl;

            skills = astSkills();
            cout << "Your skills are: " + skills << endl;

            //have user choose cantrips;
            astCantrips();

        } else if (confirmJob == 2){
            cout << "Returning to the list..." << endl;
            displayJobs();

        } else {
            cout << "Invalid selection" << endl;

        }
    } else if(job == 2){
        cout << "You have chosen Black Mage. A brief summary: A mage who calls upon the power of the void to empower their spells. Black Mages are proficient in Inteligence and Wisdom. \nIs this what you want? Type 1 for yes or 2 for no." << endl;
        confirmJob = confirmation(jobSelection);
        if(confirmJob == 1){
            cout << "Your job is Black Mage." << endl;
            //AMB 11/22 - added confirmation stats
            finalJob = "Black Mage";
            setHitPoints(6);
            hitDice = "1d6";
            savingThrows1 = "INT";
            savingThrows2 = "WIS";
            proficiencyBonus = "+2";

            startingEquipment = blackMageEquipmentChoices();
            cout << "Your starting equipment is: " + startingEquipment << endl;

            skills = blmSkills();
            cout << "Your skills are: " + skills << endl;

            //TO-DO: black mage cantrips?
            blmCantripsSpells();

        } else if(confirmJob == 2){
            cout << "Returning to the list..." << endl;
            displayJobs();

        } else {
            cout << "Invalid selection" << endl;

        }
    } else if (job == 3){
        cout << "You have chosen Dancer. A brief summary: A supportive fighter who uses both magic and martial arts to control the battle field. Dancers are proficient in Dexterity and Charisma. \nIs this what you want? Type 1 for yes or 2 for no." << endl;
        confirmJob = confirmation(jobSelection);
        if (confirmJob == 1){
            cout << "Your job is Dancer." << endl;
            //AMB 11/22 - added confirmation stats
            finalJob = "Dancer";
            setHitPoints(8);
            hitDice = "1d8";
            savingThrows1 = "DEX";
            savingThrows2 = "CHA";
            proficiencyBonus = "+2";

            startingEquipment = dancerEquipmentChoices();
            cout << "Your starting equipment is: " + startingEquipment << endl;

            skills = dncSkills();
            cout << "Your skills are: " + skills << endl;

        } else if (confirmJob == 2) {
            cout << "Returning to the list..." << endl;
            displayJobs();

        } else {
            cout << "Invalid selection" << endl;

        }
    } else if(job == 4){
        cout << "You have chosen Gunbreaker. A brief summary: A bodyguard who augments their weaponry with manatriggers to deliver powerful attacks.Gunbreakers are proficient in Strength and Dexterity. \nIs this what you want? Type 1 for yes or 2 for no." << endl;
        confirmJob = confirmation(jobSelection);
        switch(confirmJob){
        case 1:
            cout << "Your job is Gunbreaker." << endl;
            //AMB 11/22 - added confirmation stats
            finalJob = "Gunbreaker";
            setHitPoints(10);
            hitDice = "1d10";
            savingThrows1 = "STR";
            savingThrows2 = "DEX";
            proficiencyBonus = "+2";


            startingEquipment = gunbreakerEquipmentChoices();
            cout << "Your starting equipment is: " + startingEquipment << endl;

            skills = gnbSkills();
            cout << "Your skills are: " + skills << endl;

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
            //AMB 11/22 - added confirmation stats
            finalJob = "Reaper";
            setHitPoints(10);
            hitDice = "1d10";
            savingThrows1 = "STR";
            savingThrows2 = "WIS";
            proficiencyBonus = "+2";

            startingEquipment = reaperEquipmentChoices();
            cout << "Your starting equipment is: " << startingEquipment <<endl;

            skills = rprSkills();
            cout << "Your skills are: " + skills <<endl;

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

    bool validInput = false;
    while(!validInput){
        try{

            cin >> confirmJob;

            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                throw "Please input a digit number";
            }
            if(confirmJob < 1 || confirmJob > 2){
                throw "Invalid range, please try again";
            }
            else{

                validInput = true;
            }
        } catch(const char *e){
            cin.clear();
            cout << e << endl;
            continue;
        }
    }

    return confirmJob;
}

//AMB 11/22 -adding starting equipment choices
string jobs::blackMageEquipmentChoices(){
    string startingEquipment;
    string equipmentChoice = " ";
    cout << "With the Black Mage job you get the following starting equipment: " << endl;
    cout << "Dagger, a spellcasting focus (wand, cane, staff, etc.), and a spellbook" << endl << "You get to choose one of the following: (a) explorer's pack or (b) scholar's pack" << endl;
    cin >> equipmentChoice;

    while(equipmentChoice != "a" && equipmentChoice != "b"){
        cout << "Invalid choice, please try again... enter a or b." << endl;
        cin >> equipmentChoice;
    }

    if(equipmentChoice == "a"){
        equipmentChoice = "Explorer's pack";
    } else if (equipmentChoice == "b"){
        equipmentChoice = "Scholar's pack";
    }

    startingEquipment = "Dagger, spellcasting focus, spellbook and " + equipmentChoice + ". ";
    return startingEquipment;
}

//AMB 11/22 -adding starting equipment choices
string jobs::astEquipmentChoices(){
    string startingEquipment;
    string equipmentChoice = " ";
    cout << "With the Astrologian job you get the following starting equipment: " << endl;
    cout << "Dagger, Star globe, Divination deck " << endl << "You get to choose one of the following: (a) explorer's pack or (b) scholar's pack" << endl;
    cin >> equipmentChoice;

    while(equipmentChoice != "a" && equipmentChoice != "b"){
        cout << "Invalid choice, please try again... enter a or b." << endl;
        cin >> equipmentChoice;
    }

    if(equipmentChoice == "a"){
        equipmentChoice = "Explorer's pack";
    } else if (equipmentChoice == "b"){
        equipmentChoice = "Scholar's pack";
    }

    startingEquipment = "Dagger, Star globe, Divination deck, and " + equipmentChoice + ".";
    return startingEquipment;
}

//AMB 11/22 -adding starting equipment choices
string jobs::dancerEquipmentChoices(){
    string startingEquipment;
    string equipmentChoice1;
    string equipmentChoice2;
    string equipmentChoice3;
    string equipmentChoice4;
    cout << "With the Dancer Job, you get the following starting equipment: " << endl;
    cout << "A set of clothes, a set of bracelets and anklets for spell casting, and you also get to choose the following: " << endl;

    cout << "(a) two daggers or (b) two chakrams" << endl;
    cin >> equipmentChoice1;
    while(equipmentChoice1 != "a" && equipmentChoice1 != "b"){
        cout << "Invalid choice, please try again... enter a or b." << endl;
        cin >> equipmentChoice1;
    }
    if(equipmentChoice1 == "a"){
        equipmentChoice1 = "Two daggers";
    } else if (equipmentChoice1 == "b"){
        equipmentChoice1 = "Two chakrams";
    }

    cout << endl << "a (a) whip or (b) scimitar" <<endl;
    cin >> equipmentChoice2;
    while(equipmentChoice2 != "a" && equipmentChoice2 != "b"){
        cout << "Invalid choice, please try again... enter a or b." << endl;
        cin >> equipmentChoice2;
    }
    if(equipmentChoice2 == "a"){
        equipmentChoice2 = "A whip";
    } else if (equipmentChoice2 == "b"){
        equipmentChoice2 = "Scimitar";
    }

    cout << endl << "a (a) costume or (b) light armour" << endl;
    cin >> equipmentChoice3;
    while(equipmentChoice3 != "a" && equipmentChoice3 != "b"){
        cout << "Invalid choice, please try again... enter a or b." << endl;
        cin >> equipmentChoice3;
    }
    if(equipmentChoice3 == "a"){
        equipmentChoice3 = "Costume";
    } else if (equipmentChoice3 == "b"){
        equipmentChoice3 = "Light Armour";
    }

    cout << endl << "(a) an explorer's pack or (b) a entertainer's pack" << endl;
    cin >> equipmentChoice4;
    while(equipmentChoice4 != "a" && equipmentChoice4 != "b"){
        cout << "Invalid choice, please try again... enter a or b." << endl;
        cin >> equipmentChoice4;
    }
    if(equipmentChoice4 == "a"){
        equipmentChoice4 = "Costume";
    } else if (equipmentChoice4 == "b"){
        equipmentChoice4 = "Light Armour";
    }

    startingEquipment = "A set of clothes, a set of bracelets and anklets for spell casting, " + equipmentChoice1 + ", " + equipmentChoice2 +
            ", " + equipmentChoice3 + ", " + equipmentChoice4 + ". ";

    return startingEquipment;
}

//AMB 11/22 -adding starting equipment choices
string jobs::gunbreakerEquipmentChoices(){
    string startingEquipment;
    string equipmentChoice1;
    string equipmentChoice2;
    string equipmentChoice3;
    cout << "With the Gunbreaker job you get the following starting equipment: " << endl;
    cout << "Smith's tools, martial weapon (already converted to a gun blade), and you get to choose the following: " << endl;

    cout << endl << "(a) scale mail or (b) leather armor" << endl;
    cin >> equipmentChoice1;
    while(equipmentChoice1 != "a" && equipmentChoice1 != "b"){
        cout << "Invalid choice, please try again... enter a or b." << endl;
        cin >> equipmentChoice1;
    }
    if(equipmentChoice1 == "a"){
        equipmentChoice1 = "Scale mail";
    } else if (equipmentChoice1 == "b"){
        equipmentChoice1 = "Leather armor";
    }

    cout << endl << "(a) a shield or (b) a pistol and 20 bullets" << endl;
    cin >> equipmentChoice2;
    while(equipmentChoice2 != "a" && equipmentChoice2 != "b"){
        cout << "Invalid choice, please try again... enter a or b." << endl;
        cin >> equipmentChoice2;
    }
    if(equipmentChoice2 == "a"){
        equipmentChoice2 = "Shield";
    } else if (equipmentChoice2 == "b"){
        equipmentChoice2 = "pistol and 20 bullets";
    }

    cout << endl << "(a) an explorer's pack or (b) a dungeoneer's pack" << endl;
    cin >> equipmentChoice3;
    while(equipmentChoice3 != "a" && equipmentChoice3 != "b"){
        cout << "Invalid choice, please try again... enter a or b." << endl;
        cin >> equipmentChoice3;
    }
    if(equipmentChoice3 == "a"){
        equipmentChoice3 = "explorer's pack";
    } else if (equipmentChoice2 == "b"){
        equipmentChoice3 = "dungeoneer's pack";
    }

    startingEquipment = "Smith's tools, martial weapon, " + equipmentChoice1 + ", " +
            equipmentChoice2 + ", " + equipmentChoice3 + ".";

    return startingEquipment;
}

//AMB 11/22 -adding starting equipment choices
string jobs::reaperEquipmentChoices(){
    string startingEquipment;
    string equipmentChoice1;
    string equipmentChoice2;
    string equipmentChoice3;
    string equipmentChoice4;

    cout << "With the Reaper Job you get the following starting equipment: " << endl;
    cout << "A Momento bestowed to you by the voidsent, and you get to choose the following..." << endl;

    cout << "(a) Battle Scythe or (b) one martial melee weapon" << endl;
    cin >> equipmentChoice1;
    while(equipmentChoice1 != "a" && equipmentChoice1 != "b"){
        cout << "Invalid choice, please try again... enter a or b." << endl;
        cin >> equipmentChoice1;
    }
    if(equipmentChoice1 == "a"){
        equipmentChoice1 = "Battle Scythe";
    } else if (equipmentChoice1 == "b"){
        equipmentChoice1 = "One martial melee weapon";
    }

    cout << endl << "(a) two Handaxes or (b) a Light Crossbow with 20 bolts" << endl;
    cin >> equipmentChoice2;
    while(equipmentChoice2 != "a" && equipmentChoice2 != "b"){
        cout << "Invalid choice, please try again... enter a or b." << endl;
        cin >> equipmentChoice2;
    }
    if(equipmentChoice2 == "a"){
        equipmentChoice2 = "two Handaxes";
    } else if (equipmentChoice2 == "b"){
        equipmentChoice2 = "a light Crossbow and 20 bolts";
    }

    cout << endl << "(a) scale mail or (b) light armor" << endl;
    cin >> equipmentChoice3;
    while(equipmentChoice3 != "a" && equipmentChoice3 != "b"){
        cout << "Invalid choice, please try again... enter a or b." << endl;
        cin >> equipmentChoice3;
    }
    if(equipmentChoice3 == "a"){
        equipmentChoice3 = "scale mail";
    } else if (equipmentChoice2 == "b"){
        equipmentChoice3 = "leather armor";
    }

    cout << endl << "(a) a Dungeoneer's Pack or (b) an Explorer's Pack" << endl;
    cin >> equipmentChoice4;
    while(equipmentChoice4 != "a" && equipmentChoice4 != "b"){
        cout << "Invalid choice, please try again... enter a or b." << endl;
        cin >> equipmentChoice4;
    }
    if(equipmentChoice4 == "a"){
        equipmentChoice4 = "Dungeoneer's Pack";
    } else if (equipmentChoice4 == "b"){
        equipmentChoice4 = "Explorer's Pack";
    }

    startingEquipment = "Momento bestowed to you by voidsent, " + equipmentChoice1 + ", " + equipmentChoice2 + ", " +
            equipmentChoice3 + ", " + equipmentChoice4 + ".";

    return startingEquipment;
}


//AMB 11/22 - implement skill choosing
string jobs::astSkills(){
    map<int, string> astSkills{ {1, "Arcana"}, {2, "Deception"}, {3, "Insight"} , {4, "Persuasion"}, {5, "History"}, {6, "Religion"}};
    string skills;

    int skillChoice1;
    int skillChoice2;

    map<int, string>::iterator i;
    int c = 1;
    cout << "You get to choose 2 from this list: " << endl;
    for(i = astSkills.begin(); i != astSkills.end(); i++){
        cout << c << ": " << i->second << endl;
        c++;
    }

    cout << "Choose skill 1: ";
    bool validInput = false;
    while(!validInput){
        try{ //check to see if input is inputted correctly, if not throw an error and have them re-enter
            cin >> skillChoice1;

            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                throw "Please input a digit number";
            }
            if(skillChoice1 < 1 || skillChoice1 > 6){
            throw "Invalid range, please try again";
            }
            else{
                validInput = true;
            }
        } catch(const char *e){
            cin.clear();
            cout << e << endl;
            continue;
        }
    }

    cout << "Choose your second skill: ";
    bool validInput2 = false;
    while(!validInput2){
        try{ //check to see if input is inputted correctly, if not throw an error and have them re-enter
            cin >> skillChoice2;

            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                throw "Please input a digit number";
            }
            if(skillChoice2 < 1 || skillChoice2 > 6){
                throw "Invalid range,  please try again";
            }
            if(skillChoice2 == skillChoice1){
                throw "Second choice cannot be the same as the first one, please try again";
            }
            else{
                validInput2 = true;
            }
        } catch(const char *e){
            cin.clear();
            cout << e << endl;
            continue;
        }
    }
    skills = astSkills.at(skillChoice1) + " and " + astSkills.at(skillChoice2);
    return skills;
}

//AMB 11/22 - implement skill choosing
string jobs::blmSkills(){
    string skills;
    map<int, string> bmlSkills {  {1, "Arcana"}, {2, "Deception"}, {3, "History"}, {4, "Insight"}, {5, "Intimidation"}, {6, "Persuasion"}, {7, "Religion"} };

    int skillChoice1;
    int skillChoice2;

    map<int, string>::iterator i;
    int c = 1;
    cout << "You get to choose 2 from this list: " << endl;
    for(i = bmlSkills.begin(); i != bmlSkills.end(); i++){
        cout << c << ": " << i->second << endl;
        c++;
    }

    cout << "Choose skill 1: ";
    bool validInput = false;
    while(!validInput){
        try{ //check to see if input is inputted correctly, if not throw an error and have them re-enter
            cin >> skillChoice1;

            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                throw "Please input a digit number";
            }
            if(skillChoice1 < 1 || skillChoice1 > 7){
            throw "Invalid range, please try again";
            }
            else{
                validInput = true;
            }
        } catch(const char *e){
            cin.clear();
            cout << e << endl;
            continue;
        }
    }

    cout << "Choose your second skill: ";
    bool validInput2 = false;
    while(!validInput2){
        try{ //check to see if input is inputted correctly, if not throw an error and have them re-enter
            cin >> skillChoice2;

            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                throw "Please input a digit number";
            }
            if(skillChoice2 < 1 || skillChoice2 > 7){
                throw "Invalid range,  please try again";
            }
            if(skillChoice2 == skillChoice1){
                throw "Second choice cannot be the same as the first one, please try again";
            }
            else{
                validInput2 = true;
            }
        } catch(const char *e){
            cin.clear();
            cout << e << endl;
            continue;
        }
    }

    skills = bmlSkills.at(skillChoice1) + " and " + bmlSkills.at(skillChoice2);

    return skills;
}

//AMB 11/22 - implement skill choosing
string jobs::dncSkills(){
    map<int, string> dncSkills{ {1, "Acrobatics"}, {2, "Deception"}, {3, "Insight"}, {4, "Perception"}, {5, "Performance"} , {6, "Persuasion"} };
    string skills;

    int skillChoice1;
    int skillChoice2;

    map<int, string>::iterator i;
    int c = 1;
    cout << "You get to choose 2 from this list: " << endl;
    for(i = dncSkills.begin(); i != dncSkills.end(); i++){
        cout << c << ": " << i->second << endl;
        c++;
    }

    cout << "Choose skill 1: ";

    bool validInput = false;
    while(!validInput){
        try{ //check to see if input is inputted correctly, if not throw an error and have them re-enter
            cin >> skillChoice1;

            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                throw "Please input a digit number";
            }
            if(skillChoice1 < 1 || skillChoice1 > 6){
            throw "Invalid range, please try again";
            }
            else{
                validInput = true;
            }
        } catch(const char *e){
            cin.clear();
            cout << e << endl;
            continue;
        }
    }

    cout << "Choose your second skill: ";
    bool validInput2 = false;
    while(!validInput2){
        try{ //check to see if input is inputted correctly, if not throw an error and have them re-enter
            cin >> skillChoice2;

            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                throw "Please input a digit number";
            }
            if(skillChoice2 < 1 || skillChoice2 > 6){
                throw "Invalid range,  please try again";
            }
            if(skillChoice2 == skillChoice1){
                throw "Second choice cannot be the same as the first one, please try again";
            }
            else{
                validInput2 = true;
            }
        } catch(const char *e){
            cin.clear();
            cout << e << endl;
            continue;
        }
    }

    skills = dncSkills.at(skillChoice1) + " and " + dncSkills.at(skillChoice2);

    return skills;
}

//AMB 11/22 - implement skill choosing
string jobs::gnbSkills(){
    map<int, string> gnbSkills{ {1, "Athletics"} , {2, "Acrobatics"}, {3, "History"}, {4, "Investigation"}, {5, "Intimidation"}, {6, "Persuasion"}, {7, "Stealth"}, {8, "Survival"}};
    string skills;

    int skillChoice1;
    int skillChoice2;

    map<int, string>::iterator i;
    int c = 1;
    cout << "You get to choose 2 from this list: " << endl;
    for(i = gnbSkills.begin(); i != gnbSkills.end(); i++){
        cout << c << ": " << i->second << endl;
        c++;
    }
    cout << "Choose skill 1: ";
    bool validInput = false;
    while(!validInput){
        try{ //check to see if input is inputted correctly, if not throw an error and have them re-enter
            cin >> skillChoice1;

            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                throw "Please input a digit number";
            }
            if(skillChoice1 < 1 || skillChoice1 > 8){
            throw "Invalid range, please try again";
            }
            else{
                validInput = true;
            }
        } catch(const char *e){
            cin.clear();
            cout << e << endl;
            continue;
        }
    }

    cout << "Choose your second skill: ";
    bool validInput2 = false;
    while(!validInput2){
        try{ //check to see if input is inputted correctly, if not throw an error and have them re-enter
            cin >> skillChoice2;

            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                throw "Please input a digit number";
            }
            if(skillChoice2 < 1 || skillChoice2 > 8){
                throw "Invalid range,  please try again";
            }
            if(skillChoice2 == skillChoice1){
                throw "Second choice cannot be the same as the first one, please try again";
            }
            else{
                validInput2 = true;
            }
        } catch(const char *e){
            cin.clear();
            cout << e << endl;
            continue;
        }
    }
    skills = gnbSkills.at(skillChoice1) + " and " + gnbSkills.at(skillChoice2);
    return skills;
}

//AMB 11/22 - implement skill choosing
string jobs::rprSkills(){
    map<int, string> rprSkills{ {1, "Arcana"}, {2, "Athletics"} , {3, "Insight"}, {4, "Intimidation"}, {5, "Perception"}, {6, "Religion"}};
    string skills;

    int skillChoice1;
    int skillChoice2;

    map<int, string>::iterator i;
    int c = 1;
    cout << "You get to choose 2 from this list: " << endl;
    for(i = rprSkills.begin(); i != rprSkills.end(); i++){
        cout << c << ": " << i->second << endl;
        c++;
    }
    cout << "Choose skill 1: ";
    bool validInput = false;
    while(!validInput){
        try{ //check to see if input is inputted correctly, if not throw an error and have them re-enter
            cin >> skillChoice1;

            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                throw "Please input a digit number";
            }
            if(skillChoice1 < 1 || skillChoice1 > 6){
            throw "Invalid range, please try again";
            }
            else{
                validInput = true;
            }
        } catch(const char *e){
            cin.clear();
            cout << e << endl;
            continue;
        }
    }

    cout << "Choose your second skill: ";
    bool validInput2 = false;
    while(!validInput2){
        try{ //check to see if input is inputted correctly, if not throw an error and have them re-enter
            cin >> skillChoice2;

            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                throw "Please input a digit number";
            }
            if(skillChoice2 < 1 || skillChoice2 > 6){
                throw "Invalid range,  please try again";
            }
            if(skillChoice2 == skillChoice1){
                throw "Second choice cannot be the same as the first one, please try again";
            }
            else{
                validInput2 = true;
            }
        } catch(const char *e){
            cin.clear();
            cout << e << endl;
            continue;
        }
    }

    skills = rprSkills.at(skillChoice1) + " and " + rprSkills.at(skillChoice2);
    return skills;
}

void jobs::astCantrips(){
    map<int, string> astCantripList{ {1, "Bladeward"}, {2, "Dancing Lights"}, {3, "Friends"}, {4, "Guidance"}, {5, "Light"}, {6, "Magic Stone"},
                                     {7, "Mind Sliver"}, {8, "Message"}, {9, "Resistance"}, {10, "Sacred Flame"}, {11, "Spare the Dying"},
                                     {12, "True Strike"}, {13, "Word Of Radiance"}};

    vector<int> cantripChoices = {0, 0, 0};

    cout << "Now it is time to choose your cantrips, you get to choose 3 from the following list: " << endl;

    map<int, string>::iterator i;
    int c = 1;
    for(i = astCantripList.begin(); i != astCantripList.end(); i++){
        cout << c << ": " << i->second << endl;
        c++;
    }

    int cantripChoice = 0;
    for(unsigned int i = 0; i < cantripChoices.size(); i++){
        cout << "Choose cantrip choice " << i+1 << ": ";
        bool validInput = false;
        while(!validInput){
        try{

            cin >> cantripChoice;
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                throw "Please use digits.";
            }
            if((cantripChoice < 1 || cantripChoice > 13)){
                throw "Out of range, please try again.";
            }
            if(count(cantripChoices.begin(), cantripChoices.end(), cantripChoice)){
                throw "Cantrip choice cannot be the same as past choices.";
            }

            else{
                cantripChoices.at(i) = cantripChoice;
                validInput = true;

            }
        }
        catch(const char *e){
            cin.clear();
            cout << e << endl;
            continue;
        }
        }

    }

    string cantrips = astCantripList.at(cantripChoices.at(0)) + ", " + astCantripList.at(cantripChoices.at(1)) + ", " + astCantripList.at(cantripChoices.at(2));
    setCantrips(cantrips);
    cout << "Your chosen cantrips are: " << cantrips << endl;

    map<int, string> astSpellList{{1, "Bane"}, {2, "Bless"}, {3, "Ceremony"}, {4, "Color Spray"},
                                     {5, "Comprehend Languages"}, {6, "Cure Wounds"}, {7, "Detect Evil and Good"}, {8, "Detect Magic"},
                                     {9, "Detect Poison and Disease"}, {10, "Faerie Fire"}, {11, "False Life"}, {12, "Gift of Alacrity"},
                                     {13, "Guiding Bolt"}, {14, "Healing Word"}, {15, "Heroism"}, {16, "Hex"}, {17, "Identify"}, {18, "Illsory Script"},
                                     {19, "Mage Armor"}, {20, "Magic Missile"}, {21, "Magnify Gravity"}, {22, "Sactuary"}, {23, "Shield of Faith"}, {24, "Sleep"},
                                     {25, "Unseen Servant"}, {26, "Witch Bold"}};

    cout << "Now you get to choose 2 spells from the following list: " << endl;

    vector<int> spellChoices = {0, 0};
    int spellChoice = 0;

    cout << "Now it is time to choose your spells, you get to choose 6 from the following list: " << endl;

    map<int, string>::iterator j;
    int d = 1;
    for(j = astSpellList.begin(); j != astSpellList.end(); j++){
        cout << d << ": " << j->second << endl;
        d++;
    }

    for(unsigned int i = 0; i < spellChoices.size(); i++){
        cout << "Choose spell Choice " << i+1 << ": ";
        bool validInput = false;
        while(!validInput){
        try{

            cin >> spellChoice;
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                throw "Please use digits.";
            }
            if((spellChoice < 1 || spellChoice > 26)){
                throw "Out of range, please try again.";
            }
            if(count(spellChoices.begin(), spellChoices.end(), spellChoice)){
                throw "Cantrip choice cannot be the same as past choices.";
            }

            else{
                spellChoices.at(i) = spellChoice;
                validInput = true;

            }
        }
        catch(const char *e){
            cin.clear();
            cout << e << endl;
            continue;
        }
        }

    }

    string chosenSpells = astSpellList.at(spellChoices.at(0)) + ", " + astSpellList.at(spellChoices.at(1));
    setSpells(chosenSpells);
    cout << "Your chosen spells are: " << chosenSpells << endl;

    //draw from deck
    cout << "Now drawing from your deck... " << endl;
    map<int, string> drawFromDeck {{1, "The balance - Bonus 1d6 damage on all damage rolls. This bonus damage applies once per action, attack damage roll, bonus action and reaction."},
                                   {2, "The Bole - All damage you take is reduced by 1d6."},
                                   {3, "The Arrow - You gain one extra attack when you take the attack action."},
                                   {4, "The Spear - Your attack rolls crit on a 19 or 20 die result."},
                                   {5, "The Ewer - Temporarily provides one level 1 or 2 spell slot."},
                                   {6, "The Spire - Temporarily provides 1, non-spell slot resource to an ally."}};
    int diceRolls = rand() % 6 + 1;
    string cardDrawn = drawFromDeck.at(diceRolls);
    cout << "Your card draw is: " <<  cardDrawn << endl;
    setCardDraw(cardDrawn);

}

void jobs::blmCantripsSpells(){
    map<int, string> blmCantripList{{1, "Blade Ward"}, {2, "Chill Touch"}, {3, "Fire Bolt"}, {4, "Frostbite"}, {5, "Infestation"},
                                    {6, "Lightning Lure"}, {7, "Mage Hand"}, {8, "Magic Stone"}, {9, "Produce Flame"}, {10, "Ray Of Frost"},
                                    {11, "Sapping Sting"}, {12, "Shocking Grasp"}, {13, "Thaumaturgy"}, {14, "Toll the Dead"}};

    vector<int> cantripChoices = {0, 0, 0};

    cout << "Now it is time to choose your cantrips, you get to choose 3 from the following list: " << endl;

    map<int, string>::iterator i;
    int c = 1;
    for(i = blmCantripList.begin(); i != blmCantripList.end(); i++){
        cout << c << ": " << i->second << endl;
        c++;
    }

    int cantripChoice = 0;
    for(unsigned int i = 0; i < cantripChoices.size(); i++){
        cout << "Choose cantrip choice " << i+1 << ": ";
        bool validInput = false;
        while(!validInput){
        try{

            cin >> cantripChoice;
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                throw "Please use digits.";
            }
            if((cantripChoice < 1 || cantripChoice > 14)){
                throw "Out of range, please try again.";
            }
            if(count(cantripChoices.begin(), cantripChoices.end(), cantripChoice)){
                throw "Cantrip choice cannot be the same as past choices.";
            }

            else{
                validInput = true;
                cantripChoices.at(i) = cantripChoice;
            }
        }
        catch(const char *e){
            cin.clear();
            cout << e << endl;
            continue;
        }
        }

    }

    string cantrips = blmCantripList.at(cantripChoices.at(0)) + ", " + blmCantripList.at(cantripChoices.at(1)) + ", " + blmCantripList.at(cantripChoices.at(2));
    setCantrips(cantrips);
    cout << "Your chosen cantrips are: " << cantrips << endl;

    cout << endl << "Now you get to choose 6 spells from the following list to put into your spell book: " << endl;
    map<int, string> blmSpellList{{1, "Absorb Elements"}, {2, "Burning Hands"}, {3, "Chaos Bolt"}, {4, "Detect Magic"}, {5, "Disguise Self"},
            {6, "Expeditious Retreat"}, {7, "False Life"}, {8, "Feather Fall"}, {9, "Find Familiar"}, {10, "Hex"}, {11, "Ice Knife"},
            {12, "Illusory Script"}, {13, "Inflict Wounds"}};

    vector<int> spellChoices = {0, 0, 0, 0, 0, 0};
    int spellChoice = 0;

    cout << "Now it is time to choose your spells, you get to choose 6 from the following list: " << endl;

    map<int, string>::iterator j;
    int d = 1;
    for(j = blmSpellList.begin(); j != blmSpellList.end(); j++){
        cout << d << ": " << j->second << endl;
        d++;
    }

    for(unsigned int i = 0; i < spellChoices.size(); i++){
        cout << "Choose spell Choice " << i+1 << ": ";
        bool validInput = false;
        while(!validInput){
        try{
            cin >> spellChoice;
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                throw "Please use digits.";
            }
            if((spellChoice < 1 || spellChoice > 13)){
                throw "Out of range, please try again.";
            }
            if(count(spellChoices.begin(), spellChoices.end(), spellChoice)){
                throw "Cantrip choice cannot be the same as past choices.";
            }

            else{
                spellChoices.at(i) = spellChoice;
                validInput = true;
            }
        }
        catch(const char *e){
            cin.clear();
            cout << e << endl;
            continue;
        }
        }
    }

    string chosenSpells = blmSpellList.at(spellChoices.at(0)) + ", " + blmSpellList.at(spellChoices.at(1)) + ", " + blmSpellList.at(spellChoices.at(2)) +
            ", " + blmSpellList.at(spellChoices.at(3)) + ", " + blmSpellList.at(spellChoices.at(4)) + ", " + blmSpellList.at(spellChoices.at(5));
    setSpells(chosenSpells);
    cout << "Your chosen spells are: " << chosenSpells << endl;
}
