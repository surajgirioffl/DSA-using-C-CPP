#include <stdio.h>
int main()
{
    int array[10];
    for (int i = 0; i < 10; i++)
    {
        printf("Enter Number %d:\n", i + 1);
        scanf("%d", &array[i]);
    }

    printf("\nReverse Array is following:\n");
    for (int i = 9; i >= 0; i--)
        printf("%d  ", array[i]);
    return 0;
}