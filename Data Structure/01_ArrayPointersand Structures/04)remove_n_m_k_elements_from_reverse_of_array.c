/*Q. Write a program in c language to store 10 number in an array and remove first n number first time then remove
m number 2nd time then remove k number 3rd time and sum of n,m and k is less thatn the size of array-1 or equal to
 inserted data
*/
#include <stdio.h>
void remove_n_elements_from_reverse(int *array, int n);
int size = 10; // global variable store current size of array in whole program
int main()
{
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n, m, k; // to remove last l/m/n elements of array one by one
    // for (int i = 0; i < 10; i++)
    // {
    //     printf("write number %d\n", i + 1);
    //     scanf("%d", &array[i]);
    // }

    // removing elements from reverse array
    // input of n
    printf("\nwrite value of n to remove last n element of array:\n");
    scanf("%d", &n);
    if (n <= size)
        remove_n_elements_from_reverse(array, n);
    else
        printf("It's not possible to remove %d elements from reverse array. Because current size of array is %d.\n", n, size);

    // input of  m
    printf("\nwrite value of m to remove last m element of array:\n");
    scanf("%d", &m);
    if (m <= size)
        remove_n_elements_from_reverse(array, m);
    else
        printf("It's not possible to remove %d elements from reverse array. Because current size of array is %d.\n", m, size);

    // input of k
    printf("\nwrite value of k to remove last k element of array:\n");
    scanf("%d", &k);
    if (k <= size)
        remove_n_elements_from_reverse(array, k);
    else
        printf("It's not possible to remove %d elements from reverse array. Because current size of array is %d.\n", k, size);

    return 0;
}

// remove n elements from reverse array.
void remove_n_elements_from_reverse(int *array, int n)
{
    int i = size - 1; // because size changes in each call. So position last element changes.
    size -= n;
    printf("\nRemoved elements are following:\n");
    for (i; i >= size; i--)
        printf("%d  ", array[i]);

    printf("\nNew array is following:\n");
    for (int i = 0; i < size; i++)
        printf("%d  ", array[i]);
}

/*
Q provided by Anand sir  on 24th Jan 2022
*/