#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

// n*n 배열의 [0,0] 셀에서 출발하여 
// 1부터 n 사이의 정수를 지그재그 순서로 채우는 알고리즘

void zigzag(int A[][SIZE])
{
    int value = 1;
    for(int i=0; i < SIZE; i++)
    {
        if(i % 2 == 0)
            for(int j = 0; j < SIZE; j++)
            {
                A[i][j] = value;
                value++;
            }
        else
            for(int j = SIZE - 1; j >= 0; j--)
            {
                A[i][j] = value;
                value++;
            }
    }

}

void printArray(int A[][SIZE])
{
    for(int i = 0; i < SIZE; i++)
    {
        for (int j=0; j < SIZE; j++)
            printf("%2d ", A[i][j]);
        printf("\n");
    }
}

void main()
{
    int A[SIZE][SIZE] = {0};
    zigzag(A);
    printArray(A);
}