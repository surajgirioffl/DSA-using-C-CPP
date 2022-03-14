#include <stdio.h>
int main()
{
    int array[10];
    for (int i = 0; i < 10; i++)
    {
        printf("Enter Number %d:\n", i + 1);
        scanf("%d", &array[i]);
    }

    int index;
    int size = 10;
    printf("Enter array index to delete element:\n");
    scanf("%d", &index);

    for (int i = 0; i < size; i++)
    {
        if (i == index)
        {
            for (int j = i; j < size; j++)
                array[j] = array[j + 1];
            size--;
        }
    }

    printf("New array is following:\n");
    for (int i = 0; i < size; i++)
        printf("%d  ", array[i]);

    return 0;
}
