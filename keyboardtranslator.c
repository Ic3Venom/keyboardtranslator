/*
** File: keyboardtranslator.c
** Purpose: to translate a string of text from one keyboard layout to another
** Created by Julian Meyn 12/24/16
*/

#include <stdio.h>
#include <stdlib.h>

#define TOTAL_KEYS  96
#define LAYOUTS     4
#define MAX_LENGTH  64

void layoutSelect(int layoutOrder[]);
void conversion  (int layoutOrder[]);
int  dvorak      (char layout[][TOTAL_KEYS], int i);
int  qwerty      (char layout[][TOTAL_KEYS], int i);
int  colemak     (char layout[][TOTAL_KEYS], int i);
int  workman     (char layout[][TOTAL_KEYS], int i);

int main()
{
    int layoutOrder[2];

    layoutSelect(layoutOrder);
    conversion(layoutOrder);

    return 1;
}

void layoutSelect(int layoutOrder[])
{
    char userInput[MAX_LENGTH];
    char layoutSupport[LAYOUTS][8] = {"dvorak","qwerty","colemak","workman"};
    int  i, j;

    for (i = 0; i < 2;)
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
            layoutOrder[i] = 0;
            i++;
        }
        else if (strcmp(userInput, layoutSupport[1]) == 0)
        {
            layoutOrder[i] = 1;
            i++;
        }
        else if (strcmp(userInput, layoutSupport[2]) == 0)
        {
            layoutOrder[i] = 2;
            i++;
        }
        else if (strcmp(userInput, layoutSupport[3]) == 0)
        {
            layoutOrder[i] = 3;
            i++;
        }
        else if (strcmp(userInput, "help") == 0 || strcmp(userInput, "HELP") == 0)
        {
            printf("HELP MENU\nList of commands:\n");
            printf("- \"help\": displays list of available commands\n");
            printf("- \"list\": lists supported layouts\n");
            printf("- \"quit\": exits program.\n$ ");
        }
        else if (strcmp(userInput, "list") == 0 || strcmp(userInput, "LIST"))
        {
            printf("List of supported layouts:\n");

            for(j = 0; j < LAYOUTS; j++)
            {
                printf("%d: %s\n", j +1, layoutSupport[j]);
            }
        }
        else if (strcmp(userInput, "quit") == 0 || strcmp(userInput, "QUIT") == 0 || strcmp(userInput, "q") == 0)
        {
            exit(1);
        }
        else
        {
            printf("Unknown input \"%s\". Try again (type \"quit\" to leave).\n$ ", userInput);
        }
    }
}

void conversion(int layoutOrder[])
{

    char    layout[2][TOTAL_KEYS];
    char    userInput[MAX_LENGTH] = {0};
    char    translatedOutput[MAX_LENGTH];
    int     offset[2] = {25};
    int     i, j;

    printf("Place your text here:\n$ ");
    //WHY DOES THIS FIX THE PROBLEM
    getchar();
    fgets (userInput, MAX_LENGTH, stdin);

    //Puts each layout into [layout]
    for(i = 0; i < 2; i++)
    {
        switch(layoutOrder[i])
        {
        case 0:
            offset[1] = dvorak(layout, i);
            break;
        case 1:
            offset[1] = qwerty(layout, i);
            break;
        case 2:
            offset[1] = colemak(layout, i);
            break;
        case 3:
            offset[1] = workman(layout, i);
            break;
        default:
            printf("Something went wrong! Please restart the program and try again.");
            exit(-1);
        }
    }

    printf("Translated Text:\n");
    
    //The most important thing
    for(i = 0; i < MAX_LENGTH; i++)
    {

        for(j = 0; j < TOTAL_KEYS; j++)
        {

            if (userInput[i] == layout[0][j])
            {
                if (j == offset[0] || j == offset[1])
                {
                    j++;
                }

                printf("%c", layout[1][j]);
                break;
            }
        }
    }
}

int dvorak (char layout[][TOTAL_KEYS], int i)
{
    strncpy(layout[i], " 1234567890[]',.pyfgcrl/=\\aoeuidhtns-;qjkxbmwvz!@#$%^&*(){}\"<>PYFGCRL?+|AOEUIDHTNS_:QJKXBMWVZ", TOTAL_KEYS);
    return 58;
}

int qwerty (char layout[][TOTAL_KEYS], int i)
{
    strncpy(layout[i], " 1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?", TOTAL_KEYS);
    return 85;
}

int colemak(char layout[][TOTAL_KEYS], int i)
{
    strncpy(layout[i], " 1234567890-=qwfpgjluy;[]\\arstdhneio'zxcvbkm,./!@#$%^&*()_+QWFPGJLUY:{}|ARSTDHNEIO\"ZXCVBXM<>?", TOTAL_KEYS);
    return 85;
}

int workman(char layout[][TOTAL_KEYS],  int i)
{
    strncpy(layout[i], " 1234567890-=qdrwbjfup;[]\\ashtgyneoi'zxmcvkl,./!@#$%^&*()_+QDRWBJFUP:{}\ASHTGYNEOI\"ZXMCVKL<>?", TOTAL_KEYS);
    return 85;
}
