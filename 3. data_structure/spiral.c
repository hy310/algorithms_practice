#include <stdio.h>
#include <stdlib.h>

#define ROWS 6
#define COLS 8

// 행렬 '나선형' 채우기
// n*m 배열의 [0,0] 셀에서 출발하여 1부터 nm 사이의 정수를 '나선형' 순서로 채우는 알고리즘

void spiral(int A[][COLS])
{
    int left = 0;
    int top = 0;
    int right = COLS - 1;
    int bottom = ROWS - 1;
    int value = 1;

    while(left <= right && top <= bottom)
    {
        for(int j=left; j <= right; j++)
        {
            A[top][j] = value;
            value++;
        }
        top++;

        if(left <= right && top <= bottom)
        {
            for(int i=top; i<=bottom; i++)
            {
                A[i][right] = value;
                value++;
            }
            right--;
        }
    
        if(left <= right && top <= bottom)
        {
            for(int j=left; j<=right; j++)
            {
                A[bottom][left + right - j] = value;
                value++;
            }
            bottom--;
        }

        if(left <= right && top <= bottom)
        {
            for(int i=top; i<=bottom; i++)
            {
                A[top + bottom - i][left] = value;
                value++;
            }
            left++;
        }
    }
}

void printArray(int A[][COLS])
{
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
            printf("%2d ", A[i][j]);
        printf("\n");
    }
}

void main()
{
    int A[ROWS][COLS] = {0}; 
    spiral(A);
    printArray(A);
}