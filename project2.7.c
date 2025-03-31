#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void populateVector(int *vector,int length)
{
    srand(time(0));
    for(int i = 0 ; i < length ; i++)
    {
        vector[i] = rand() % 11 ;
    }
}int dotProduct(int *vectorA , int *vectorB, int lenght)
{
    int sum = 0 ;
    for(int i = 0 ; i < lenght ; i++)
    {
        sum += vectorA[i] + vectorB[i];
    }
    return sum ;
}
double magnitude(int *vector,int lenght)
{
    double magni = 0 ;
    for(int i = 0 ; i < lenght ; i++)
    {
        magni = magni + vector[i] * vector[i];
    }
    double result = sqrt(magni) ;
    return result ;
}


int main()
{
    int length;
    printf("Enter the lenght:");
    scanf("%d",&length);
    if(length == 0)
    {
        printf("Sorry invalid input please try again \n");
        printf("Enter the lenght:");
        scanf(" %d",&length);
    }

    int *vectorA = (int *) malloc(length * sizeof(int));
    int *vectorB = (int *) malloc(length * sizeof(int));

    populateVector(vectorA,length);
    populateVector(vectorB,length);

    printf("Vector A: \n");
    for(int i = 0 ; i < length ; i++)
    {
        printf("%d ",vectorA[i]);
    }
    printf("\n");
    printf("Vector B: \n");
    for(int i = 0 ; i < length ; i++)
    {
        printf("%d ",vectorB[i]);
    }
    printf("\n");

    int total = dotProduct(vectorA,vectorB,length);

    double magnitudeA = magnitude(vectorA,length);
    double magnitudeB = magnitude(vectorB,length);

    double cosine_sim = total / (magnitudeA * magnitudeB);
    printf("Cosine similarity = %.4lf",cosine_sim);
    return 0 ;
}
