#include <stdio.h>
#include "prots.h"

void printMenu()
{
    char notePadSymb = 178;

    char squareSymb = 254;

    putchar('\n');

    printf("  %c Text editor by Kaloyan Angelov v2.0.0 %c\n\n", notePadSymb, notePadSymb);
    printSpaces(3);
    printf("1. New File  2. Open file ONLY for writing  3. Open file READ ONLY");
    printf("  4. Clear content of existing file 5. Redact Content From File  \n");
    printSpaces(3);
    printf("6. All saved files 7. READ ME \n");

    printf("\n  Enter menu choice: ");
}

void printHelper()
{
    printf("\n * By default editor work only with .txt files, don\'t write an extension after filename! *\n\n");
}

void printChoicesForExt()
{
    printf("\n * You can choose 2 extensions. \'.txt\' and \'.c\' \n\n");

    printf("   -- Please, enter 1 for \'.txt\' \n");
    printf("   -- Please, enter 2 for \'.c\' \n");
    putchar('\n');
    printf("  -- Enter your choice: ");
}

void printVersionUpdates()
{
    printf("\n * version: v1.0.0 *\n");
    printf("     1. CREATE FILE , 2. WRITING IN FILE, 3. READ ONLY IN FILE \n");
    printf("\n * version: v2.0.0 *\n");
    printf("     1. CREATE STRING FUNCTIONS\n");
    printf("     2. CHECKS LENGTH, AND REMOVE ALL SYMBOLS FROM NAMES OF FILES\n");
    printf("     3. ADD README\n");
    printf("     4, ADD FUNCTION FOR READ+CLEAR CONTENT FROM FILE. \n");
}