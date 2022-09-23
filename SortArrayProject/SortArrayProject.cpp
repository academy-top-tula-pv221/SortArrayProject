#include <iostream>
#include "ArrayLib.h"

int main()
{
    const int size{ 10 };
    int array[size];

    ArrayInit(array, size);
    ArrayPrint(array, size);

    ArraySortQuick(array, size);

    ArrayPrint(array, size);

}
