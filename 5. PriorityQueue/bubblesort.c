#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define MAX_SIZE 15

// 원소의 이동연산 매크로함수 (단순치환
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

/*
bubble sort (맨 뒤부터 정렬 됨)
5 3 8 1 2 7  (1,2 비교)
3 5 8 1 2 7  (2,3 비교)
3 5 8 1 2 7  (3,4 비교)
3 5 1 8 2 7
3 5 1 2 8 7
3 5 1 2 7 8  (1단계 끝. 맨 뒤 8만 정렬된 상태)
3 5 1 2 7 8  (2단계 시작(1,2비교). <3 5 1 2 7> 에 대해 정렬 시작)
3 1 5 2 7 8  (2,3 비교)
3 1 2 5 7 8  (3,4 비교)
3 1 2 5 7 8  (4,5 비교. 2단계 끝. 맨 뒤 <7,8> 정렬 완료)
1 3 2 5 7 8  (3단계 시작(1,2비교) <3 1 2 5> 에 대해 시작)
1 2 3 5 7 8  (2,3 비교)
1 2 3 5 7 8  (3,4 비교. 3단계 끝. <5,7,8> 정렬 완료)
bubble 정렬 끝
*/

void bubble_sort(int list[], int n)
{
    int temp;
    printf("정렬할 원소 : ");
    for (int t =0; t<n; t++)
        printf("%d ", list[t]);
    printf("\n\n-----------버블 정렬 수행-----------");

    for(int i= n-1; i>0; i--)
    {
        printf("\n %d 단계>>", n-i);
        for(int j=0; j<i; j++)
            if(list[j] > list[j+1])
                SWAP(list[j], list[j+1], temp);
        for(int t=0; t<n; t++)
            printf("%3d ", list[t]);
    }
}

void main()
{
    int list[6] = {5,3,8,1,2,7};
    bubble_sort(list, 6);
} 