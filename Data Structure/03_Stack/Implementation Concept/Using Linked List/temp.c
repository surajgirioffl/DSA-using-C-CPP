#include <stdio.h>
int *sum()
{
    int a = 5;
    return &a;
}

int main()
{
    int *ptr = sum();
    printf("sum is %d\n", *ptr);
    /* It will not print because on the basis of block concept value lost at the address
     *so receive address will not contain anything.* solution is "we have pass the variable by reference and store the data in it. So,  it will not lost till loss of calling function".
     *means local variable of function lost just coming out from the block of the same function
     *on debugging it will show error that 'function returns address of local variable'. and it will not remain in memory
     *It will say segmentation fault when printing because no memory provided that you are tyring to accessing because memory is cleared after function returns.
     */
}
