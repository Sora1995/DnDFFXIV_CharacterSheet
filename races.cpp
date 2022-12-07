//Have user choose race from the list given. Once they've chosen one, give them a breif description of the race. Then have them confirm the race.
//If they don't want the race chosen, then they can repick one.

//AMB 11/7- Added all the races and their clan options
//AMB 11/8- added confirmation and added logic to add to stats


#include "races.h"
#include <limits>

//default
races::races()
{
    raceSelection = -1;
    clanSelection = " ";
    walkingSpeed = 0;
    raceAbilityScore = " ";
    raceASIncreaseAmount = 0;
    clanAbilityScore = " ";
    clanASIncreaseAmount = 0;
}

//getters and setters
//race
void races::setRace(string race){
    raceString = race;
}
string races::getRace(){
    return raceString;
}

//clan
void races::setClan(string clan){
    clanSelection = clan;
}
string races::getClan(){
    return clanSelection;
}

//race ability score
void races::setRaceAbilityScore(string raceAS){
    raceAbilityScore = raceAS;
}
string races::getRaceAbilityScore(){
    return raceAbilityScore;
}

//race ability score increase amount
void races::setRaceASIncreaseAmount(int raceASIncrease){
    raceASIncreaseAmount = raceASIncrease;
}
int races::getRaceASIncreaseAmount(){
    return raceASIncreaseAmount;
}

//clan ability score
void races::setClanAbilityScore(string clanAS){
    clanAbilityScore = clanAS;
}
string races::getClanAbilityScore(){
    return clanAbilityScore;
}

//clan ability score increase amount
void races::setClanASIncreaseAmount(int clanASIncrease){
    clanASIncreaseAmount = clanASIncrease;
}
int races::getClanASIncreaseAmount(){
    return clanASIncreaseAmount;
}

//walking speed
void races::setWalkingSpeed(int speed){
    walkingSpeed = speed;
}
int races::getWalkingSpeed(){
    return walkingSpeed;
}

//display the races to the user to choose from
void races::displayRaces() {
    cout << "Please select a race from the list below: " << endl;
    cout << "1. Au Ra" << endl;
    cout << "2. Hyur" << endl;
    cout << "3. Lalafell" << endl;
    cout << "4. Miqo'te" << endl;
    cout << "5. Viera" << endl;

    bool validInput = false;
    while(!validInput){
        try{
            cin >> raceSelection;

            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                throw "Please input a digit number";
            }
            if(raceSelection < 1 || raceSelection > 5){
                throw "Invalid range, please try again";
            }
            else{
                listRaces(raceSelection);
                validInput = true;
            }
        } catch(const char *e){
            cin.clear();
            cout << e << endl;
            continue;
        }
    }

}

