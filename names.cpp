#include "names.h"
#include <limits>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
using namespace std;

//default constructor
names::names()
{
    string name = " ";
}

//AMB 11/9- added displaying name function, user chooses from inputting their own name or choosing a random name based off their clan/race
int names::displayNameGenerator(){
    int nameChoice = 0;
    cout << "Choose an option below: " << endl;
    cout << "1. Input your own name." << endl;
    cout << "2. Random name - based off race and clan." << endl;

    bool validInput = false;
    while(!validInput){
        try{
            cin >> nameChoice;
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                throw "Invalid input, please use digits";
            }
            if(nameChoice < 1 || nameChoice >2){
                throw "Invalid choice, please try again.";
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

    return nameChoice;
}

//AMB- 11/15 added randomization for names based on race, clan, and charater's sex
void names::randomName(string race, string clan, string sex){
    string firstName =  "";
    string lastName = "";

    //initizilize random seed
    srand (time(NULL));

    //Au Ra names in vectors
    vector<string> raenMNames{"Osetu", "Keimei" , "Rakuyo", "Hien", "Genbu", "Fugetsu", "Unzan", "Masatsuchi",
                           "Izuna", "Sagan", "Karaku", "Chikamasa", "Rokuyari", "Tanehiro" , "Yoshikore" , "Hidetake", "Norishig"};
    vector<string> raenFNames{"Yachiyo", "Kikyo", "Awayuki", "Narumi", "Azami", "Kurenai", "Tsubaki", "Chidori", "Suzume", "Mizuki", "Ibuki"};
    vector<string> XaelaMNames{"Arslang", "Agasiletai", "Chaghagan", "Chuacenur", "Bayan", "Luvsan", "Bujeg",
                            "Khalja", "Charakha", "Khaishan", "Chigu", "Jebke", "Cirina", "Narangerel", "Ogul", "Altan"};
    vector<string> XaelaFNames{"Boragchin", "Narengawa", "Chotan", "Qoyar", "Khorchi", "Ogul", "Checheyigen", "Altun", "Eji",
                            "Baguchi", "Odchigin", "Khorghosun", "Yesun", "Ariunbold", "Bayar"};
    vector<string>clanNames{"Adarkim", "Angura", "Arulaq", "Avagnar", "Bairon", "Bayaqud", "Bolir", "Borlaa", "Buduga", "Dalamiq", "Iriq", "Jhungid", "Kharlu", "Khatayin", "Malqir", "Mankhad", "Mierqid",
                             "Noykin", "Olkund", "Dazkar", "Oronir", "Oroq", "Qerel", "Torgud", "Tumet", "Ugund", "Uyagir", "Dhoro", "Orben", "Ejinn", "Dotharl", "Hotgo", "Sagahl", "Kahkol", "Kha", "Mol", "Gesi",
                             "Kagon", "Goro", "Gharl", "Dataq", "Haragin", "Ura", "Moks", "Geneq", "Horo", "Himaa", "Malaguld", "Urumet", "Qalli"};

    vector<string> familyNames{"Yuzuka", "Obinata", "Yuzuka", "Yatsurugi", "Rokuyari", "Godo", "Tabito", "Yumishi", "Musa"};

    //Hyur names in vectors
    vector<string> midMNames{"Odard", "Redwald", "Kenward", "Herebert", "Acwuld", "Edward", "Roderic", "Eadwine"};
    vector<string> midFNames{"Rowena", "Hilda", "Agatha", "Hrodwyn", "Goldyna", "Hounild", "Edusa", "Beyhild", "Mathilda", "Tonild", "Somerhild", "Rimilde"};
    vector<string> highMNames{"Sigmundr", "Arnar", "Armond", "Varin", "Bard", "Hordr", "Ogmundr", "Hallgrim", "Thordr", "Raubahn"};
    vector<string> highFNames{"Marte", "Cathrine", "Yngvildr", "Helene", "Kolgrima", "Katie", "Myrun", "Kaolin", "Kaia", "Kamilla"};

    vector<string> midSurname{"Taylor", "Faulkner", "Browne", "Parker", "Forrest", "River", "Miller", "Draper", "Fletcher", "Hill", "Thatcher"};
    vector<string> highSurname{"Fury", "Burne", "Savage", "Stronge", "Strongaxe", "Blood", "Furor", "Shatterfist", "Strongblade", "Ironwill"};

    //Lalafell names in vectors
    vector<string> plainsMNames{"Budadi Yidadi", "Egul Sagul", "Erelo Forelo", "Elehul Pedulehul", "Gusis Shisis"};
    vector<string> plainsFNames{"Icucu Icu", "Badada Bada", "Usoso Uso", "Kikuku Kiku"};
    vector<string> dunesMNames{"Wowokima Chichikima", "Sheshehici Rorohici", "Hihihebo Ruruhebo", "Tutushuhu Kukushuhu", "Gogoreba Susureba"};
    vector<string> dunesFNames{"Ejaja Eja", "Babayi Bayi", "Rerega Rega", "Chochosha Chosha", "Bobochu Bochu", "Lelepu Lepu"};

    //Miqo'te names in vectors
    vector<string> sunFfchar{"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
    vector<string> sunMNames{"wheto", "ciwah", "tuja", "fhemeh", "chelu", "cuhguh", "tohm", "ghut", "bod", "phur"};
    vector<string> sunFNames{"nhamfaule", "qhaalkamo", "mhagsoo", "ganni", "yhaafoqu", "gidhiju", "jotnhu", "keknhegu", "yhaiabdu", "zhamroli"};
    vector<string> moonMNames{"Axah'a", "Gohkoh'to", "Luhga'li", "Mahgeh'sae", "Mucih'ra", "Nohpu'ir", "Sahxa'wo", "Suleh'ya", "Vehse'zi", "Wizo'tan"};
    vector<string> moonFNames{"Nuhmu", "Ota", "Pehbi", "Vehba", "Yaba", "Miko", "Fafoh", "Cehxi", "Xarih", "Ecih"};

    vector<string> moonSurnames{"Dagnheive", "Dopsha", "Gauvro", "Jadnhapo", "Jhendaka", "Khutnauyu", "Phemfa", "Mhento", "Rheibfuqe", "Ruyhaia"};

    //Viera names in vectors
    vector<string> vieraMNames{"Atan", "Morn", "Tjln", "Frjn"};
    vector<string> vieraFNames{"Fran", "Jote", "Mjrn", "Kryn", "Ktjn"};

    //randomly choose names based on their race, the clan, and their character's sex
    if(race == "Au Ra"){
        if(clan == "Raen"){
            if(sex == "M"){
                firstName = raenMNames.at(rand() % raenMNames.size());
            } else if(sex == "F"){
                firstName = raenFNames.at(rand() % raenFNames.size());
            }
            //randomize surname
            lastName = familyNames.at(rand() % familyNames.size());

        } else if(clan == "Xaela"){
            if(sex == "M"){
                firstName = XaelaMNames.at(rand() % XaelaMNames.size());
            } else if(sex == "F"){
                firstName = XaelaFNames.at(rand() % XaelaFNames.size());
            }
             //randomize surname
            lastName = clanNames.at(rand() % clanNames.size());
        }

    } else if(race == "Hyur") {
        if(clan == "Midlander"){
            if(sex == "M"){
                cout << "Randomizing first name" << endl;
                firstName = midMNames.at(rand() % midMNames.size());
            } else if(sex == "F"){
                firstName = midFNames.at(rand() % midFNames.size());
            }
            //randomize surname
            cout << "Randomizing last name" << endl;
            lastName = midSurname.at(rand() % midSurname.size());


        } else if(clan == "Highlander"){
            if(sex == "M"){
                firstName = highMNames.at(rand() % highMNames.size());
            } else if(sex == "F"){
                firstName = highFNames.at(rand() % highFNames.size());
            }
            //randomize surname
            lastName = highSurname.at(rand() % highSurname.size());
        }

    } else if(race == "Lalafell"){
        if(clan == "Plainsfolk"){
            if(sex == "M"){
                firstName = plainsMNames.at(rand() % plainsMNames.size());
            } else if(sex == "F"){
                firstName = plainsFNames.at(rand() % plainsFNames.size());
            }

        } else if(clan == "Dunesfolk"){
            if(sex == "M"){
                firstName = dunesMNames.at(rand() % dunesMNames.size());
            } else if(sex == "F"){
                firstName = dunesFNames.at(rand() % dunesFNames.size());
            }
        }
    } else if(race == "Miqo'te"){
        if(clan == "Sun"){
            if(sex == "M"){
                firstName = sunFfchar.at(rand() % sunFfchar.size())  + "'" + sunMNames.at(rand() % sunMNames.size());
                lastName = "Tia"; //all last names of males in the seekers of the sun are Tia
            } else if(sex == "F"){
                firstName = sunFfchar.at(rand() % sunFfchar.size())  + "'" + sunFNames.at(rand() % sunFNames.size());
                lastName = sunMNames.at(rand() % sunMNames.size()); //last names for female seekers are the first name of breeding male
            }

        } else if(clan == "Moon"){
            if(sex == "M"){
                firstName = moonMNames.at(rand() % moonMNames.size());
            } else if(sex == "F"){
                firstName = moonFNames.at(rand() % moonFNames.size());
            }
            //set last name of keepers of the moon
            lastName = moonSurnames.at(rand() % moonSurnames.size());
        }

    } else if(race == "Viera") {
        if(sex == "M"){
            firstName = vieraMNames.at(rand() % vieraMNames.size());
        } else if(sex == "F"){
            firstName = vieraFNames.at(rand() % vieraFNames.size());
        }
    }

    //set the randomly generated name]
    setCharacterName(firstName, lastName);
}


//returns character's name, whether random or inputted by user
string names::getCharacterName(){
    return name;
}


//sets character's name.
void names::setCharacterName(string firstName, string lastName){
    name = firstName + " " + lastName;
}

//set characters name (for own input)
void names::setCharacterName(string characterName){
    name = characterName;
}
