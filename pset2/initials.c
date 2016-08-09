#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    
    string name = GetString();
    short nameLength = strlen(name);
    //check if first letter needs to be capitalized, print it.
    if (name[0] > 90)
    {
        printf("%c", name[0] - 32);
    }
    else
    {
        printf("%c", name[0]);
    }
    for(int i = 0;i < nameLength; i++)
    {
        //if letter is lowercase, capitalize and print it
        if (name[i] == 32 && name[i + 1] > 90)
        {
            printf("%c", name[i + 1] -32);
        }
        //else just print it
        else if (name[i] == 32)
        {
            printf("%c", name[i + 1]);
        }
    }
    printf("\n");
}