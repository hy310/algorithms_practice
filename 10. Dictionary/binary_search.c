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
    element dict[SIZE];    // element 배열로 dictionary 만들기
    int size;              // dictionary 항목의 개수를 기억
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
                // 유일키 사전이기 때문에
                // 이미 이전에 존재하는 키값이 있다면 backward 해서 키값중복방지
    }
}

void insertValue(DictType* d)
{
    for (int i=0; i < SIZE; i++)
    {
        for (int j=0; j < 5; j++)  // 5글자 랜덤 문자열
            d->dict[i].value[j] = rand() % 26 + 97;  // A부터 Z까지 (26,97)
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
    makeDict(&d);           // 순서 사전 만들기
    printDict(&d);
}
