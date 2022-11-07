//Have user choose race from the list given. Once they've chosen one, give them a breif description of the race. Then have them confirm the race.
//If they don't want the race chosen, then they can repick one.

//AMB 11/7- Added all the races and their clan options


#include "races.h"

races::races()
{
    raceSelection = -1;
}

void races::displayRaces() {
    cout << "Please select a race from the list below: " << endl;
    cout << "1. Au Ra" << endl;
    cout << "2. Hyur" << endl;
    cout << "3. Lalafell" << endl;
    cout << "4. Miqo'te" << endl;
    cout << "5. Viera" << endl;

    //AMB - TODO: add try/catch to catch if the user enters a wrong input type.
    cin >> raceSelection;
    while(raceSelection < 1 || raceSelection > 5) {
        cout << "Invalid selection, please try again." << endl;
        cin >> raceSelection;
    }

    listRaces(raceSelection);
}

void races::listRaces(int race) {
    switch(race){
    case 1 : //Au Ra
        cout << endl << "You have chosen Au Ra. The Au Ra hail from the east, and are marked by their scales and horns. These people have a stark difference in height between the the males and females of the species. The males tend to be much taller than the females and many other races, while the females on average are shorter than many of the other races." << endl;
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

        //AMB - TO-DO: add confirmation
        //AMB - TO-DO: Add Logic to increase ability scores when the slection is confirmed.

        break;

    case 2 : //Hyur
        cout << "You have chosen Hyur. The Hyur have spread across the entirety of the world, making it difficult to trace what their homeland truly is. There are the average sized Midlanders, named for the elevation in which their sub species lived for many years, and the taller, more muscular highlanders, who lived in the high mountains for their declared homeland."  << endl << endl;

        cout << "With the Hyur race, you get to choose what your ability score increase is. Your base walking speed is 30ft." << endl;
        cout << " Choose an ability score to increase by 1:" << endl;
        cout << "1. Strength" << endl << "2. Dexterity" << endl << "3. Constitution" << endl << "4. Intelligence" << endl << "5. Wisdom" << endl << "6. Charisma" << endl;
        cin >> increaseChoice;
        while (increaseChoice < 1 || increaseChoice > 5){
            cout << "Invalid selection, please try again.";
            cin >> increaseChoice;
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

        //AMB - TO-DO: add confirmation
        //AMB - TO-DO: Add Logic to increase ability scores when the slection is confirmed.

        break;

    case 3 : //Lalafell
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

        //AMB - TO-DO: add confirmation
        //AMB - TO-DO: Add Logic to increase ability scores when the slection is confirmed.

        break;

    case 4: // Miqo'te
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

        //AMB - TO-DO: add confirmation
        //AMB - TO-DO: Add Logic to increase ability scores when the slection is confirmed.
        break;

    case 5: //Viera
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

        //AMB - TO-DO: add confirmation
        //AMB - TO-DO: Add Logic to increase ability scores when the slection is confirmed.
        break;

    default : //default
        cout << "Invalid selection." << endl;
        break;
    }
}
