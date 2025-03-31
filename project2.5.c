#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Store
{
    int id;
    char name[50];
    char surname[50];
    char gender[50];
    int smoking;
    char lungcancer[50];
};

int numberofline(int *number)
{
    FILE *file = fopen("data.txt","r");
    if(file==NULL)
    {
        printf("Eror while calculating the number of line! \n");
        exit(1);
    }

    char ch;
    while((ch = fgetc(file))!=EOF)
    {
        if(ch == '\n')
        {
            (*number)++;
        }
    }
    fclose(file);
    return (*number)++;
}
void populatedata(struct Store *e,int number) //Yes actually we can write dynmacilay array here
{
    FILE *inflie = fopen("data.txt","r");
    if(inflie==NULL)
    {
        printf("Eror while reading a file \n");
        exit(1);
    }
    int i;
    for(i=0;i<number;i++)
    {
        fscanf(inflie,"%d %s %s %s %d %s\n",&e[i].id,e[i].name,e[i].surname,e[i].gender,&e[i].smoking,e[i].lungcancer);
    }
    fclose(inflie);
}
void displaydata(struct Store *e,int number) //This function pass by referance because we used pointer
{
    int i;
    for(i=0;i<number;i++)
    {
        printf("%d %s %s %s %d %s\n",e[i].id,e[i].name,e[i].surname,e[i].gender,e[i].smoking,e[i].lungcancer);
    }
}
void statdata(struct Store *e,int number)
{
    int lung = 0;
    int nonlung = 0;
    int male=0;
    int female=0;
    int i;
    for(i=0;i<number;i++)
    {
        if(strchr(e[i].lungcancer,'Y'))
        {
            lung++;
        }
        else if(strchr(e[i].lungcancer,'N'))
        {
            nonlung++;
        }
        if(strchr(e[i].gender,'M'))
        {
            male++;
        }
        else if(strchr(e[i].gender,'F'))
        {
            female++;
        }
    }
    printf("%d patient with cancer and %d patient without cancer.\n",lung,nonlung);
    printf("%d Male and %d Female patients \n",male,female);
}
void splitdata(struct Store *e,int number)
{

    FILE *cancer = fopen("cancer.txt","w");
    if(cancer==NULL)
    {
        printf("Eror while creating a cancer file! \n");
        exit(1);
    }
    FILE *noncancer = fopen("noncancer.txt","w");
    if(noncancer==NULL)
    {
        printf("Eror while creating a noncancer file! \n");
        exit(1);
    }
    int i;
    for(i=0;i<number;i++)
    {
        if(strchr(e[i].lungcancer,'Y'))
        {
            fprintf(cancer,"%d %s %s %s %d %s\n",e[i].id,e[i].name,e[i].surname,e[i].gender,e[i].smoking,e[i].lungcancer);
        }
        else
        {
            fprintf(noncancer,"%d %s %s %s %d %s\n",e[i].id,e[i].name,e[i].surname,e[i].gender,e[i].smoking,e[i].lungcancer);
        }
    }
}
int main()
{
    int number=0;
    numberofline(&number);
    struct Store *report;
    report = (struct Store *) malloc(sizeof(struct Store) * number); // We create a dynamicaly array
    populatedata(report,number);
    displaydata(report,number);
    statdata(report,number);
    splitdata(report,number);
    free(report);
    return 0;
}