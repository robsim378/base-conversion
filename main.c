#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <string.h>

#define MAX_INPUTS 11

int main()
{
    char baseArray[MAX_INPUTS];
    int i = 0;
    int validInput = 0;
    int x;
    long long input = 0;
    int base = 0;


    printf("Please input a base beteen base 2 and base 36.\t");
    scanf("%i", &base);

    while(base > 36 || base < 2)
    {
        printf("Invalid base selected.\t");
        base = 0;
        scanf("%i", &base);
    }
    fflush(stdin);

    printf("\nPlease input a number up to 10 digits long in your chosen base to be converted to base 10.\t");
    gets(baseArray);
    int length = strlen(baseArray);

    while(!validInput)
    {
        if(base < 11 && baseArray[i] >= '0' && baseArray[i] <= '0' + base - 1 && i < MAX_INPUTS - 1)
        {
            i++;
        }
        else if(base > 10 && i < MAX_INPUTS - 1 && baseArray[i] >= '0' && baseArray[i] <= '0' + base - 1)
        {
            i++;
        }
        else if(base > 10 && i < MAX_INPUTS - 1 && baseArray[i] >= 'a' && baseArray[i] <= 'a' + base - 11)
        {
            baseArray[i] -= 39;
            i++;
        }
        else if(base > 10 && i < MAX_INPUTS - 1 && baseArray[i] >= 'A' && baseArray[i] <= 'A' + base - 11)
        {
            baseArray[i] -= 7;
            i++;
        }
        else if(baseArray[i] == '\0')
        {
            for(i = 0; i < length; i++)
            {
                input = base * input;
                input += baseArray[i] - '0';
            }

            /*
            int convertChar;

            int y = 0;

            for(convertChar = 0 ;convertChar <  i; convertChar++)
            {
                baseArray[convertChar] = baseArray[convertChar] - '0';
            }
            for(x = i - 1; x >= 0; x--)
            {
                input += baseArray[y] * pow(base, x);
                y++;
            }
            */
            printf("\nYour number in base %i is %llu in base 10.\n",base, input);
            validInput = 1;
        }
        else
        {
            memset(baseArray, '\0', sizeof baseArray);
            printf("\nInvalid input.\t" );
            gets(baseArray);
            length = strlen(baseArray);
            i = 0;
        }
    }
}