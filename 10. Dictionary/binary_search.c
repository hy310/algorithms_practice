#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 15

typedef struct 
{
    int key;
    char value[10];
}element;

typedef struct
{
    element dict[SIZE];    // element �迭�� dictionary �����
    int size;              // dictionary �׸��� ������ ���
}DictType;

void init(DictType* d)
{
    d->size = 0;
}

void insertKey(DictType* d)
{
    for (int i=0; i<SIZE; i++)
    {
        d->dict[i].key = rand() % 30 +1;
        for(int j = 0; j < i; j++)     
            if(d->dict[i].key == d->dict[j].key)
                i--;
                // ����Ű �����̱� ������
                // �̹� ������ �����ϴ� Ű���� �ִٸ� backward �ؼ� Ű���ߺ�����
    }
}

void insertValue(DictType* d)
{
    for (int i=0; i < SIZE; i++)
    {
        for (int j=0; j < 5; j++)  // 5���� ���� ���ڿ�
            d->dict[i].value[j] = rand() % 26 + 97;  // A���� Z���� (26,97)
        d->size++;
    }
}

void makeDict(DictType* d)
{
    insertKey(d);
    insertValue(d);
}

void printDict(DictType* d)
{
    printf("key value \n ============================\n");
    for(int i=0; i < d->size; i++)
    {
        printf("%2d ", d->dict[i].key);
        for (int j=0; j <5; j++)
            printf("%c", d->dict[i].value[j]);
        printf("\n");
    }
}

int main()
{
    DictType d;
    init(&d);
    srand(time(NULL));
    makeDict(&d);           // ���� ���� �����
    printDict(&d);
}
