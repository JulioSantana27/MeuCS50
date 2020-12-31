#include <stdio.h>
#include <cs50.h>
#include <math.h>

int get_cash(void); 
void min_coin(int value);

int main(void)
{
    int value = get_cash();
    min_coin(value);
}

int get_cash(void) //Prompts the user for a float value and turn it into a integer
{
    float n1;
    int n2;
    do
    {
        n1 = get_float("How much is owed? ");
    }
    while (n1 < 0);
    n2 = round(n1 * 100);
    return n2;
}

void min_coin(int value)  //Return the minimun amount of coins
{
    int n3;
    int n4;
    int total;

    total = 0;

    if (value >= 25) //In case the value is over 0.25
    {
        n3 = (value / 25);
        n4 = (value % 25);
        total = n3;
        value = n4;
    }

    if (10 <= value && value < 25) //In case the value is in between 0.25 and 0.10
    {
        n3 = (value / 10);
        n4 = (value % 10);
        total = total + n3;
        value = n4;
    }

    if (5 <= value && value < 10) // In case the value is in between 0.10 and 0.05
    {
        n3 = (value / 5);
        n4 = (value % 5);
        total = total + n3;
        value = n4;
    }

    if (0 <= value && value < 5) //In case the value is in between 0.05 and 0.01
    {
        total = value + total;
    }
    
    value = total;
    printf("%i\n", value); //Prints the minimum amount of coins
}

