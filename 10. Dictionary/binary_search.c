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

void insertion_sort(DictType* d)
{
    int i, j;
    element item;
    for (i=1; i<SIZE; i++)
    {
        item = d -> dict[i];
        for (j=i-1; j>=0 && d -> dict[j].key > item.key; j--)
            d->dict[j+1] = d->dict[j];
        d->dict[j+1] = item;
    }
}

int rFindElement(DictType* d, int key, int l, int r)
{
    int mid;
    if (l <= r)
    {
        mid = (l+r) / 2;
        if(key == d->dict[mid].key)
            return mid;
        else if (key < d->dict[mid].key)
            return rFindElement(d, key, l, mid-1);
        else
            return rFindElement(d, key, mid+1, r);
    }
    return -1;
}

int main()
{
    DictType d;
    init(&d);
    srand(time(NULL));
    makeDict(&d);           // 순서 사전 만들기
    printDict(&d);
    getchar();
    printf("\n");
    insertion_sort(&d);
    printDict(&d);
    getchar();

    printf("\n검색할 키 값을 입력하세요 : ");
    int key;
    scanf_s("%d", &key);
    int index = rFindElement(&d, key, 0, SIZE - 1);
    if (index == -1)
        printf("\n검색에 실패하였습니다.\n");
    else
    {
        printf("\n위치 %d에서 키 %d 값 ", index+1, key);
        for (int j=0; j<5; j++)
            printf("%c", d.dict[index].value[j]);
        printf("이 검색되었습니다.\n");
    }

    return 0;
}
