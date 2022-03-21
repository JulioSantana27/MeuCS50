#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if ( ! isdigit(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

        string text = get_string("Plaintext: ");

        int key = atoi(argv[1]);
        if (key > 26)
        {
            key = key % 26;
        }

        printf("Ciphertext: ");

        for (int i = 0, n = strlen(text); i < n; i++)
        {
            if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
            {
                if ((text[i] + key > 'z') || (text[i] + key > 'Z' && text[i] + key < '`'))
                {
                    printf("%c", text[i] + key - 26);
                }
                else
                {
                    printf("%c", text[i] + key);
                }
            }

            else
            {
                printf("%c", text[i]);
            }

        }
        printf("\n");
    }

    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}




