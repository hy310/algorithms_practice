#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct
{
    int V[SIZE];
    int n;
}ArrayList;


void init(ArrayList *L)
{
    L->n = 0;
}

int remove1(ArrayList *L, int n, int pos)
{
    if (pos < 0 || pos > n-1)
    {
        printf("invalidRankException...\n");
    }
    if (n == 0)
    {
        printf("emptyListException...\n");
        return 0;
    }
    
    int item = L->V[pos];
    for (int i = pos+1; i <= n - 1; i++)
        L->V[i-1] = L->V[i];
    n--;
    return n;
}

void buildList(ArrayList *L, int n)
{
    for (int i=0; i < n; i++) {
        L->V[i] = i+1;
    }
}


int runSimulation(ArrayList *L, int n, int k)
{
    int r = 0;

    while (n > 1)
    {
        r = (r+k) % n;
        n = remove1(L, n, r);
    }

    return L->V[0];
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