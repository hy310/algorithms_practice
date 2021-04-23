#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define MAX_SIZE 15
int sorted[MAX_SIZE];  // 정렬된 것 저장위한 array 전역으로 선언

void merge(int list[], int left, int mid, int right)
{
    int i=left; int k=left;
    int j = mid+1;
    int l; // 반복문 돌릴 변수

    while(i <= mid && j <= right)
    {
        if (list[i] <= list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++]; 
    }

    if (i > mid)
        for(l=j; l<=right; l++)
            sorted[k++] = list[l];
    else
        for(l=i; l<=mid; l++)
            sorted[k++] = list[l];

    for(l=left; l<=right; l++)
        list[l] = sorted[l];
}


void merge_sort(int list[], int left, int right)
{
    int mid;
    if(left < right) // 원소가 있어 분할할 수 있다면
    {
        mid = (left+right)/2;
        merge_sort(list, left, mid);
        merge_sort(list, mid+1, right);
        merge(list, left, mid, right);
    }
}


void main()
{
    int list[MAX_SIZE];
    srand(time(NULL));
    for(int i=0; i<MAX_SIZE; i++)
    {
        list[i] = rand() % 100;
        for(int j = 0; j<i; j++)
            if (list[i] == list[j])
                i--;
    }

    for (int i=0; i <MAX_SIZE; i++)
        printf("[%d] ", list[i]);
    printf("\n\n"); getch();

    merge_sort(list, 0, MAX_SIZE - 1);

    for(int i=0; i<MAX_SIZE; i++)
    {
        printf("[%d] ", list[i]);
        Sleep(500);  // 0.5초에 하나씩 출력
    }
    printf("\n");
}