void races::listRaces(int race) {

    if(race == 1){  //Au Ra
        raceString = "Au Ra";
        cout << endl << "You have chosen Au Ra. The Au Ra hail from the east, and are marked by their scales and horns. These people have a stark difference in height between the males and females of the species. The males tend to be much taller than the females and many other races, while the females on average are shorter than many of the other races." << endl;
        cout << endl << "Within the Au Ra there are two clans, Xaela and Raen." << endl;
        cout << "The dark scaled Xaela are nomads who travel the Azim Steppe and have developed a wide variety of customs which change from tribe to tribe." << endl;
        cout << "The light scaled Raen live largely integrated into modern society, giving up their nomadic ways for peaceful coexistence with the other races." << endl;

        cout << "With the Au Ra race, your wisdom ability score will increase by 2. Your base walking speed is 30ft. " << endl;
        cout << "If you choose the Xaela clan, your Strength will increase by 2. If you choose Raen, your Charisma Score will increase by 1." << endl;
        cout << "Choose a clan to align with... 'Xaela', or 'Raen': " << endl;

        cin >> clanSelection;
        while (clanSelection != "Xaela" && clanSelection != "Raen"){
            cout << "Please enter your selection with the first letter capitalized." << endl;
            cin >> clanSelection;
        }

        //AMB 11/8- Added confirmation and logic to increase the ability scores.
        raceConfirm = raceConfirmation(raceString, clanSelection);

            switch(raceConfirm){
                case 1 : //confirmed selection
                    cout << "You have confirmed the race selection of " << raceString << " with the clan " << clanSelection << "."  << endl;

                    walkingSpeed = 30;
                    raceAbilityScore = "Wisdom";
                    raceASIncreaseAmount = 2;

                    if (clanSelection == "Xaela"){
                        clanAbilityScore = "Strength";
                        clanASIncreaseAmount = 2;
                    } else {
                        clanAbilityScore = "Charisma";
                        clanASIncreaseAmount = 1;
                    }
                break;

                case 2 : //wants to reselect race and clan
                    cout << "Please reselect your race and clan." << endl;
                    displayRaces();
                break;

                default : //default
                    cout << "Invalid selection." << endl;
                break;
            }
    }else if(race == 2) { //Hyur
        raceString = "Hyur";
        string increaseChoiceString = " ";
        cout << "You have chosen Hyur. The Hyur have spread across the entirety of the world, making it difficult to trace what their homeland truly is. There are the average sized Midlanders, named for the elevation in which their sub species lived for many years, and the taller, more muscular highlanders, who lived in the high mountains for their declared homeland."  << endl << endl;

        cout << "With the Hyur race, you get to choose what your ability score increase is. Your base walking speed is 30ft." << endl;
        cout << " Choose an ability score to increase by 1:" << endl;
        cout << "1. Strength" << endl << "2. Dexterity" << endl << "3. Constitution" << endl << "4. Intelligence" << endl << "5. Wisdom" << endl << "6. Charisma" << endl;

        bool validInput = false;
        while(!validInput){
        try{
            cin >> increaseChoice;
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                throw "Please use digits";
            }
            if(increaseChoice < 1 || increaseChoice > 5){
                throw "Invalid range, please try again.";
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

        switch(increaseChoice){
            case 1: increaseChoiceString = "Strength"; break;
            case 2: increaseChoiceString = "Dexterity"; break;
            case 3: increaseChoiceString = "Constitution"; break;
            case 4: increaseChoiceString = "Intelligence"; break;
            case 5: increaseChoiceString = "Wisdom"; break;
            case 6: increaseChoiceString = "Charisma"; break;
        }

        cout << endl;

        cout << "Within the Hyur race there are two clans, Midlander and Highlander." << endl;
        cout << "Midlander's ability score, intelligence, increases by 2. Highlander's ability score, strength, increases by 2." << endl;
        cout << "Choose a clan to align with... 'Midlander' or 'Highlander': " << endl;

        cin >> clanSelection;
        while (clanSelection != "Midlander" && clanSelection != "Highlander"){
            cout << "Please enter your selection with the first letter capitalized." << endl;
            cin >> clanSelection;
        }

        //AMB 11/8- Added confirmation and logic to increase the ability scores.
        raceConfirm = raceConfirmation(raceString, clanSelection);

        switch(raceConfirm){

        case 1 : //confirmed selection
            cout << "You have confirmed the race selection of " << raceString << " with the clan " << clanSelection << "."  << endl;

            //set scores/stats
            walkingSpeed = 30;
            raceAbilityScore = increaseChoiceString;
            raceASIncreaseAmount = 1;

            if (clanSelection == "Midlander"){
                clanAbilityScore = "Intelligence";
                clanASIncreaseAmount = 2;
            } else {
                clanAbilityScore = "Strength";
                clanASIncreaseAmount = 2;
            }
        break;

        case 2 : //wants to reselect race and clan
            cout << "Please reselect your race and clan." << endl;
            displayRaces();
            break;

        default : //default
            cout << "Invalid selection." << endl;
            break;
        }
    } else if(race == 3){ //Lalafell
        raceString = "Lalafell";

        cout << "You have chosen Lalafell. A dimunitive race, the Lalafell immigrated from Southern islands to Eorzea forming two distinct groups based on the geography their ancestors settled in. " << endl;
        cout << "Within the Lalafell race there are two clans, Plainsfolk and Dunesfolk." << endl;
        cout << "The darker skinned Dunesfolk formed the city state of Ul'dah in the deserts of Thanalan, while the lighter skinned Planesfolk settled and farmed the lands of La Noscea, a large island off the mainland of Eorzea." << endl;
        cout << " Both of these naturally charming folk found great success as merchants through history." << endl << endl;

        cout << "With the Lalafell race, your Charisma ability score will increase by 1. Your base walking speed is 25ft." << endl;
        cout << "If you choose the Plainsfolk, your Dexterity ability score will increase by 1. If you choose the Dunesfolk, your Intelligence ability score will increase by 1" << endl;
        cout << "Choose your clan to align with... 'Plainsfolk' or 'Dunesfolk':" << endl;

        cin >> clanSelection;
        while(clanSelection != "Plainsfolk" && clanSelection != "Dunesfolk"){
            cout << "Please enter your selection with the first letter capitalized." << endl;
            cin >> clanSelection;
        }

        //AMB 11/8- Added confirmation and logic to increase the ability scores.
        raceConfirm = raceConfirmation(raceString, clanSelection);
        switch(raceConfirm){
            case 1 : //confirmed selection
                cout << "You have confirmed the race selection of " << raceString << " with the clan " << clanSelection << "."  << endl;

                //set scores/stats
                walkingSpeed = 25;

                raceAbilityScore = "Charisma";
                raceASIncreaseAmount = 1;

                if (clanSelection == "Plainsfolk"){
                    clanAbilityScore = "Dexterity";
                    clanASIncreaseAmount = 1;
                } else {
                    clanAbilityScore = "Intelligence";
                    clanASIncreaseAmount = 1;
                }
            break;
            case 2 : //wants to reselect race and clan
                cout << "Please reselect your race and clan." << endl;
                displayRaces();
            break;
            default : //default
                cout << "Invalid selection." << endl;
            break;
        }
    } else if(race == 4){


        raceString = "Miqo'te";

        cout << "You have chosen Miqo'te. The Miqo'te are a second group of feline people who traveled to Eorzea across a frozen sea long ago. These proud people find pride in their natural hunting ability and have split into two distinct ethnic groups who worship the sun and moon respectively." << endl;
        cout << "The Seekers of the Sun live in warmer clients in patriarchal societies." << endl;
        cout << "The Keepers of the Moon live in dense forests, their tribes centering on matriarchs. " << endl << endl;

        cout << "With the Miqo'te race, your Wisdom ability score increases by 2. Your base walking speed is 30ft." << endl;
        cout << "If you choose the Seekers of the Sun clan your Charisma ability score will increase by 1. If you choose the Keepers of the Moon clan, your Wisdom ability score will increase by 1." << endl;
        cout << "Choose the clan you would like to align with... 'Sun' or 'Moon': " << endl;

        cin >> clanSelection;
        while(clanSelection != "Sun" && clanSelection != "Moon"){
            cout << "Please enter your selection with the first letter capitalized." << endl;
            cin >> clanSelection;
        }

        //AMB 11/8- Added confirmation and logic to increase the ability scores.
        raceConfirm = raceConfirmation(raceString, clanSelection);

        switch(raceConfirm){
            case 1 : //confirmed selection
                cout << "You have confirmed the race selection of " << raceString << " with the clan " << clanSelection << "."  << endl;

                walkingSpeed = 30;

                raceAbilityScore = "Wisdom";
                raceASIncreaseAmount = 2;

                if (clanSelection == "Sun"){
                    clanAbilityScore = "Charisma";
                    clanASIncreaseAmount = 1;
                } else {
                    clanAbilityScore = "Moon";
                    clanASIncreaseAmount = 1;
                }
            break;
            case 2 : //wants to reselect race and clan
                cout << "Please reselect your race and clan." << endl;
                displayRaces();
            break;
            default : //default
                cout << "Invalid selection." << endl;
            break;
        }
    } else if(race == 5){
        raceString = "Viera";

        cout << "You have chosen Viera. The Viera are lapine people who live in dense forests and act as the protectors of their home. With their more secluded nature, they generally avoid contact with the outside world, happily protecting the Golmore Jungles and Skatay Range, both found in the east. " << endl;
        cout << "There are two distinct groups of Viera who developed slightly differently based on their homes. The Rava having darker skin while the Veena have far fairer skin, both groups blending into their respective environments better thanks to these adaptations."  << endl << endl;

        cout << "With the Viera race, your Dexterity ability score increases by 2. Your base walking speed is 35ft." << endl;
        cout << "If you choose the Rava clan, your Wisdom ability score will increase by 1. If you choose Veena, your Intelligence ability score will increase by 1." << endl;
        cout << "Choose the clan you would like to align with... 'Rava' or 'Veena.': " << endl;

        cin >> clanSelection;
        while(clanSelection != "Rava" && clanSelection != "Veena"){
            cout << "Please enter your selection with the first letter capitalized." << endl;
            cin >> clanSelection;
        }

        //AMB 11/8- Added confirmation and logic to increase the ability scores.
        raceConfirm = raceConfirmation(raceString, clanSelection);
        switch(raceConfirm){
            case 1 : //confirmed selection
                cout << "You have confirmed the race selection of " << raceString << " with the clan " << clanSelection << "."  << endl;

                walkingSpeed = 35;

                raceAbilityScore = "Dexterity";
                raceASIncreaseAmount = 2;

                if (clanSelection == "Rava"){
                    clanAbilityScore = "Wisdom";
                    clanASIncreaseAmount = 1;
                } else {
                    clanAbilityScore = "Intelligence";
                    clanASIncreaseAmount = 1;
                }
            break;
            case 2 : //wants to reselect race and clan
                cout << "Please reselect your race and clan." << endl;
                displayRaces();
            break;
            default : //default
                cout << "Invalid selection." << endl;
            break;
        }

    } else { //default
        cout << "Invalid selection." << endl;
    }
}

//confirms the race to user and returns a 1 for yes and 2 for no
int races::raceConfirmation(string race, string clan){
    int raceConfirm = 3;

    cout << "Your selected race is: " << race << endl << "Your selected clan is: " << clan << endl;
    cout << "Would you like to confirm this selection?" << endl << "1. Yes, confirm my selection." << endl << "2. No, I would like to reselect my race and clan." << endl;
    bool validInput = false;
    while(!validInput){
        try{
            cin >> raceConfirm;
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                throw "Invalid input, please use digits.";
            }
            if(raceConfirm < 1 || raceConfirm > 2){
                throw "Invalid selection, please try again...";
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
    return raceConfirm;
}


