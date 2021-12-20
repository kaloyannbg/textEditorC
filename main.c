#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include "prots.h"

int main()
{

    int menuChoice = 0;

    int cContinue = 0;

    char clearContinue = 'n';

    system("color 1B");

    do
    {
        char file[100] = "files.txt";
        system("cls");
        printMenu();
        scanf("%d", &menuChoice);

        if (menuChoice == 1)
        {
            getFileName(file);
            createNewFile(file);
        }
        else if (menuChoice == 2)
        {
            getFileName(file);
            writeInFile(file);
        }
        else if (menuChoice == 3)
        {
            getFileName(file);
            readFromFile(file);
        }
        else if (menuChoice == 4)
        {
            getFileName(file);
            readFromFile(file);
            printf("\n\n -- Are you sure to clear all content from: \'%s.txt\'? [y/n]: ", file);
            fflush(stdin); // ДА ПИТАМ ВАНКАТА УТРЕ, "ЗАЩО ТЕХНИЧЕСКИ АКО НЕ ИЗЧИСТЯ БУФЕРА, НЕ МИ РАБОТИ КОДА И ТРИЕ ФАЙЛ '1.TXT'";
            scanf("%c", &clearContinue);
            clearContentFromFile(file, clearContinue);
        }
        else if (menuChoice == 5)
        {
            getFileName(file);
            redactContentFromFile(file);
        }

        else if (menuChoice == 6)
        {
            printHelper();
            readNamesOfAllFiles(file);
        }
        else if (menuChoice == 7)
        {
            printVersionUpdates();
            printHelper();
        }
        else
        {
            printf(" ! Invalid menu choice. ! ");
        }

        printf("\n\n   -- Do you want to continue use the text editor? [y/n]: ");

        scanf("%s", &cContinue);

        if ((menuChoice == 0) || (!isContinue(cContinue)))
        {
            break;
        }

    } while (menuChoice != 0);

    return 0;
}