#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "userregistration.h"

typedef struct voter_information
{
    char voterid[20];
    char name[50];
    char birth_date[15];
    struct voter_information *next;
} details;

details *head;
details *space, *start = NULL;
details *search(char x[], char y[], char z[], details *, int *);
details *voter_insert(details *);
details *main_logs(details *);
void admin();
void winner();
void back();
void voting();
void not_again();
void stop();
void show();

int count = 0, R = 3, vote = 0;
int vote1 = 0, vote2 = 0, vote3 = 0, vote4 = 0, vote5 = 0;
int main()
{
    while (1)
    {

        system("cls");
        printf("\n\n\n");
        printf("\t        *************************************************************       \n\n");
        printf("\t            ****** WELCOME TO THE ONLINE VOTING PORTAL ******        \n\n");
        printf("\t            ****** SUBMITTED BY: ADARSHA POKHAREL,232004 ******        \n\n");
        printf("\t        *************************************************************       \n\n\n\n");

        printf("        \t\t *****Please Enter 1 for  main menu*****    \n\n\n");
        int BB;

        scanf("%d", &BB);
        if (BB == 1)
        {
            start = main_logs(start);
        }
    }
    return 0;
}

details *main_logs(details *start)
{
    system("cls");
    printf("\t\t\t\t****** MAIN MENU******");
    printf("\n\n\n");
    printf("        \t\t\t1. FOR REGISTRATION     \n");
   
    printf("        \t\t\t2. FOR VOTE ENTRY     \n");
    Sleep(300);
    printf("        \t\t\t3. FOR ADMIN PANEL    \n");
    Sleep(300);
    printf("        \t\t\t4. FOR WINNER         \n");

    printf("         \t\t\t0. Exit    \n\n");
    Sleep(500);
    printf("    \t\t\t ********Enter options********\n\n\n");
    int T;
    scanf("%d", &T);
    if (T == 1)
    {
        registration();
    }
    if (T == 2)
    {
        start = voter_insert(start);
    }
    if (T == 3)
    {
        admin();
    }
    if (T == 4)
    {
        winner();
    }
    if (T == 0)

        back();

    else
        main_logs(start);

    return start;
}

details *voter_insert(details *start)
{
    int UNIVERSAL = 0;
    int *z;
    z = &UNIVERSAL;
    details *temp;
    char name[50], birth_date[15], voterid[20];
    system("cls");
    printf("\n\n\n\n");
    printf("\t\t *******VOTING PORTAL******* \n\n");
    Sleep(300);
    printf("\t\t\t  THE PORTAL WILL BE CLOSED AUTOMATICALLY,IF ENTRY IS INVALID FOR %d TIMES\n\n\n", R);
    Sleep(300);
    printf("\t\tENTER YOUR REGISTERED VOTER ID \n\n");
    Sleep(300);
   
    printf("\t\t\tEnter VOTER ID   :");
    gets(voterid);
    gets(voterid); // prevents skip while fetching id
    printf("\t\t\tEnter  NAME   :");
    gets(name);
   
    printf("\t\t\tEnter pin :");
    gets(birth_date);
    temp = (details *)malloc(sizeof(details));
    strcpy(temp->voterid, voterid);
    strcpy(temp->name, name);
    strcpy(temp->birth_date, birth_date);
    temp->next = NULL;
    head = temp;
    while (temp != NULL)
    {
        // need to scan frommm file of registration
        //  FILE *fr;
        //  fr = fopen("user_data.txt", "r");

        // if (fr == NULL)
        // {
        //     printf("File does not exist");
        // }

        // int i;
        // users d[15];
        // compare with database
        // for(i=0;i<sizeof(d);i++){
        //     while(fread(&d, sizeof(d[i]), 1, fr)==1)
        //     {
        //         if(strcmp(d[i].Name,name)==0){

        //         // int x=d[i].password;
        //         // int y=pass;
        //        // if ("x"=="y"){//d[i].voter_id == votid &&  &&d[i].password==pass
        //             printf(d[i].voter_id);
        //             getch();

        //             voting();
        //         }else{
        //             printf("vayena");

        //         }
        //     }
        // }

        if (
            (strcmp(temp->voterid, "1") == 0 && strcmp(temp->name, "a") == 0 && strcmp(temp->birth_date, "1") == 0) ||
            (strcmp(temp->voterid, "2") == 0 && strcmp(temp->name, "b") == 0 && strcmp(temp->birth_date, "2") == 0) ||
            (strcmp(temp->voterid, "3") == 0 && strcmp(temp->name, "c") == 0 && strcmp(temp->birth_date, "3") == 0) ||
            // (strcmp(temp->voterid, "10004") == 0 && strcmp(temp->name, "Kundan Kumar") == 0 && strcmp(temp->birth_date, "08-12-1999") == 0) ||
            // (strcmp(temp->voterid, "10005") == 0 && strcmp(temp->name, "Hari Upreti") == 0 && strcmp(temp->birth_date, "28-08-1999") == 0) ||
            // (strcmp(temp->voterid, "10006") == 0 && strcmp(temp->name, "Dipika Singh") == 0 && strcmp(temp->birth_date, "20-10-2000") == 0) ||
            // (strcmp(temp->voterid, "10007") == 0 && strcmp(temp->name, "Avinash Kumar") == 0 && strcmp(temp->birth_date, "02-03-1999") == 0) ||
            // (strcmp(temp->voterid, "10008") == 0 && strcmp(temp->name, "Ravi Raj") == 0 && strcmp(temp->birth_date, "26-12-1999") == 0) ||
            // (strcmp(temp->voterid, "10009") == 0 && strcmp(temp->name, "Shubham Kumar") == 0 && strcmp(temp->birth_date, "02-01-1999") == 0) ||
             (strcmp(temp->voterid, "10010") == 0 && strcmp(temp->name, "NishantAcharya") == 0 && strcmp(temp->birth_date, "01-01-2000") == 0)
         )

        {
            R = 3;
            start = search(temp->voterid, temp->name, temp->birth_date, start, &UNIVERSAL);

            if (UNIVERSAL == 0)
            {
                voting();
            }
            else
            {
                not_again();
            }
        }
        else
        {
            R--;
            if (R == 0)
            {
                stop();
                break;
            }
            printf("\n\n\n\n");
            printf("\t!!!INVALID CREDENTIALS!!!\n\n");
            Sleep(300);
            printf("\t\t\t Re-Enter\n\n");
            Sleep(300);
            system("pause");
            start = main_logs(start);
        }
        temp = temp->next;
    }
    return start;
}

