#include <stdio.h>
int main()
{
    int number[10];
    for (int i = 0; i < 10; i++)
    {
        printf("write number %d\n", i + 1);
        scanf("%d", &number[i]);
    }
    printf("\nMiddle elements: %d And %d\n", number[4], number[5]); // index=4 is 5th element and index=5 is 6th element
    return 0;
}
/*
In case of even size of array: middle elements = element at index size/2 and (size+2)/2
In case of odd size of array: middle element = element at index size/2 only
*/