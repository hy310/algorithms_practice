#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct
{
    int V[SIZE];
    int num;
}ArrayList;


void init(ArrayList *L)
{
    L->num = 0;
}

void buildList(ArrayList *L, int n)
{
    for (int i=0; i < n; i++)
        L->V[i] = i+1;
}

int runSimulation(ArrayList *L, int n, int k)
{
    int r = 0;
    int N = n;
    while (n > 1)
    {
        int i = 0;
        while(i < k)
        {
            r = (r+1) % N;
            if (L->V[r] != 0)
                i = i+1;
        }
        L->V[r] = 0;
        n = n-1;
        while(L->V[r] == 0)
            r = (r+1) % N;
    }
    return L->V[r];
}

int candle(ArrayList *L, int n, int k)
{
    buildList(L, n);
    return runSimulation(L, n, k);
}

void main()
{
    ArrayList list;      
    init(&list);
    int n; int k;
    printf("몇 개의 양초를 꽂을까요?");
    scanf("%d", &n);
    printf("몇 개씩 건너뛸까요?");
    scanf("%d", &k);
    printf("%d", candle(&list, n, k));
}