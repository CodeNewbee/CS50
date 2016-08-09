#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void) {
    float flchng;
    int change;
    int coins = 0;
    //make sure that change entered by user is a positive number
    do {
        printf("How much change is owned?\n");
        flchng = GetFloat();
    } while(flchng < 0);
    
    change = round(flchng * 100);
    //count how many coins needed to give change using 25, 10, 5 and 1 coins
    while (change > 0) {
        
        if (change >= 25) {
            change = change - 25;
            coins++;
        } 
    
        else if (change >= 10) {
            change = change - 10;
            coins++;
        }
    
        else if (change >= 5) {
            change = change - 5;
            coins++;
        }
    
        else if (change >= 1) {
            change--;
            coins++;
        }
    }
    
    printf("%i\n", coins);
}