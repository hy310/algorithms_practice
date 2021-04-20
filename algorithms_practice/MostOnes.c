#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 8
#define COLS 8

void makeArray(int A[][COLS])
{
    for(int r = 0; r  < ROWS; r++)
    {
        int count = rand() % 8;  // 1의 개수를 rand 함수로 정함
        for(int i=0; i<count; i++)
            A[r][i] = 1;
        for(int j=count; j<COLS; j++)
            A[r][j] = 0;
    }
}

void printArray(int A[][COLS])
{
    for(int r = 0; r < ROWS; r++)
    {
        for(int c = 0; c < COLS; c++)
            printf("%2d ", A[r][c]);
        printf("\n");
    }
    printf("\n");
}

void mostOnesButSlow(int A[][COLS])
{
    int jmax = 0;
    int i, j, row;
    for(i=0; i < ROWS; i++)
    {
        j = 0;
        while(j<COLS && A[i][j] == 1)
            j++;
        if(j > jmax)
        {
            row = i;
            jmax = j;
        }
    }
    printf("%d행에 %d개의 1이 최대값임\n", row, jmax);
}

int mostOnes(int A[][COLS])  //2차원 배열은 행은 생략가능하나 열은 생략하면 error 나니까 하나는 적어주는 것임
{
    int i=0, j=0;
    int row;

    while(1)
    {
        while(A[i][j] == 1)
        {
            j++;
            if(j == COLS - 1)
                return i;
        }
        row = i;
        while(A[i][j] == 0)
        {
            i++;
            if(i == COLS - 1)
                return row;
        }

    }
}
void main()
{
    int A[ROWS][COLS];
    srand(time(NULL));      //srand 안하면 계속 똑같은값만 난수로 발생
    makeArray(A);
    printArray(A);
    getchar();

    printf("최대 1행은 %d행입니다.\n", mostOnes(A));

}