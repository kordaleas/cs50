#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

bool validate_key(string key);

void encrypt(string plaintext, int key);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string key_string = argv[1];
        bool key_is_gtp = validate_key(key_string);
        if (key_is_gtp)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        int key = atoi(key_string);
        string user_input = get_string("plaintext: ");
        encrypt(user_input, key);
        // printf("cyphertext: %s", output);
        printf("\n");
        return 0;
    }
    else
    {
        printf("Wrong number of arguments!\n");
        return 1;
    }
};

bool validate_key(string key)
{
    for (int j = 0, n = strlen(key); j < n; j++)
    {
        if (!isdigit(key[j]))
        {
            return true;
        }

    }
    return false;
};

void encrypt(string plaintext, int key)
{
    char ciphertext[strlen(plaintext)];
    ciphertext[strlen(plaintext)] = '\0';
    string LOWER = "abcdefghijklmnopqrstuvwxyz";
    string UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int j = 0, n = strlen(plaintext); j < n; j++)
    {
        if (isalpha(plaintext[j]))
        {
            if (islower(plaintext[j]))
            {
                int idx = (plaintext[j] - 97 + key) % 26;
                //   printf("skata7 %i", plaintext[j] - 97);
                //   printf("%s\n", &LOWER[idx]);
                //   printf("%c\n", LOWER[idx]);
                // try me  printf("%c\n", &LOWER[idx]);
                ciphertext[j] = LOWER[idx];

            }
            else if (isupper(plaintext[j]))
            {
                int idx = (plaintext[j] - 65 + key) % 26;
                //   printf("skata7 %i", plaintext[j] - 65);
                //   printf("%s\n", &LOWER[idx]);
                //   printf("%c\n", LOWER[idx]);
                // try me  printf("%c\n", &LOWER[idx]);
                ciphertext[j] = UPPER[idx];
            }

        }
        else
        {
            ciphertext[j] = plaintext[j];
        }

    }
    printf("ciphertext: %s", ciphertext);

};
