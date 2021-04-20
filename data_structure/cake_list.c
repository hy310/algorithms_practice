#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int data;
    struct ListNode *link;
}ListNode;

typedef struct
{
    ListNode *head;
}LinkedListType;

void init(LinkedListType *L)
{
    L->head = NULL;
}

void buildList(LinkedListType *L, int n)
{
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    L->head = p;
    p->data = 1;
    for (int i=2; i<=n; i++)
    {
        ListNode *next = (ListNode*)malloc(sizeof(ListNode));
        p->link = next;
        p = p->link;
        p->data = i;
    }
    p->link = L->head;
}


int runSimulation(LinkedListType *L, int n, int k)
{
    ListNode *p = L->head;
    while (p != p->link)
    {
        for (int i=1; i <= k-1; i++)
            p = p->link;
        ListNode *pnext = p->link;
        p->link = p->link->link;
        free(pnext);
        p = p->link;
    }
    return p->data;
}

int candle(LinkedListType *L, int n, int k)
{
    buildList(L, n);
    return runSimulation(L, n, k);
}

void main()
{
    LinkedListType list;    
    init(&list);
    int n; int k;
    printf("몇 개의 양초를 꽂을까요?");
    scanf("%d", &n);
    printf("몇 개씩 건너뛸까요?");
    scanf("%d", &k);
    printf("%d", candle(&list, n, k));
}