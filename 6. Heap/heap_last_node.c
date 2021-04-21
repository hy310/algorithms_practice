#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 100
#define LEN 10
#define TRUE 1
#define FALSE 0

struct Heap
{
    int H[MAX_ELEMENT];
    int n;
}_Heap;

struct Stack
{
    int Arr[LEN];
    int top;
}_Stack;

void init_Stack()
{
    _Stack.top = -1;
}

int isEmpty()
{
    if(_Stack.top == -1)
        return TRUE;
    else
        return FALSE;
}

int pop()
{
    if(_Stack.top == -1)
    {
        printf("memory error!");
        exit(-1);
    }
    int temp = _Stack.Arr[_Stack.top];
    _Stack.top -= 1;
    return temp;
}

void push(int data)
{
    _Stack.top += 1;
    _Stack.Arr[_Stack.top] = data;
}

void init_Heap()
{
    _Heap.n = 0;
}

void upHeap()
{
    int i = _Heap.n;
    int key = _Heap.H[i]; 
    while ((i!=1) && (key < _Heap.H[i/2]))
    {
        _Heap.H[i] = _Heap.H[i/2];
        i /= 2;
    }
    _Heap.H[i] = key;
}

void insertItem(int key)
{
    _Heap.n += 1;
    _Heap.H[_Heap.n] = key;
    upHeap();
}

void printHeap()
{
    for (int i = 1; i<= _Heap.n; i++)
        printf("[%d] ", _Heap.H[i]);
    printf("\n");
}

void printStack()
{
    for (int i=0; i< _Stack.top + 1; i++)
        printf("%d\n", _Stack.Arr[i]);
}

void binaryExpansion(int i)
{
    while(i >= 2)
    {
        push(i%2);
        i = i/2;
    }
    push(i);
}

int findLastNode(int v, int n)
{
    int bit;
    init_Stack();
    binaryExpansion(n);
    pop();
    int i=1;
    
    while(!isEmpty())
    {
        bit = pop();
        if (bit == 0)
        {
            i = i*2;
            v = _Heap.H[i];
        }
        else
        {
            i = i*2 +1;
            v = _Heap.H[i];
        }
    }

    return v;
}

void main()
{
    int n;
    int key;
    init_Stack();
    init_Heap();
    printf("입력할 원소의 개수 : ");
    scanf_s("%d", &n);
    printf("Insert할 원소를 입력하세요\n");

    for(int i=1; i <= n; i++)
    {
        scanf_s("%d", &key);
        insertItem(key);
    }

    printf("완성된 최소 힙은\n");
    printHeap();

    printf("힙의 마지막 노드는\n");
    printf("%d", findLastNode(_Heap.H[1], n));
}