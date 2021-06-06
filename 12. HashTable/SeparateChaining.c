#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 13

typedef struct HashNode
{
    int key;
    struct HashNode* next;
}HashType;

void init(HashType* HT)
{
    for (int i=0; i<M; i++)
    {
        HT[i].key = 0;
        HT[i].next = NULL;
    }
}

int h(int key)    // �ؽ� �Լ�
{
    return key % M;
}

void insertItem(HashType* HT, int key)
{
    int v = h(key);
    HashType* node = (HashType*)malloc(sizeof(HashType));
    node->key = key;
    node->next = HT[v].next;  // insert First
    // ���� ù��° �ִ� �ְ� �ι�°�� �Ǵ� ��
    HT[v].next = node;
    // ���� ù��°�� �Ǵ� ��
}

int removeElement(HashType* HT, int key)
{
    int v = h(key);
    int count = 0;
    // �ܼ� ���Ḯ��Ʈ�̱� ������ ���� ���� �� �� �� �� ����ϱ� ����
    HashType* p = &HT[v];
    HashType* q;

    while(p->next)
    {
        if(p->next->key == key)
        {
            count++;
            q = p->next;
            p->next = q->next;
            free(q);
        }
        else
            p = p->next;
    }
    return count;
}

int findElement(HashType* HT, int key)
{
    int v = h(key);
    int count;
    HashType* p;
    for(p = HT[v].next; p != NULL; p = p->next)
        if(p->key == key)
            count;;
    return count;
}

void printHash(HashType* HT)
{
    HashType* p;
    for (int i=0; i<M; i++)
    {
        // ���� ���� �ִ� ���� hash table ���� ��� ���Ͽ� 
        // ����Ǿ����� Ȯ�� ( 0 ~ 12 )
        printf("HT[%02d] : ", i);  // ���ڸ����̰�, ���ڸ������ �տ� 0�� �������
        for(p = HT[i].next; p != NULL; p = p->next)
            printf("(%d) ", p->key);
        printf("\n");
    }
}

int main()
{
    HashType HT[M];    // �迭�� ������ֱ�
    init(HT);

    srand(time(NULL));

    for(int i=0; i<20; i++)
        insertItem(HT, rand() % 90 + 10);   // ���ڸ����� �����ֱ� ���� 90 mod �� ���� 10 ���ϱ�
    
    printHash(HT);

    printf("\n������ Ű �Է� : ");
    int key;
    scanf("%d", &key);
    
    printf("\nŰ �� %d�� %d�� �����Ǿ����ϴ�. \n\n", key, removeElement(HT, key));
    printHash(HT);

    return 0;
}