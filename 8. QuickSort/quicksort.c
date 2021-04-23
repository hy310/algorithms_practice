#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 15
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

int partition(int list[], int left, int right)
{
    int pivot, temp, low, high;
    low = left;
    high = right+1;
    pivot = list[left];
    
    do
    {
        do
            low++;
        while (list[low] < pivot);

        do
            high--;
        while(list[high] > pivot);

        if(low < high)
            SWAP(list[low], list[high], temp);
        
    }while (low < high);

    SWAP(list[left], list[high], temp);
    return high;     // fixed 된 pivot 의 위치를 return 해서 큐에 넣어줄 것
    

}

void quick_sort(int list[], int left, int right)
{
    if(left < right)  // list size 1보다 클 동안
    {
        int q = partition(list, left, right);
        quick_sort(list, left, q-1);
        quick_sort(list, q+1, right);
    }
}

void main()
{
    int list[MAX_SIZE];
    srand(time(NULL));
    for(int i=0; i<MAX_SIZE; i++)
        list[i] = rand() % 100;
    for(int i=0; i<MAX_SIZE; i++)
        printf("[%d] ", list[i]);
    printf("\n\n"); getch();

    quick_sort(list, 0, MAX_SIZE - 1);

    for(int i=0; i<MAX_SIZE; i++)
        printf("[%d] ", list[i]);
    printf("\n\n"); getch();

}