#include <cstdio>
#include <iostream>

using namespace std;

/*
ARRAYS
    Arrays specify length, either in the number of members or the [num] argument.
    when you used braced initializers, the [num] argument becoems optional:
        this is because the compiler infers the size from the number of arguments.
        int myArray[] = {0,1,2,3,4,5,6,7,8,9};
    Do not initialize arrays like this, because the values will remain unitialized:
        int array[5];
    Good practice:
        int myArray[100]{}; will initialize to zero.

*/
int main()
{
    int myArray1[100];                               // unitialized values; never do this!
    int myArray2[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // good practice
    int myArray3[5]{1, 2};                           // this works; the other elements are initialized.
    int myArray4[100]{};                             // good practice
    return 0;
}