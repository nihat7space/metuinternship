// Nihat Oksuz 2638039
// Nihat Oksuz 2638039
// Nihat Oksuz 2638039


#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int rolladice() {
    return (rand() % 6 + 1);
}

int calculate_score(int dice1, int dice2, int dice3) {
    if ((dice1 == dice2 || dice1 == dice3 || dice2 == dice3) && (dice1 + dice2 + dice3 == 13)) {
        printf("Crag! \n");
        return 50;
    } else if (dice1 + dice2 + dice3 == 13) {
        return 26;
    } else if (dice1 == dice2 && dice2 == dice3) {
        return 25;
    } else if (dice1 == 1 && dice2 == 2 && dice3 == 3) {
        return 20;
    } else if (dice1 == 4 && dice2 == 5 && dice3 == 6) {
        return 20;
    } else if (dice1 == 1 && dice2 == 3 && dice3 == 5) {
        return 20;
    } else if (dice1 == 2 && dice2 == 4 && dice3 == 6) {
        return 20;
    } else {
        return dice1 + dice2 + dice3;
    }
}

int play_user() {
    int dice1 = rolladice();
    int dice2 = rolladice();
    int dice3 = rolladice();
    char choice;
    printf("You got --> [Dice 1]: %d [Dice 2]: %d [Dice 3]: %d \n", dice1, dice2, dice3);

    printf("Shall I roll for you (Y/N)? ");
    scanf(" %c", &choice);

    while (1) {
        switch (choice) {
            case 'Y':
            case 'y': {
                int keep1, keep2;

                do {
                    printf("Which ones do you want to keep? ");
                    scanf("%d %d", &keep1, &keep2);

                    if (keep1 < 1 || keep1 > 3 || keep2 < 1 || keep2 > 3 || keep1 == keep2) {
                        printf("Sorry, wrong input!\n");
                    }
                } while (keep1 < 1 || keep1 > 3 || keep2 < 1 || keep2 > 3 || keep1 == keep2);

                if ((keep1 == 1 && keep2 == 2) || (keep1 == 2 && keep2 == 1)) {
                    dice3 = rolladice();
                    printf("You got --> [Dice 1]: %d [Dice 2]: %d [Dice 3]: %d \n", dice1, dice2, dice3);
                } else if ((keep1 == 1 && keep2 == 3) || (keep1 == 3 && keep2 == 1)) {
                    dice2 = rolladice();
                    printf("You got --> [Dice 1]: %d [Dice 2]: %d [Dice 3]: %d \n", dice1, dice2, dice3);
                } else {
                    dice1 = rolladice();
                    printf("You got --> [Dice 1]: %d [Dice 2]: %d [Dice 3]: %d \n", dice1, dice2, dice3);
                }
                printf("Your score: %d\n", calculate_score(dice1, dice2, dice3));
                return calculate_score(dice1, dice2, dice3);
            }
            case 'N':
            case 'n': {
                printf("You got --> [Dice 1]: %d [Dice 2]: %d [Dice 3]: %d \n", dice1, dice2, dice3);
                printf("Your score: %d\n", calculate_score(dice1, dice2, dice3));
                return calculate_score(dice1, dice2, dice3);
            }
            default:
                printf("Sorry, I don't understand! \n");
                printf("Would you like to roll again? (Y/N) ");
                scanf(" %c", &choice);
                break;
        }
    }
}

int play_computer() {
    int dice1 = rolladice();
    int dice2 = rolladice();
    int dice3 = rolladice();
    printf("I rolled them and I got --> [Dice 1]: %d [Dice 2]: %d [Dice 3]: %d \n", dice1, dice2, dice3);

    int score = calculate_score(dice1, dice2, dice3);

    if ((dice1 == 4 && dice2 == 5 && dice3 == 5) ||
        (dice1 == 4 && dice2 == 5 && dice3 == 1) ||
        (dice1 == 4 && dice2 == 5 && dice3 == 2) ||
        (dice1 == 3 && dice2 == 5 && dice3 == 6) ||
        (dice1 == 4 && dice2 == 3 && dice3 == 6) ||
        (dice1 == 1 && dice2 == 5 && dice3 == 6))
    {
        if (dice1 == 4 && dice2 == 5 && dice3 == 5)
        {
            printf("Rolled dice 3!\n");
            dice3 = 6;
        }
        else if (dice1 == 4 && dice2 == 5 && dice3 == 1)
        {
            printf("Rolled dice 3!\n");
            dice3 = 6;
        }
        else if (dice1 == 4 && dice2 == 5 && dice3 == 2)
        {
            printf("Rolled dice 3!\n");
            dice3 = 6;
        }
        else if (dice1 == 3 && dice2 == 5 && dice3 == 6)
        {
            printf("Rolled dice 1!\n");
            dice1 = 4;
        }
        else if (dice1 == 4 && dice2 == 3 && dice3 == 6)
        {
            printf("Rolled dice 2!\n");
            dice2 = 5;
        }
        else if (dice1 == 1 && dice2 == 5 && dice3 == 6)
        {
            printf("Rolled dice 1!\n");
            dice1 = 4;
        }

        printf("[Dice 1]: %d [Dice 2]: %d [Dice 3]: %d \n", dice1, dice2, dice3);
        score = calculate_score(dice1, dice2, dice3);
    }

    printf("My score: %d\n", score);
    return score;
}

int main() {
    srand(time(0));
    int round;
    int computerroll, playerroll;
    int computerTotalScore = 0;
    int playerTotalScore = 0;
    printf("Welcome to Crag game.\n");
    printf("Lets get started! \n");
    printf("How many rounds would you like to play? ");
    scanf("%d", &round);
    computerroll = rolladice();
    playerroll = rolladice();
    printf("I have rolled the dice and got %d! \n", computerroll);
    printf("I have rolled the dice for you and you got %d! \n", playerroll);

    if (playerroll > computerroll) {
        for (int i = 1; i <= round; i++) {
            printf("Round %d -- Your Turn \n", i);
            playerTotalScore += play_user();
            printf("Round %d -- My Turn \n", i);
            computerTotalScore += play_computer();
            printf("Our scoresheet after round %d:\n", i);
            printf("=========================\n");
            printf("Computer's score   Your score\n");
            printf("%d                       %d\n", computerTotalScore, playerTotalScore);
        }
    } else {
        for (int i = 1; i <= round; i++) {
            printf("Round %d -- My Turn \n", i);
            computerTotalScore += play_computer();
            printf("Round %d -- Your Turn \n", i);
            playerTotalScore += play_user();
            printf("Our scoresheet after round %d:\n", i);
            printf("==========================\n");
            printf("Computer's score   Your score\n");
            printf("%d                      %d\n", computerTotalScore, playerTotalScore);
        }
    }

    if (computerTotalScore > playerTotalScore) {
        printf("COMPUTER WIN!\n");
    } else {
        printf("YOU ARE THE WINNER!\n");
    }

    return 0;
}


