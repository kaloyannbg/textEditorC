#include <stdio.h>
#include <string.h>
#include "prots.h"

int isLetter(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int isUpper(char c)
{
    return (c >= 'A' && c <= 'Z');
}

char toLower(char c)
{

    if (isUpper(c) == 1)
    {
        c = c + 32;
    }

    return c;
}

int isDigit(char c)
{
    return (c >= '0' && c <= '9');
}

void stringSymbCutter(char *string) // Only digits and letters, if letter is upper make it lower
{

    int counter = 0;

    for (int i = 0; string[i] != '\0'; i++)
    {

        if (isDigit(string[i]))
        {
            string[counter] = string[i];
            counter++;
        }
        else if (isLetter(string[i]))
        {
            string[counter] = toLower(string[i]);
            counter++;
        }
    }

    if (counter == 0)
    {
        string[counter] = '1';
        counter++;
    }

    string[counter] = '\0';
}

int checkMaxLength(char *string, int maxSize)
{

    int length = strlen(string);

    if (length > maxSize)
    {
        return 0;
    }

    return 1; // if valid size;
}

int checkMinLength(char *string, int minSize)
{

    int length = strlen(string);

    if (length < minSize)
    {
        return 0;
    }

    return 1; // if valid size;
}

void printArray(char *str, char *fileName)
{
    // printf("%s", str);

    int i = 0;

    int count = 1;

    printSpaces(3);

    printf("* You write/redact in file: \'%s.txt\' | For save file press \'0\' | Delete Previous characters with \'BackSpace\' *\n\n", fileName);

    printSpaces(3);

    printf("%d. ", count);

    while (str[i] != '\0')
    {
        printf("%c", str[i]);
        if (str[i] == '\n')
        {
            printSpaces(3);
            printf("%d. ", ++count);
        }

        i++;
    }
}

void getFileName(char *file)
{
    printHelper();
    printf("  Enter file name: ");
    scanf("%s", file);
    fflush(stdin);
}