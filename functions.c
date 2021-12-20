#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#include "prots.h"

FILE *fp;

char Path[] = "TXT_FILES/";

char extension[] = ".txt";

char fileContent[10000] = {0};

void readNamesOfAllFiles(char *file)
{

    if (!isFileExist(file))
    {
        printSpaces(3);
        printf("This file dont exist");
        return;
    }

    fp = fopen(file, "r");

    char c = 0;

    int newLineCount = 1;

    system("cls");

    printSpaces(3);
    printf("%d. ", newLineCount);
    while (c != EOF)
    {
        c = fgetc(fp);

        putchar(c);

        if (c == '\r' || c == '\n')
        {
            printSpaces(3);
            printf("%d. ", ++newLineCount);
        }
    }

    fclose(fp);
}

void redactContentFromFile(char *file)
{
    char filesPathForRedact[200];

    strcpy(filesPathForRedact, Path);

    strcat(filesPathForRedact, file);

    strcat(filesPathForRedact, extension);

    if (!isFileExist(filesPathForRedact))
    {
        printSpaces(3);
        printf("File dont exist.");
    }
    else if (isFileExist(filesPathForRedact))
    {

        memset(fileContent, 0, 10000);

        fp = fopen(filesPathForRedact, "r");

        char c = 0;

        int symbCount = 0;

        while (c != EOF)
        {
            c = fgetc(fp);
            fileContent[symbCount] = c;
            symbCount++;
        }

        fileContent[symbCount] = '\0';

        fclose(fp);

        int size = symbCount - 1; // we dont think about for termination zero '\0' with this code

        int i = 0;

        char checkForKey = 0;

        int keyNum = 0;

        system("cls");
        printArray(fileContent, file);

        while (checkForKey != '0')
        {

            checkForKey = getch();

            if (checkForKey == '0')
            {
                break;
            }
            if (checkForKey == 0 || checkForKey == 'p') {
                checkForKey = getch();
                if(checkForKey == 'M' || checkForKey == 77 || checkForKey == 72 || checkForKey == 75 || checkForKey == 80) {
                    system("cls");
                    printf("Arrows is disabled. Enter key for refresh!");
                }
            }
            else if (checkForKey == ' ' && fileContent[size - 1] == ' ')
            {
                system("cls");
                fileContent[--size] = '\0';
                printArray(fileContent, file);
            }
            else if (checkForKey == 8)
            {
                system("cls");
                if (size != 0)
                {
                    fileContent[--size] = '\0';
                    printArray(fileContent, file);
                }
                else if (size == 0)
                {
                    printArray(fileContent, file);
                }
            }
            else if (checkForKey == '\r') // carriage return \n is the new line character (0x0A) or 10 decimal, \r is the carrige return character (0x0D) or 13 decimal.
            {
                system("cls");
                fileContent[size] = '\n';
                fileContent[size + 1] = '\0';
                printArray(fileContent, file);
                size++;
            }
            else if (checkForKey != 8)
            {
                system("cls");
                fileContent[size] = checkForKey;
                fileContent[size + 1] = '\0';
                printArray(fileContent, file);
                size++;
            }
        }

        char choice = 0;

        printf("\n -- Do you want to save this content in current file? [y/n]: ");

        fflush(stdin);

        scanf("%c", &choice);

        if (choice == 'n')
        {
            printf("\n\n -- Okay! :) -- \n\n");
        }
        else if (choice == 'y')
        {
            printf("\n \'%s.txt\' is saved! ", file);
            fp = fopen(filesPathForRedact, "w");
            fwrite(fileContent, sizeof(char), size, fp);
            fclose(fp);
        }
    }
}

