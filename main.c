#include <stdio.h>
#include <stdlib.h>
#define KEYS    46
#define LAYOUTS 4
#define LENGTH  100

// Purpose: to translate a string of text from one keyboard layout to another
// Created by Julian Meyn 12/24/16

void layoutSelect(int layoutOrder[]);
void conversion  (int layoutOrder[]);
void dvorak      (char layout[][46], int i);
void qwerty      (char layout[][46], int i);
void colemak     (char layout[][46], int i);
void workman     (char layout[][46], int i);

int main()
{
    int layoutOrder[2];
    layoutSelect(layoutOrder);

    printf("%d %d", layoutOrder[0], layoutOrder[1]);

    conversion(layoutOrder);

    return 0;
}

void layoutSelect(int layoutOrder[])
{
    char userInput[10];
    char layoutSupport[LAYOUTS][8] = {"dvorak","qwerty","colemak","workman"};
    int  i;

    for (i= 0; i < 2;)
    {
        if (i == 1)
        {
            printf("What layout do you want the text translated to?\n$ ");
        }
        else
        {
            printf("Hello! What layout is your text in? Type \"help\" to learn more.\n$ ");
        }
        scanf("%s", userInput);

        if(strcmp(userInput, layoutSupport[0]) == 0)
        {
            layoutOrder[i]= 0;
            i++;
        }
        else if (strcmp(userInput, layoutSupport[1]) == 0)
        {
            layoutOrder[i]= 1;
            i++;
        }
        else if (strcmp(userInput, layoutSupport[2]) == 0)
        {
            layoutOrder[i]= 2;
            i++;
        }
        else if (strcmp(userInput, layoutSupport[3]) == 0)
        {
            layoutOrder[i]= 3;
            i++;
        }
        else if (strcmp(userInput, "help") == 0)
        {
            printf("HELP MENU\nList of commands:\n");
            printf("- \"help\": displays list of available commands\n");
            printf("- \"list\": lists supported layouts\n");
            printf("- \"quit\": exits program.\n$ ");
        }
        else if (strcmp(userInput, "list") == 0)
        {
            int j;

            printf("List of supported layouts:\n");
            for(j= 0; j < LAYOUTS; j++)
            {
                printf("%d: %s\n", j +1, layoutSupport[j]);
            }
        }
        else if (strcmp(userInput, "quit") == 0)
        {
            exit(1);
        }
        else
        {
            printf("Unknown input \"%s\". Try again (type \"quit\" to leave).\n$ ", userInput);
        }
    }

    //Probably don't need this anymore
    /*switch(layoutOrder[0])
    {
    case 0:
        dvorak(layoutOrder[1]);
    case 1:
        qwerty(layoutOrder[1]);
    case 2:
        colemak(layoutOrder[1]);
    case 3:
        workman(layoutOrder[1]);
    default:
        printf("Something went wrong! Please close and restart the program.");
        exit(404);
    }*/
}

void conversion(int layoutOrder[])
{

    char  layout[2][KEYS];
    char  userInput[LENGTH];

    //Puts each layout into [layout]
    {
        int   i;
        for(i= 0; i < 2; i++)
        {
            switch(layoutOrder[i])
            {
            case 0:
                dvorak(layout, i);
            case 1:
                qwerty(layout, i);
            case 2:
                colemak(layout, i);
            case 3:
                workman(layout, i);
            }
        }
    }
    
    //Debug
    printf("Place your text here:\n$ ");
    scanf("%s", &userInput);
    printf("%s", userInput);
}

void dvorak (char layout[][46], int i)
{
    strncpy(layout[i], "1234567890[]',.pyfgcrl/=aoeuidhtns-;qjkxbmwvz", KEYS);
}

void qwerty (char layout[][46], int i)
{
    strncpy(layout[i], "1234567890-=qwertyuiop[]asdfghjkl;'zxcvbnm,./", KEYS);
}

void colemak(char layout[][46], int i)
{
    strncpy(layout[i], "1234567890-=qwfpgjluy;{}arstdhneio'zxcvbkm,./", KEYS);
}

void workman(char layout[][46], int i)
{
    strncpy(layout[i], "1234567890-=qdrwbjfup;{}ashtgyneoi'zxmcvkl,./", KEYS);
}
