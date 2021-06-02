#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8

typedef struct
{
    int elem;
    int idx;
}Dict;

void sort(Dict D[])
{
    int elem, i, j, idx;
    for(i=1; i<SIZE; i++)
    {
        elem = D[i].elem;
        idx = D[i].idx;
        // insertion sort
        for(j=i-1; j>=0 && D[j].elem > elem; j--)
        {
            D[j+1].elem = D[j].elem;
            D[j+1].idx = D[j].idx;
        }
        D[j+1].elem = elem;
        D[j+1].idx = idx;
    }

}

int findElement(Dict D[], int v)
{
    int mid;
    int l = 0;
    int r = SIZE-1;
    while(l <= r)
    {
        mid = (l+r) / 2;
        if (D[mid].elem == v)
            return D[mid].idx;
        else if(D[mid].elem > v)
            r = mid-1;
        else
            l = mid+1;
    }
    return -1;
}

void findIndexPair(Dict D[], int A[], int s)
{
    int j;
    for(int i=0; i<SIZE; i++)
    {
        int v = s - A[i];
        j = findElement(D, v);   // findElement 는 이진탐색으로 구현
        if (j != -1)
        {
            printf("(%d, %d)\n", i, j);
            printf("%d + %d = %d", A[i], A[j], s);
            break; 
        }
    }
    if (j == -1)
        printf("Not Found\n");
}

void buildDict(Dict D[], int A[])
{
    for(int i=0; i<SIZE; i++)
    {
        D[i].elem = A[i];
        D[i].idx = i;
    }
    sort(D);
}

int main()
{
    int A[SIZE] = {2, 21, 8, 3, 5, 1, 13, 1};
    Dict D[SIZE];
    int s;

    for(int i=0; i<SIZE; i++)
        printf("[%d] ", A[i]);
    printf("\n");

    buildDict(D, A);
    for(int i=0; i<SIZE; i++)
        printf("(%d, %d) ", D[i].elem, D[i].idx);
    printf("\n");

    getchar();
    printf("더해서 s 가 되는 수 s 를 입력하세요 : ");
    scanf_s("%d", &s);
    findIndexPair(D, A, s);

    return 0;
}