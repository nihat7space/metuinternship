// Nihat Oksuz 2638039
// Dear Hocam,In this code, argument argc, and argv[] are used. Please do not forget to add the arguments when running the code.
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

struct Intershp
{
    char name[100];
    char surname[100];
    int depcode;
    int semester;
    float score;
};

char computeLetterGrade(float score) // Function to compute letter grade based on score
{
    if (score >= 70.0) {
        return 'S';
    } else {
        return 'U';
    }
}
void Load_InternshipDataTable(struct Intershp **table ,char *filename,int *size) // Function to load internship data from a file into an array of structures
{
    FILE *file = fopen(filename,"r");
    if(file==NULL)
    {
        printf("Eror while reading! \n");
        exit(1);
    }
    fscanf(file," %*s %*s %*s %*s %*s"); // Skip the file header
    int capacity = 10 ;
    *table = (struct Intershp *) malloc(capacity * sizeof(struct Intershp));
    while(fscanf(file,"%s %s %d %d %f",(*table)[*size].name,(*table)[*size].surname,&(*table)[*size].depcode,&(*table)[*size].semester,&(*table)[*size].score)!=EOF)
    {
        (*size)++;
        if(*size>=capacity)
        {
            capacity = capacity + 1;
            *table = (struct Intershp *) realloc(*table,capacity * sizeof(struct Intershp));
        }
    }
    fclose(file);
}
void Display_InternshipDataTable(struct Intershp *table,int size) // Function to display the internship data table
{
    if(size==0)
    {
        printf("No records!");
        return;
    }
    printf("name surname departmentCode semester score letterGrade\n");
    for(int i=0;i<size;i++)
    {
        char lettergrade = computeLetterGrade(table[i].score);
        printf("%s %s %d %d %.1f %c \n",table[i].name,table[i].surname,table[i].depcode,table[i].semester,table[i].score,lettergrade);

    }
}
int Search(struct Intershp *table,int size,char *getname) // Function to search for a student by name or surname
{
    for(int i=0;i<size;i++)
    {
        if(strcmp(table[i].name,getname)==0 || strcmp(table[i].surname,getname)==0)
        {
            return i;
        }
    }
    return -1;
}
void Sort(struct Intershp *table,int size) // Function to sort the internship data table by score or letter grade
{
    int option;
    do  // To ask the user to choose the sorting criteria
    {
        printf("Which column (1: score, 2: letter grade)?: ");
        scanf("%d",&option);
        if (option != 1 && option != 2)
        {
            printf("Invalid choice!\n");
        }
    }while (option != 1 && option != 2);

    for(int i=0;i<size-1;i++)  //bubble sort
    {
        for(int j=0;j<size-1-i;j++)
        {
            if(option==1)
            {
                if(table[j].score>table[j+1].score)
                {
                    struct Intershp temp = table[j];
                    table[j] = table[j+1];
                    table[j+1] = temp;
                }
            }
            else if(option==2)
            {
                char grade1 = computeLetterGrade(table[j].score);
                char grade2 = computeLetterGrade(table[j + 1].score);
                if (grade1 > grade2)
                {
                    struct Intershp temp = table[j];
                    table[j] = table[j + 1];
                    table[j + 1] = temp;
                }
            }
            else
            {
                printf("Invalid choice \n");
                return;
            }
        }
    }
}
void statistics(struct Intershp *table,int size)  // Function to calculate and display statistics about pass/fail rates
{
    int pass = 0,fail = 0;
    int pasdep[4] = {0,0,0,0};
    int faildep[4] = {0,0,0,0};
    int departman[] = {355,356,365,384};

    for(int i=0;i<size;i++) // Calculate the number of students who passed and failed
    {
        char grade = computeLetterGrade(table[i].score);
        if(grade == 'S')
        {
            pass++;
            for(int j=0;j<4;j++)
            {
                if(table[i].depcode == departman[j])
                {
                    pasdep[j]++;
                    break;
                }
            }
        }
        else
        {
            fail++;
            for(int m=0;m<4;m++)
            {
                if(table[m].depcode==departman[m])
                {
                    faildep[m]++;
                    break;
                }
            }
        }
    }
    printf("Oveall: %d student(s) passed and %d student(s) failed! \n",pass,fail);
    for(int l=0;l<4;l++)
    {
        printf("Department: %d, %d student(s) passed and %d student(s) failed!\n",departman[l],pasdep[l],faildep[l]);
    }
}
int main(int argc,char *argv[])
{
    int size=0;
    if(argc!=2)
    {
        printf("Usage: %s <data file>\n", argv[0]);
        return 1;
    }
    struct Intershp *table = 0;

    Load_InternshipDataTable(&table,argv[1],&size);   // Load the internship data

    printf("The student records file (%s) has been successfully loaded!\n",argv[1]);

    Display_InternshipDataTable(table,size);   // Display the loaded internship data

    int choice;

    do
    {
        // Display the menu options
        printf("What would you like to do?\n");
        printf("1-search\n");
        printf("2-sort\n");
        printf("3-statistics\n");
        printf("4-exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                char name[100];
                printf("Please enter the name of student: ");
                scanf("%s",name);
                int index = Search(table,size,name);
                if(index != -1)
                {
                    // Display the student's information if found
                    printf("name: %s\nsurname: %s\ndepartment code: %d\nsemester: %d\nscore: %.1f\ngrade: %c\n",
                           table[index].name,table[index].surname,table[index].depcode,table[index].semester,table[index].score,
                           computeLetterGrade(table[index].score));
                }
                else
                {
                    printf("This student is not in our records!\n");
                }
                break;
            case 2:
                Sort(table,size);
                Display_InternshipDataTable(table,size);
                break;
            case 3:
                statistics(table,size);
                break;
            case 4:
                printf("Exiting the program\n");
                break;
            default:
                printf("Wrong input!.\n");
                break;
        }
    } while (choice!=4);
    free(table);  // Free the allocated memory
    return 0;
}