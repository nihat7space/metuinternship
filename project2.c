//Nihat Öksüz 2638039

#include <stdio.h>

int menu(int economy,int busines,int money)
{
    char choice1;

    do
    {

        int choice;
        economy = 0;
        busines = 0;
        printf("Would you like to do a booking(Y/N)?");
        if(choice1=='Y')
        {
            printf("Type 1 for economy \n");
            printf("Type 2 for busines \n");
            printf("Your choice: ");
            scanf("%d",&choice);
            switch (choice)
            {
                case 1:
                   if(economy<6)
                       economy++;
                    printf("Your booking is done successfully in seat %d",economy);
                    else
                    {
                        printf("Economy class is full ,please try business!");
                    }
                    break ;
                case 2:
                    if(busines<6)
                    {
                        busines++;
                        printf("Your booking is done successfully in seat %d",busines+5);
                        break;
                    }
                    else
                    {
                        printf("Business class is full,please try economy");
                    }
                default:
                    printf("I don't understand");
                    break;
            }

        }

    }while(choice1!='N');

    printf("You had %d economy and %d business seats booked",economy,busines);

    money = economy * 100 + busines * 200 ;
    return money ;
    return 0;
}

double invest(double money,int years)
{
    if(years==0)
    {
        return money;
    }
    else
    {
        return invest(money,years-1) + invest(money,years-1) * 0.25 ;
    }
}

void recommender(double orginalıncome,double ınvestedıncome)
{
    if(ınvestedıncome-orginalıncome<300)
    {
        printf("Cancel the flight");
    }
    else if(ınvestedıncome-orginalıncome<900)
    {
        printf("Plan the flight");
    }
    else
    {
        printf("Plan omre such flight");
    }
}

int main()
{
    int totalbusinnes;
    int totaleconomy;
    int firstmoney ;
    int investyear;

    menu(totaleconomy,totalbusinnes,firstmoney);
    printf("How many years would you like to invest this money:");
    scanf("%d",&investyear);
    invest(firstmoney,investyear);
    return 0;

}


