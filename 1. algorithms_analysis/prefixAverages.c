#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8

void makeArray(int A[])
{
    for(int i = 0; i<SIZE; i++)
        A[i] = rand() % 50 + 50;
}

void printArray(int A[])
{
    for(int i=0; i<SIZE; i++)
        printf("[%d] ", A[i]);
    printf("\n");
}

//O(n^2) 시간에 완성
void prefixAVg1(int A[])
{
    int X[SIZE];
    int sum;
    for(int i=0; i<SIZE; i++)
    {
        sum = 0;
        for (int j=0; j <= i; j++)
            sum += A[j];
        X[i] = sum / (i+1);
    }
    printArray(X);
}

//O(n) 시간에 완성
void prefixAVg2(int A[])
{
    int X[SIZE];
    int sum = 0;
    for(int i=0; i<SIZE; i++)
    {
        sum += A[i];
        X[i] = sum / (i+1);
    }
    printArray(X);
}

void main()
{
    int A[SIZE];
    srand(time(NULL));      //srand 안하면 계속 똑같은값만 난수로 발생
    makeArray(A);
    printArray(A);
    getchar();
    prefixAVg2(A);
}