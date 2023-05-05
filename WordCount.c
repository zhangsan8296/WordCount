#include <stdio.h>
#include <ctype.h>

int main()
{
    FILE *fp;
    char filename[100];
    char c;
    int char_count = 0;
    int word_count = 0;
    int in_word = 0;

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return -1;
    }

    while ((c = fgetc(fp)) != EOF)
    {
        // Count characters
        char_count++;

        // Check if the character is a space, comma, or newline
        if (isspace(c) || c == ',' || c == '\n')
        {
            if (in_word)
            {
                // End of word, increment word count
                word_count++;
                in_word = 0;
            }
        }
        else
        {
            // Character is part of a word
            in_word = 1;
        }
    }

    fclose(fp);

    printf("Character count: %d\n", char_count);
    printf("Word count: %d\n", word_count);

    return 0;