void clearContentFromFile(char file[], char cChoice)
{
    char filesPathClear[200];

    strcpy(filesPathClear, Path);

    strcat(filesPathClear, file);

    strcat(filesPathClear, extension);

    if (isFileExist(filesPathClear))
    {
        // printf("\n\n -- Are you sure to clear all content from: \'%s.txt\'? [y/n]: ", file); <--- ЧАСТ ОТ ДОЛНИЯ ВЪПРОС
        // scanf("%s", &c);  <--- ЧАСТ ОТ ДОЛНИЯ ВЪПРОС
        // СЛЕД ТОВА НАПРАВИХ ФУНКЦИЯТА ДА ПРИЕМА ВТОРИ АРГУМЕНТ (char cChoice) И ПО ТОЗИ НАЧИН НЕ РАБОТЕШЕ, ОБАЧЕ СЛЕД ФФЛЪШ ПРОРАБОТИ
        if (cChoice == 'n' || cChoice == 'N')
        {
            printf("  -- File is saved, you choose %c -- ", cChoice);
        }
        else if (cChoice == 'y' || cChoice == 'Y')
        {
            //  strcpy(filesPathClear, Path);

            //  strcat(filesPathClear, file);

            //  strcat(filesPathClear, extension);

            //  ДА ПИТАМ ВАНКАТА УТРЕ : "ЗАЩО ЧИСТО ТЕХНИЧЕСКИ КАТО БЯХ ВКАРАЛ SCANF- А ВЪВ ФУНКЦИЯТА, СЕ НАЛАГАШЕ ДА ПРЕЗАПИСВАМ"
            //  ЦЕЛИЯ МАСИВ ВЪВ ИФ-А, РАЗБИРА СЕ, НЕ ТРИЕХ С ФФЛУШ БУФЕРНАТА ПАМЕТ.
            //  МЪЧИХ СЕ 1 ЧАС ДА ГО ОПРАВЯ, ДАНО НЕ ЗАБРАВЯ ДА ПИТАМ.

            fp = fopen(filesPathClear, "w");
            fclose(fp);
            printf("  -- The file \'%s.txt\' is clear now. -- ", file);
        }
        else
        {
            printf("  -- Your choice is invalid. -- ");
        }
    }
}

void readFromFile(char file[])
{
    stringSymbCutter(file);

    char filesPathRead[200];

    strcpy(filesPathRead, Path);

    strcat(filesPathRead, file);

    strcat(filesPathRead, extension);

    if (!isFileExist(filesPathRead))
    {
        printf(" *Sorry, the file: %s don\'t exist. You can create it. *", file);
    }
    else if (isFileExist(filesPathRead))
    {
        char c = 0;

        printf("\n     * You read content at file \'%s.txt\' * \n", file);

        int countLine = 0;

        fp = fopen(filesPathRead, "r");

        printf("  %d  ", ++countLine);

        while (c != EOF)
        {
            if (c == '\n')
            {
                printf("  %d  ", ++countLine);
            }

            c = fgetc(fp);

            if (c != '+')
            {
                putchar(c);
            }
        }
        fclose(fp);
    }
}

void writeInFile(char file[])
{
    stringSymbCutter(file);

    char filesPath[200];

    strcpy(filesPath, Path);

    strcat(filesPath, file);

    strcat(filesPath, extension);

    if (!isFileExist(filesPath))
    {
        printSpaces(3);
        printf("Sorry, the file: %s don\'t exist. You can create it.", file);
    }
    else if (isFileExist(filesPath))
    {
        char c = 0;
        printSpaces(3);

        printf(" For close and save the file enter \'+\' and enter \n\n");

        int countLine = 0;

        c = 0;

        printf("  %d  ", ++countLine);

        while (c != '+')
        {

            if (c == '\n')
            {
                printf("  %d  ", ++countLine);
            }
            fp = fopen(filesPath, "a+");

            c = getchar();

            fputc(c, fp);

            fclose(fp);
        }
    }
}

void createNewFile(char file[])
{
    // only will work with .txt files!

    stringSymbCutter(file);

    if (!checkMaxLength(file, 20))
    {
        printf(" * Your file is not created! *\n");
        printf(" * REASON: File can be maximum 20 chars! *");
        return;
    }
    else if (!checkMinLength(file, 4))
    {
        printf(" * Your file is not created! *\n");
        printf(" * REASON: File can be minimum 4 chars! *");
        return;
    }

    char filesPath[200];

    strcpy(filesPath, Path);

    strcat(filesPath, file);

    strcat(filesPath, extension);

    if (isFileExist(filesPath))
    {
        printf(" * Sorry, the file: \'%s.txt\' exist. You can choose other name. *\n", file);
    }
    else if (!isFileExist(filesPath))
    {
        fp = fopen(filesPath, "w");
        fclose(fp);
        printf(" *Your file \'%s.txt\' is created. *", file);

        char saveNameOfFile[] = "files.txt";
        fp = fopen(saveNameOfFile, "r");
        char c = fgetc(fp);
        int notEmpty = 0;

        if (c != EOF)
        {
            notEmpty = 1;
        }
        fclose(fp);

        fp = fopen(saveNameOfFile, "a+");
        if (notEmpty)
        {
            fputc('\n', fp);
        }
        fwrite(filesPath, sizeof(char), strlen(filesPath), fp);
        fclose(fp);
    }
}

int isFileExist(char file[])
{
    fp = fopen(file, "r");

    if (!fp)
    {
        fclose(fp);
        return 0;
    }
    else
    {
        fclose(fp);
        return 1;
    }
}

int isContinue(char c)
{

    if (c == 'n' || c == 'N')
    {
        return 0;
    }

    return 1;
}