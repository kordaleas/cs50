#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>


int main(void)
{
    int letters = 0;
    int words = 0;
    int sentences = 0;

    // You may assume that a sentence will not start or end with a space,
    // and you may assume that a sentence will not have multiple spaces
    // in a row.

    string text = get_string("Text: ");
    for (int i=0; i < strlen(text); i++)
    {
        switch (text[i]){
            case '!':
                sentences++;
                break;
            case '?':
                sentences++;
                break;
            case '.':
                sentences++;
                break;
            case ',':
            case ';':
            case '\'':
            case '-':
            case '"':
                break;
            case ' ':
                words++;
                break;
            default:
                letters++;
        }



    }
    words = words + 1;
    // printf("%i", letters);
    // printf("%i", words);
    // printf("%i", sentences);

    float L = 1.0 * letters / words * 100;
    float S = 1.0 * sentences / words * 100;

    int Coleman_Liau_index;
    int idx = Coleman_Liau_index = round(0.0588 * L - 0.296 * S - 15.8);

    if (idx >= 16) {
        printf("Grade 16+\n");
    }
    else if (idx < 1) {
        printf("Before Grade 1\n");
    }
    else {
        printf("Grade %i\n", idx);
    }


}