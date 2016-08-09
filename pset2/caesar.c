#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    
    if(argc != 2)
    {
        printf("You failed to provide key\n");
        return 1;
    }
    
    string plaintext = GetString();
    
    int key = atoi(argv[1]);
    short len = strlen(plaintext);
    
    for (int i = 0; i < len; i++)
    {
        if (plaintext[i] >= 65 && plaintext[i] <= 90)
        {
            int pos = plaintext[i] - 64;
            pos = (key + pos) % 26;
            printf("%c", pos + 64);
        }
        else if (plaintext[i] >= 97 && plaintext[i] <= 122)
        {
            int pos = plaintext[i] - 96;
            pos = (key + pos) % 26;
            printf("%c", pos + 96);
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;
}