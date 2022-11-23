#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <randomDice.h>

randomDice::randomDice() {

}

void randomDice::printStat()
{
    /* Declare stat variables */
    char stats_label[6][6];
    /* = "Str", "Dex", "Con", "Int", "Wis", "Cha"; */
    /* Declare control variables */
    int stat_loop;
    /* Seed the random number generator */
    srand((unsigned) time(NULL));
    /* Store labels in a string. This helps us later on to easily print them */
    strcpy(stats_label[0], "Str");
    strcpy(stats_label[1], "Dex");
    strcpy(stats_label[2], "Con");
    strcpy(stats_label[3], "Int");
    strcpy(stats_label[4], "Wis");
    strcpy(stats_label[5], "Cha");
    /* roll stats */
    for (stat_loop = 0; stat_loop < 6; stat_loop++)
        roll_stat(&myCharacter.stats[stat_loop]);
    /* print stats in required formatted block */
    printf("%s: %d ", stats_label[0], myCharacter.stats[0]);
    for (stat_loop = 0; stat_loop < 5; stat_loop++)
        printf("%s: %d ", stats_label[stat_loop],
               myCharacter.stats[stat_loop]);
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
