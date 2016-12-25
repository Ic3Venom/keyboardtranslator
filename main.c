#include <stdio.h>
#include <stdlib.h>

// Purpose: to translate a string of text from one keyboard layout to another
// Created by Julian Meyn 12/24/16

void dvorak();
void qwerty();
void colemak();
void workman();

int main()
{
    char layout[10];
    char layoutSupport[4][8] = {"dvorak","qwerty","colemak","workman"};

    printf("%s %s %s %s", layoutSupport[0], layoutSupport[1], layoutSupport[2], layoutSupport[3]);
    printf("Hello! What layout is your text in? Use lowercase font and only use the first noteable word in the layout's name\n$ ");

    while(scanf("%s", layout))
    {
        if(strcmp(layout, layoutSupport[0]) == 0)
        {
            dvorak();
            break;
        }
        else if (strcmp(layout, layoutSupport[1]) == 0)
        {
            qwerty();
            break;
        }
        else if (strcmp(layout, layoutSupport[2]) == 0)
        {
            colemak();
            break;
        }
        else if (strcmp(layout, layoutSupport[3]) == 0)
        {
            workman();
            break;
        }
        else
        {
            printf("What you typed did not fit any of our supported keyboard layouts! Try again\n$ ");
        }
    }
    return 0;
}

void dvorak()
{

}

void qwerty()
{

}

void colemak()
{

}

void workman()
{

}
