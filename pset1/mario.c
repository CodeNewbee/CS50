#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do {
        printf("Height: ");
        height = GetInt();
    } while(height < 0 || height > 23);
    
    int length = 2;
    int totalLength = height + 1;
    for(int i = 0; i < height; i++)
    {
        
        for(int z = 0; z < totalLength - length; z++){
            printf(" ");
        }
        
        for(int k = 0; k < length; length--) {
            printf("#");
        }
        
        length = i + 3;
        printf("\n");
    }
}