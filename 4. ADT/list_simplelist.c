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

void addFirst(LinkedListType *L, int item)
{
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node->data = item;
    node->link = L->head;
    L->head = node;
}

void addLast(LinkedListType *L, int item)
{
    ListNode *node = (ListNode*)malloc(sizeof(ListNode)); 
    ListNode *before = L->head;
    while(before->link != NULL)
        before = before->link;
    node->data = item;
    node->link = NULL;
    before->link = node;
}

void add(LinkedListType *L, int pos, int item)
{
    ListNode *node = (ListNode*)malloc(sizeof(ListNode)); 
    ListNode *before = L->head;
    for (int i = 0; i < pos - 1; i++)
        before = before ->link;
    node->data = item;
    node->link = before->link;
    before->link = node;
}

void removeFirst(LinkedListType *L)
{
    ListNode *node = L->head;
    L->head = L->head->link;
}

void removeLast(LinkedListType *L)
{
    ListNode *before = L->head;
    while(before->link != NULL)
    {
        if (before->link->link == NULL)
            break;
        else 
            before = before->link;
    }
    before->link = NULL;
}

void removeitem(LinkedListType *L, int pos)
{
    ListNode *before = L->head;
    for (int i = 0; i < pos - 1; i++)
        before = before ->link;
    before->link = before->link->link;
}

int get(LinkedListType *L, int pos)
{
    ListNode *p = L->head;
    for(int i = 1; i < pos; i++)
        p = p->link;
    return p->data;
}

void set(LinkedListType *L, int pos, int item)
{
    ListNode *p = L->head;
    for(int i = 1; i < pos; i++)
        p = p->link;
    p->data = item;
}

void printList(LinkedListType *L)
{
    for(ListNode *p = L->head; p != NULL; p = p->link)
        printf("[%d] -> ", p->data);
    printf("NULL\n");
}

void main()
{
    LinkedListType list;
    init(&list);

    addFirst(&list, 10); printList(&list);
    addFirst(&list, 20); printList(&list);
    addFirst(&list, 30); printList(&list);
    addFirst(&list, 70); printList(&list);
    add(&list, 2, 40); printList(&list);
    addLast(&list, 7); printList(&list);
    getchar();
    removeLast(&list); printList(&list);
    removeFirst(&list); printList(&list);
    removeitem(&list, 2); printList(&list);
    printf("2번 노드의 값은 %d\n", get(&list, 2));
    int pos;
    printf("몇번 노드의 값을 90으로 변경할까요?\n");
    scanf("%d", &pos);
    set(&list, pos, 90); printList(&list);
}