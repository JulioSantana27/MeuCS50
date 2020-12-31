#include <cs50.h>
#include <stdio.h>

void print(int height);
int get_height(void);

int main(void) //Main
{
    int height = get_height();
    print(height);
}

int get_height(void) //Prompt the user for the height of the pyramid
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8); //Condition to limit the height from 1 to 8
    return n;
}

void print(int height) //Prints the hashes
{
    for (int i = 0; i < height; i++)
    {
        for (int k = i + 1; k < height; k++) //Loop to print spaces
        {
            printf(" ");
        }

        for (int j = height - i; j < 1 + height; j++) //Loop to print hashes
        {
            printf("#");
        }
        printf("\n");
    }
}