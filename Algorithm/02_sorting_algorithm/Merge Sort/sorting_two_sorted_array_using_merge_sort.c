/*
 *sorting two sorted arrays using merge sort
 *using c language
 */

#include <stdio.h>
#include <stdlib.h>

void mergeSort(int *array1, int *array2, int *mergedArray, int size1, int size2)
{
    int i = 0; // for iteration of sorted array1
    int j = 0; // for iteration of sorted array2
    int k = 0; // for iteration of merged array

    while (i < size1 && j < size2)
    {
        if (array1[i] < array2[j])
            mergedArray[k++] = array1[i++];
        else
            mergedArray[k++] = array2[j++];
    }

    /*
     *if above loop terminates due to fail of any one condition, then
     *it means one array have less size than another
     * so we put left elements in the mergedArray because they will already sorted
     *
     * if both condition satisfied at same time in above loop, it means size of both array are same.
     * so, the condition of both loop will be not satisfied.
     */

    while (i < size1)
        mergedArray[k++] = array1[i++];
    // if above condition not satisfied then below will work

    while (j < size2)
        mergedArray[k++] == array2[j++];
}

void inputArray(int *array, int size)
{
    puts("write elements of sorted array properly:");
    for (int i = 0; i < size; i++)
    {
        printf("write element of index %d: ", i);
        scanf("%d", &array[i]);
    }
}

int main()
{
    system("cls");
    // for sorted array1
    int size1 = 0;
    puts("write the size of sorted array1: ");
    scanf("%d", &size1);
    int *array1 = (int *)calloc(size1, sizeof(int));
    inputArray(array1, size1);

    // for sorted array2
    int size2 = 0;
    puts("write the size of sorted array2: ");
    scanf("%d", &size2);
    int *array2 = (int *)calloc(size2, sizeof(int));
    inputArray(array2, size2);

    // for merged array
    int *mergedArray = (int *)calloc(size1 + size2, sizeof(int));

    mergeSort(array1, array2, mergedArray, size1, size2); // for perform merged sort

    // displaying the merged array
    puts("Merged sorted array is following:");
    for (int i = 0; i < size1 + size2; i++)
        printf("%d ", mergedArray[i]);

    printf("\n");
    return 0;
}