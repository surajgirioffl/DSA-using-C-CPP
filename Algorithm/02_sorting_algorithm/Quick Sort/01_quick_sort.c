/*Quick sort to sort a static array*/
#define max 10
#include <stdio.h>
typedef int let; // just for js

/*return the index of pivot which is already sorted index of array after return*/
int split(int *array, int low, int high)
{
    /*as per quick sort algorithm*/
    int i = low;
    int j = high;
    let pivot = array[low]; // we can take any index value as pivot. Here, we have taken 'low' indexed value as pivot

    /*
     *1. If i and j cross each other i.e i=j+1 then swap(array[j],array[indexOfPivot]). In this condition, left part of pivot will be less than pivot and right part of pivot will greater than pivot.
     *2. otherwise, we have to increase i until array[i]>pivot and then decrease j until array[j]<pivot
     *3. if above (step 2) condition satisfied then swap(array[i],array[j])
     *4. step 2 to 3 continue until step 1 condition satisfied.
     */
    while (i < j)
    {
        while (array[i] <= pivot)
            i++;
        /*after termination of above loop i will be pointing to that index whole value will greater than pivot*/
        while (array[j] >= pivot)
            j--;
        /*after termination of above loop j will be pointing to that index whole value will less than pivot*/
        // now we will swap value at i with value of j and vice versa
        let temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
    /*after termination of this loop i and j will cross each others.*/
    /*so, now we will swap value of index j with value at index of pivot and vice versa. And after this, pivot */
}