#include <stdio.h>
#include <cs50.h>

int main(void) {
    
    printf("Type in the length of your shower time\n");
    int time = GetInt();
    printf("minutes: %i\n", time);
    printf("bottles: %i\n", time * 12);
}