void voting()
{
    system("cls");
    printf("\n\n\n\n");
    printf("\t\t* * * * * * * * * * * LIST OF CANDIDATES* * * * * * * * * * * \n\n\n");
    Sleep(300);
    printf("\t\t\t NAME                          SYMBOL\n\n");
    Sleep(300);
    printf("\t\t\t 1.Candidate_1                  1.Symbol-1\n");
    Sleep(300);
    printf("\t\t\t 2.Candidate_2                  2.Symbol-2\n");
    Sleep(300);
    printf("\t\t\t 3.Candidate_3                  3.Symbol-3\n");
    Sleep(300);
    printf("\t\t\t 4.Candidate_4                  4.Symbol-4\n");
    Sleep(300);
    printf("\t\t\t 5.Candidate_5                  5.Symbol-5\n\n\n");

    int B, j;

    printf("\t\t\t Enter Your Choice \n");
    for (j = 1; j <= 1; j++)
    {
        scanf("%d", &B);

        if (B == 1)
        {
            vote1++;
            printf("\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO Candidate_1\n\t\t\t\tTIME OF VOTE:\n");
            printf(timespan());

            break;
        }
        if (B == 2)
        {
            vote2++;
            printf("\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO Candidate_2\n\t\t\t\tTIME OF VOTE:\n");
            printf("\t\t\t\t\t\t",timespan());
            break;
        }
        if (B == 3)
        {
            vote3++;
            printf("\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO Candidate_3\n\t\t\t\tTIME OF VOTE:\n");
             printf("\t\t\t\t\t\t",timespan());
            break;
        }
        if (B == 4)
        {
            vote4++;
            printf("\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO Candidate_4\n\t\t\t\tTIME OF VOTE:\n");
            printf("\t\t\t\t\t\t",timespan());
            break;
        }
        if (B == 5)
        {
            vote5++;
            printf("\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO Candidate_5\n\t\t\t\tTIME OF VOTE:\n");
            printf("\t\t\t\t\t\t",timespan());
            break;
        }
        else
        {
            printf("\n\t\t************* INVALID CHOICE ENTERED**************\t\t\n");
            printf("\n\t\t\tENTER AGAIN\t\t\t\n");
        }
    }

    printf("press any key");
    getch();
}

void admin()
{
    int B;
    printf("\n\n\n\n");
    printf("\t\t\t\t\tEnter Password To Unlock The Admin Panel\n\n");
    printf("\t\t\t Password :");
    scanf("%d", &B);
    if (B == 1234)
    {
        show();
    }
    else
    {
        printf("Wrong Password\n");
    }
}

