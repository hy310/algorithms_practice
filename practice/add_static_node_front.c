#include <stdio.h>

struct node
{
    int data;
    char name[20];
    struct node* nextNode;
};

typedef struct node node_t;
node_t* list_head;

void add_static_node_front() 
{
    static node_t newnode;
    newnode.nextNode = list_head;
    list_head = &newnode;
}

int main()
{
    printf("size of node is %d\n", sizeof(node_t));
    node_t node1, node2;
    list_head = &node1;

    node1.data = 10;
    node1.nextNode = &node2;

    node2.data = 20;
    node2.nextNode = NULL;

    add_static_node_front();
    list_head->data = 30;

    add_static_node_front();
    list_head->data = 40;

    printf("%d\n", list_head->data);
    printf("%d\n", list_head->nextNode->data);
    printf("%d\n", list_head->nextNode->nextNode->data);
    return 0;
}