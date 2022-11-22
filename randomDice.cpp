#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <randomDice.h>

randomDice::randomDice() {

}

int randomDice::printStat()
{
    /* Declare stat variables */
    char stats_label[7][6];
    /* = "Level", "Str", "Dex", "Con", "Int", "Wis", "Cha"; */
    /* Declare control variables */
    int stat_loop, accept = 0;
    /* Seed the random number generator */
    srand((unsigned) time(NULL));
    /* Store labels in a string. This helps us later on to easily print them */
    strcpy(stats_label[0], "Level");
    strcpy(stats_label[1], "Str");
    strcpy(stats_label[2], "Dex");
    strcpy(stats_label[3], "Con");
    strcpy(stats_label[4], "Int");
    strcpy(stats_label[5], "Wis");
    strcpy(stats_label[6], "Cha");
    while (!accept) {
    /* read in level */
    scanf("%d", &myCharacter.stats[0]);
    /* roll stats */
    for (stat_loop = 1; stat_loop < 7; stat_loop++)
        roll_stat(&myCharacter.stats[stat_loop]);
    /* calculate bonuses */
    myCharacter.bonus[0] = roll_hp(myCharacter.stats[0]);
    for (stat_loop = 1; stat_loop < 7; stat_loop++)
        get_bonus(&myCharacter.bonus[stat_loop],
              myCharacter.stats[stat_loop]);
    /* print the stats out for acceptance */
    printf("%s: %d ", stats_label[0], myCharacter.stats[0]);
    for (stat_loop = 1; stat_loop < 7; stat_loop++)
        printf("%s: %d %d ", stats_label[stat_loop],
           myCharacter.stats[stat_loop],
           myCharacter.bonus[stat_loop]);
    printf("Hitpoints: %d\n", myCharacter.bonus[0]);
    /* check for loop exit condition */
    printf
        ("Do you want to accept these? \n (enter 1 to accept, 0 to reroll): ");
    scanf("%d", &accept);
    }
    /* print stats in required formatted block */
    printf("[%s] [%d]\n", stats_label[0], myCharacter.stats[0]);
    for (stat_loop = 1; stat_loop < 7; stat_loop++)
    printf("[%s]: [%d] [%d] \n", stats_label[stat_loop],
           myCharacter.stats[stat_loop], myCharacter.bonus[stat_loop]);
    printf("[Hitpoints]: [%d]\n", myCharacter.bonus[0]);
    return (0);
}

/* Roll 4d6 and drop lowest */
void randomDice::roll_stat(int *stat_to_be_rolled)
{
    int dice1, dice2, dice3, dice4, total;
    /* Roll 4d6 */
    dice1 = (rand() % 6 + 1);
    dice2 = (rand() % 6 + 1);
    dice3 = (rand() % 6 + 1);
    dice4 = (rand() % 6 + 1);
    /* Find lowest dice and add result of the other 3 */
    if ((dice1 < dice2) && (dice1 < dice3) && (dice1 < dice4))
    total = dice2 + dice3 + dice4;
    else if ((dice2 < dice1) && (dice2 < dice3) && (dice2 < dice4))
    total = dice1 + dice3 + dice4;
    else if ((dice3 < dice1) && (dice3 < dice2) && (dice3 < dice4))
    total = dice1 + dice2 + dice4;
    else
    total = dice1 + dice2 + dice3;
    /* assign total value to the memory location we were given */
    *stat_to_be_rolled = total;
}

/* This was extracted as a function to make the bonus loop more compact */
void randomDice::get_bonus(int *bonus_to_be_calculated, int base_stat)
{
    if (base_stat > 9)
    *bonus_to_be_calculated = (base_stat - 10) / 2;
    else
    *bonus_to_be_calculated = (base_stat - 11) / 2;
}

/* This was extracted as a function to make the HP loop more compact */
int randomDice::roll_hp(int char_level)
{
    int hploop = 0, hp = 0;
    /* printf("Leve1: %d", char_level); For testing */
    for (hploop = 0; hploop < char_level; hploop++)
    hp += (rand() % 6 + 1);
    return (hp);
}
