#include "jobs.h"
#include <limits>


jobs::jobs()
{
    jobSelection = -1;
    finalJob = "-";
    confirmJob = -1;
    hitDice = "-";
    hitPoints = 0;
    savingThrows1 = "-";
    savingThrows2 = "-";
    conPoints = 0;
    skills = " ";
    startingEquipment = "-";
    proficiencyBonus = "-";
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
int jobs::getHitPoints(){return hitPoints;}

void jobs::setConPoints(int conPoints){this->conPoints = conPoints;}
int jobs::getConPoints(){return conPoints;}

string jobs::getStartingEquipment(){return startingEquipment;}

string jobs::getProfiencyBonus(){return proficiencyBonus;}

string jobs::getSkills(){return skills;}

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
        cout << "Invalid input, please use digits." << endl;
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
        if (confirmJob == 1){
            cout << "Your job is Astrologian." << endl;
            //AMB 11/22 - added confirmation stats
            finalJob = "Astrologian";
            hitPoints = 8 + this->conPoints;
            hitDice = "1d8";
            savingThrows1 = "WIS";
            savingThrows2 = "CHA";
            proficiencyBonus = "+2";

            startingEquipment = astEquipmentChoices();
            cout << "Your starting equipment is: " + startingEquipment << endl;

            skills = astSkills();
            cout << "Your skills are: " + skills << endl;

            //TO-DO: astrologian cantrips?

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
            hitPoints = 6 + this->conPoints;
            hitDice = "1d6";
            savingThrows1 = "INT";
            savingThrows2 = "WIS";
            proficiencyBonus = "+2";

            startingEquipment = blackMageEquipmentChoices();
            cout << "Your starting equipment is: " + startingEquipment << endl;

            skills = blmSkills();
            cout << "Your skills are: " + skills << endl;

            //TO-DO: black mage cantrips?

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
            hitPoints = 8 + this->conPoints;
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
            hitPoints = 10 + this->conPoints;
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
            hitPoints = 10 + this->conPoints;
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

    cin >> skillChoice1;
    while(skillChoice1 < 1 || skillChoice1 > 6){
        cout << "Invalid choice, try again" << endl;
        cin >> skillChoice1;
    }
    while(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Invalid input, please use digits." << endl;;
        cin >> skillChoice1;
    }

    //check to see if skillChoice2 is inputted correctly
    cin >> skillChoice2;
    while(((skillChoice2 < 1) || (skillChoice2 > 6)) || (skillChoice2 == skillChoice1)){
        cout << "Invalid choice, try again" << endl;
        cin >> skillChoice2;
    }
    while(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Invalid input, please use digits." << endl;;
        cin >> skillChoice2;
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
    cin >> skillChoice1;

    //check to see if skillChoice1 is inputted correctly
    while(skillChoice1 < 1 || skillChoice1 > 7){
        cout << "Invalid choice, try again" << endl;
        cin >> skillChoice1;
    }
    while(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Invalid input, please use digits." << endl;;
        cin >> skillChoice1;
    }

    //check to see if skillChoice2 is inputted correctly
    cin >> skillChoice2;
    while(((skillChoice2 < 1) || (skillChoice2 > 7)) || (skillChoice2 == skillChoice1)){
        cout << "Invalid choice, try again" << endl;
        cin >> skillChoice2;
    }
    while(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Invalid input, please use digits." << endl;;
        cin >> skillChoice2;
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
    cin >> skillChoice1;

    //check to see if skillChoice1 is inputted correctly
    while(skillChoice1 < 1 || skillChoice1 > 6){
        cout << "Invalid choice, try again" << endl;
        cin >> skillChoice1;
    }
    while(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Invalid input, please use digits." << endl;;
        cin >> skillChoice1;
    }

    //check to see if skillChoice2 is inputted correctly
    cin >> skillChoice2;
    while(((skillChoice2 < 1) || (skillChoice2 > 6)) || (skillChoice2 == skillChoice1)){
        cout << "Invalid choice, try again" << endl;
        cin >> skillChoice2;
    }
    while(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Invalid input, please use digits." << endl;;
        cin >> skillChoice2;
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
    cin >> skillChoice1;

    //check to see if skillChoice1 is inputted correctly
    while(skillChoice1 < 1 || skillChoice1 > 8){
        cout << "Invalid choice, try again" << endl;
        cin >> skillChoice1;
    }
    while(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Invalid input, please use digits." << endl;;
        cin >> skillChoice1;
    }

    //check to see if skillChoice2 is inputted correctly
    cin >> skillChoice2;
    while(((skillChoice2 < 1) || (skillChoice2 > 8)) || (skillChoice2 == skillChoice1)){
        cout << "Invalid choice, try again" << endl;
        cin >> skillChoice2;
    }
    while(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Invalid input, please use digits." << endl;;
        cin >> skillChoice2;
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
    cin >> skillChoice1;

    //check to see if skillChoice1 is inputted correctly
    while(skillChoice1 < 1 || skillChoice1 > 6){
        cout << "Invalid choice, try again" << endl;
        cin >> skillChoice1;
    }
    while(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Invalid input, please use digits." << endl;;
        cin >> skillChoice1;
    }

    cin >> skillChoice2;

    //check to see if skillChoice2 is inputted correctly
    while(((skillChoice2 < 1) || (skillChoice2 > 6)) || (skillChoice2 == skillChoice1)){
        cout << "Invalid choice, try again" << endl;
        cin >> skillChoice2;
    }
    while(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Invalid input, please use digits." << endl;;
        cin >> skillChoice2;
    }

    skills = rprSkills.at(skillChoice1) + " and " + rprSkills.at(skillChoice2);

    return skills;
}
