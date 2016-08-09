#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    
    if(argc != 2)
    {
        printf("You failed to provide valid key\n");
        return 1;
    }
    
    string keyphrase = argv[1];
    short keylen = strlen(keyphrase);
    short keyindex = 0;
    int key;
    //check if keyphrase has only alphabetic characters
    for (int z = 0; z < keylen; z++)
    {
        if (isalpha(keyphrase[z]) == 0)
        {
            printf("You failed to provide valid key\n");
            return 1;
        }
    }
    
    string plaintext = GetString();
    short len = strlen(plaintext);
    
    for (int i = 0; i < len; i++)
    {
        //if reached the end of keyphrase, reset index
        if (keyindex == keylen)
        {
            keyindex = 0;
        }
        //if key char is uppercase
        if (keyphrase[keyindex] >= 65 && keyphrase[keyindex] <= 90)
        {
            key = keyphrase[keyindex] - 65;
        }
        //if key char is lowercase
        else if (keyphrase[keyindex] >= 97 && keyphrase[keyindex] <= 122)
        {
            key = keyphrase[keyindex] - 97;
        }
        //if plaintext is uppercase
        if (plaintext[i] >= 65 && plaintext[i] <= 90)
        {
            int pos = plaintext[i] - 64;
            pos = (key + pos) % 26;
            //if pos is 0, outputed char has to be z 
            if (pos == 0)
            {
                printf("%c", 90);
            }
            else
            {
                printf("%c", pos + 64);
            }
            keyindex++;
        }
        //if plaintext is lowercase.
        else if (plaintext[i] >= 97 && plaintext[i] <= 122)
        {
            int pos = plaintext[i] - 96;
            pos = (key + pos) % 26;
            if (pos == 0)
            {
                printf("%c", 122);
            }
            else
            {
                printf("%c", pos + 96);
            }
            keyindex++;
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;
}