#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include "randomnumgenerator.h"

struct user_details
{
    char Name[20];
    int DOB;
    int citizenship_number;
    char District[15];
    char Local_level_Government[20];
    int Ward_no;
    char Village[25];
    int voter_id;
    int password;
};

typedef struct user_details users;

int registration()
{
    int random_number, i;
    system("cls");
    printf("\t\t\t USER REGISTRATION\n\n");
    printf("\t\t\t\t",timespan());

    // while(1){
    //     system("cls");
    //     timespan();
        
    // }
    FILE *fp;
    fp = fopen("user_data.txt", "a+");

    users u[15];

    for (i = 0; i < 15; i++)
    {
        printf("\n");
        printf("Enter name :");
        scanf("%s", &u[i].Name);
        // gets(u[i].Name);
        // gets(u[i].Name);

        printf("Enter date of birth in year: ");
        scanf("%d", &u[i].DOB);

        printf("Enter citizenship number: ");
        scanf("%d", &u[i].citizenship_number);

        printf("Enter your district: ");
        // gets(u[i].District);
        scanf("%s", &u[i].District);

        printf("Enter local government: ");
        // gets(u[i].Local_level_Government);
        scanf("%s", &u[i].Local_level_Government);

        printf("Enter ward no: ");
        scanf("%d", &u[i].Ward_no);

        printf("Enter village: ");
        scanf("%s", &u[i].Village);

        // if age>18 then store data
           time_t t = time(NULL);
         struct tm tm = *localtime(&t);
         
        if (tm.tm_year + 1900 - u[i].DOB >= 18)
        {
            int voter_id = token();
            fprintf(fp, "\n\nName = %s", u[i].Name);
            fprintf(fp, "\nDate of birth = %d ", u[i].DOB);
            fprintf(fp, "\ncitizenship no = %d", u[i].citizenship_number);
            fprintf(fp, "\nDistrict = %s ", u[i].District);
            fprintf(fp, "\nlocalgovernment = %s ", u[i].Local_level_Government);
            fprintf(fp, "\nWard no = %d ", u[i].Ward_no);
            fprintf(fp, "\nvillage = %s ", u[i].Village);

            fprintf(fp, "\nvoter_id = %d", u[i].voter_id);

            printf("\n\t\t !!!!your voter id is = %d\n \t\tPlease keep it safe for further use\n\n", u[i].voter_id);
            printf("\n\t\t******** User information registered ********\n");

            Sleep(500);
            printf("\n\t !!!Please proceed to setup your login details.!!!");

            printf("\n\n login id: %d", u[i].voter_id);
            printf("\n  Enter pin number: ");
            scanf("%d", &u[i].password);
            fprintf(fp, "\npin = %d\n", u[i].password);

            // fwrite(&u,sizeof(u),1,fp);

            printf("\n\t\t******** User registration completed ********\n");
            printf("\n\t\t******** Please login to continue. ********\n");
            exit(1);
        }
        else
        {
            printf("\n\n!!!!!!you are not eligible for registeration!!!!");
            printf("\n\n!!!!!!User must be 18 to be eligible for registration!!!!");
            exit(1);
        }
    }
}
int timespan(){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("\t\t\tDate: %d-%02d-%02d\n\t\t\tTime: %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    return 0;
}