void show()
{
    int G;
    system("cls");

    printf("\n\n\n\n");
    printf("\t\t\tPresent Vote Count as of :\n\n");
    //timespan();
    Sleep(500);
    printf("\t\t\t  Candidate_1 \n\t\t\tVote= %d\n", vote1);
    Sleep(500);
    printf("\t\t\t  Candidate_2 \n\t\t\tVote= %d\n", vote2);
    Sleep(500);
    printf("\t\t\t  Candidate_3\n\t\t\tVote= %d\n", vote3);
    Sleep(500);
    printf("\t\t\t  Candidate_4\n\t\t\tVote= %d\n", vote4);
    Sleep(500);
    printf("\t\t\t  Candidate_5\n\t\t\tVote= %d\n\n\n\n", vote5);
    Sleep(500);

    printf("\t\t\t\t\tPress 0 For Main Logs\n\n\t\t\t\t\tEnter code to terminate the voting(345)  \n ");
    scanf("%d", &G);
    if (G == 345)
        back();
    else
        main_logs(start);
}

void winner()
{
    system("cls");
    printf("\n\n\n\n");
    if (vote2 < vote1 && vote3 < vote1 && vote4 < vote1 && vote5 < vote1)
        printf("\t\t\tThe present Winner is Candidate_1\n\t\t\t received votes= %d \n\n\n\n", vote1);

    else if (vote1 < vote2 && vote3 < vote2 && vote4 < vote2 && vote5 < vote2)
        printf("\t\t\tThe present Winner is Candidate_2\n\t\t\t received votes= %d \n\n\n\n", vote2);

    else if (vote1 < vote3 && vote2 < vote3 && vote4 < vote3 && vote5 < vote3)
        printf("\t\t\tThe present Winner is Candidate_3\n\t\t\t received votes= %d \n\n\n\n", vote3);

    else if (vote1 < vote4 && vote2 < vote4 && vote3 < vote4 && vote5 < vote4)
        printf("\t\t\tThe present Winner is Candidate_4\n\t\t\t received votes= %d \n\n\n\n", vote4);

    else if (vote1 < vote5 && vote2 < vote5 && vote3 < vote5 && vote4 < vote5)
        printf("\t\t\tThe present Winner is Candidate_5\n\t\t\t received votes= %d \n\n\n\n", vote5);
    else
        printf(" \t\t\t\t!!! VOTING WILL STARTS SOON !!!\n");
    printf("\t\t\t\tPress ENTER for Main Log\n\n");
    getch();
    main_logs(start);
}

void stop()
{
    system("cls");

    printf("\n\n\n\n");
    printf("\t\t\t ( :) OOPS! YOU ENTERED WRONG CREDENTIALS FOR THREE(3) TIMES IN A ROW ) \n\n\n");
    Sleep(500);
    printf("\t\t\t!!! Please try again later!!!\n\n\n");
    Sleep(500);
    printf("\t\t\t * * *Thank You* * *  \n\n\n");
    Sleep(500);
    printf("press any key");
    getch();
}

void not_again()
{
    int A;
    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t        ***YOU HAVE GIVEN YOUR VOTE SUCCESSFULLY***       \n\n\n");
    Sleep(300);
    printf("\t\t\t        ***YOU CANNOT GIVE YOUR VOTE MORE THAN ONCE***     \n\n\n");
    Sleep(300);
    printf("\t\t\t If You want to see present winner Enter One(1) or Enter Any Other Key for Main Menu\n\n");
    Sleep(300);

    scanf("%d", &A);
    if (A == 1)
    {
        winner();
    }
    else
    {
        main_logs(start);
    }
}

void back()
{
    system("cls");

    printf("\n\n\n\n\n");
    Sleep(500);
    printf("\t\t\t        ***YOU ARE NOW EXITING THE PORTAL***       \n\n\n");
    Sleep(1000);
    printf("\t\t\t * * *Thank You For Using This ONLINE PLATFORM For VOTING* * *  \n\n\n");
    Sleep(1000);
    exit(0);
}
details *search(char x[], char y[], char z[], details *start, int *Y)
{
    *Y = 0;
    details *t, *space;
    if (start == NULL)
    {
        space = (details *)malloc(sizeof(details));
        strcpy(space->voterid, x);
        strcpy(space->name, y);
        strcpy(space->birth_date, z);

        start = space;
        space->next = NULL;
    }
    else
    {
        t = start;
        while (t != NULL)
        {
            if ((strcmp(t->voterid, x) == 0 && strcmp(t->name, y) == 0 && strcmp(t->birth_date, z) == 0))
            {
                *Y = 1;

                break;
            }
            t = t->next;
        }

        if (*Y == 0)
        {

            space = (details *)malloc(sizeof(details));

            strcpy(space->voterid, x);

            strcpy(space->name, y);

            strcpy(space->birth_date, z);
            t = space;
            space->next = NULL;
        }
    }
    return start;
}
