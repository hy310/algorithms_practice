#include <stdio.h>

struct node
{
//    int data;
    char name[20];
//    struct node* nextNode;
};

typedef struct node node_t;
//node_t* list_head;

int main()
{
    printf("size of node is %d\n", sizeof(node_t));
}