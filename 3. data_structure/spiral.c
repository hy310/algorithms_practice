#include <stdio.h>
#include <stdlib.h>

#define ROWS 6
#define COLS 8

// ��� '������' ä���
// n*m �迭�� [0,0] ������ ����Ͽ� 1���� nm ������ ������ '������' ������ ä��� �˰���

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