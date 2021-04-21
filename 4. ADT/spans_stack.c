#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 100
#define LEN 8
#define TRUE 1
#define FALSE 0

typedef struct
{
    int Arr[LEN];
    int top;
}stack;

void init(stack *A)
{
    A->top = -1;
}

int isEmpty(stack *A)
{
    if(A->top == -1)
        return TRUE;
    else
        return FALSE;
}

int pop(stack *A)
{
    if(A->top == -1)
    {
        printf("memory error!");
        exit(-1);
    }
    int temp = A->Arr[A->top];
    A->top -= 1;
    return temp;
}


void push(stack *A, int data)
{
    A->top += 1;
    A->Arr[A->top] = data;
}

void printstack(stack *A)
{
    for (int i=0; i < A->top+1; i++)
        printf("%d\n", A->Arr[i]);
}

void spans2(int X[], int S[], int n, stack *A)
{
    for(int i = 0; i < n; i++)
    {
        while((!isEmpty(A)) && (X[A->top] <= X[i]))
            pop(A);
        if(isEmpty(A))
            S[i] = i + 1;
        else   
            S[i] = i - A->top;
        push(A, i);
    }
    while(!isEmpty(A))
        pop(A);
}

int main()
{
    int X[LEN] = {60, 30, 40, 10, 20, 30, 50, 40};
    int S[LEN] = {0};    
    stack A;
    init(&A);
    spans2(X, S, LEN, &A);
    for(int i = 0; i < LEN; i++)
        printf("%d ", S[i]);
    printf("\n");
}