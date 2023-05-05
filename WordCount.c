#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_WORD_LENGTH 256

int count_char(FILE *fp)
{
    int count = 0;
    char c;
    while ((c = fgetc(fp)) != EOF)
    {
        count++;
    }
    return count;
}

int count_word(FILE *fp)
{
    int count = 0;
    char word[MAX_WORD_LENGTH];
    int i, len;
    while (fscanf(fp, "%s", word) != EOF)
    {
        len = strlen(word);
        for (i = 0; i < len; i++)
        {
            if (word[i] != ',' && word[i] != ' ')
            {
                count++;
                // skip the rest of the word
                while (i < len && word[i] != ',' && word[i] != ' ')
                {
                    i++;
                }
            }
        }
    }
    return count;
}

int main(int argc, char *argv[])
{
    if (argc < 2 || argc > 3)
    {
        printf("Usage: %s [-c | -w] [input_file_name]\n", argv[0]);
        return 1;
    }

    char *mode = argv[1];
    if (strcmp(mode, "-c") != 0 && strcmp(mode, "-w") != 0)
    {
        printf("Error: invalid parameter\n");
        return 1;
    }

    char file_name[MAX_FILE_NAME_LENGTH] = "";
    if (argc == 3)
    {
        strncpy(file_name, argv[2], MAX_FILE_NAME_LENGTH);
    }
    else
    {
        printf("Please input file name: ");
        scanf("%s", file_name);
    }

    FILE *fp = fopen(file_name, "r");
    if (fp == NULL)
    {
        printf("Error: cannot open file %s\n", file_name);
        return 1;
    }

    int count;
    if (strcmp(mode, "-c") == 0)
    {
        count = count_char(fp);
        printf("×Ö·ûÊý%d\n", count);
    }
    else
    {
        count = count_word(fp);
        printf("µ¥´ÊÊý%d\n", count);
    }

    fclose(fp);
    return 0;
}