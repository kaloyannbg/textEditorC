#include <stdio.h>
#include <Windows.h>
#define NUMBERS_SIZE 5
#define NUMBER_TEN 10

int main()
{

    int numbers[NUMBERS_SIZE] = {0};

    for (int i = 0; i < NUMBERS_SIZE; i++)
    {
        printf(" Enter number No%d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    numbers[NUMBERS_SIZE] = 123123;  // this will broke our program , because we write out of array
    numbers[NUMBERS_SIZE + 1] = 222; // this will broke our program , because we write out of array

    system("cls");

    int len = sizeof(numbers) / sizeof(int);

    printf(" Elements in array: %d\n", len);

    for (int i = 0; i < NUMBER_TEN; i++)
    {

        printf(" Variable adress: %p ------------> ", &numbers[i]);
        printf(" Value: [%d] ", numbers[i]);
        if (i == 4)
        {
            printf(" \n\n We will get undefined results, because we print %d elements, but we have %d:: \n", NUMBER_TEN, len);
        }
        putchar('\n');
    }

    putchar('\n');

    return 0;
}