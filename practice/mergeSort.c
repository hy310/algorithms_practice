#include <stdio.h>
#define SIZE 6

void merge(int array[], int low, int middle, int high)
{
    int leftIndex = low;
    int rightIndex = middle+1;
    int mergedIndex = low;
    int tempArray[SIZE];
    int i;

    while(leftIndex <= middle && rightIndex <= high)
    {
        if(array[leftIndex] <= array[rightIndex])
            tempArray[mergedIndex++] = array[leftIndex++];
        else
            tempArray[mergedIndex++] = array[rightIndex++];
    }

    if(leftIndex == middle+1)
    {
        while(rightIndex <= high)
            tempArray[mergedIndex++] = array[rightIndex++];
    }

    else
    {
        while(leftIndex <= middle)
            tempArray[mergedIndex++] = array[leftIndex++];
    }

    for(i=low; i<=high; i++)
        array[i] = tempArray[i];
}

void divide(int array[], int low, int high) 
{
    int middle;
    if(high - low > 0) 
    {
        middle = (high + low) /2;

        divide(array, low, middle);
        divide(array, middle + 1, high);

        merge(array, low, middle, high);
        for (int j=0; j<SIZE; j++)
            printf("%d ", array[j]);
        printf("\n");
    }
}

void mergeSort(int array[], int length)
{
    divide(array, 0, length-1);
}

int main()
{
    int input[SIZE] = {4,3,6,2,1,5};
    mergeSort(input, SIZE);
//    for (int i=0; i<SIZE; i++)
//        printf("%d ", input[i]);
    return 0;
}

