#include <stdio.h>
#include <stdlib.h>

#define M 13

typedef struct {
    int key;
    int probeCount;  
    // 특정한 key 값이 배열 내에서 몇번의 조사를 거쳐서 삽입위치가 결정되는지 확인
}Bucket;

// Bucket 의 배열을 구조체로
typedef struct{
    Bucket A[M];
}HashType;

void initHash(HashType* HT)
{
    for(int i=0; i < M; i++)
    {
        HT -> A[i].key = 0;
        HT -> A[i].probeCount = 0;
    }
}

int h(int key)
{
    return key % M;
}

int h2(int key) // 이중 해싱
{
    return 11 - (key % 11);    // q - (k % q)
}

int getNextBucketLinear(int v, int i)
{
    return (v+i) % M;
}

// 이차 조사법
int getNextBucketQuadratic(int v, int i)
{
    return (v + i * i) % M;
}

// 이중 해싱법
int getNextBucketDouble(int v, int i, int key)
{
    return (v + i * h2(key)) % M;
}

int isEmpty(HashType* HT, int b)
{
    return HT->A[b].key == 0;
}

void insertItem(HashType* HT, int key)
{
    int v = h(key);
    int i = 0;
    int count = 0;   // 몇번 시도 되어서 삽입되었는지 기록
    while(i < M)
    {
        count++;
        //int b = getNextBucketQuadratic(v, i); // 이차조사법
        //int b = getNextBucketDouble(v, i, key);  // 이중해싱법
        int b = getNextBucketLinear(v, i);  // 선형조사법
        if(isEmpty(HT, b))
        {
            HT->A[b].key = key;
            HT->A[b].probeCount = count;
            return;
        }
        else
            i++;
    }
}

void printHashTable(HashType* HT)
{
    printf("Bucket Key Probe\n");
    printf("======================\n");

    for (int i=0; i<M; i++)
        printf("HT[%02d] : %2d %d\n", i, HT->A[i].key, HT->A[i].probeCount);       
}

int main()
{
    HashType HT;
    initHash(&HT);

    insertItem(&HT, 25);
    insertItem(&HT, 13);
    insertItem(&HT, 16);
    insertItem(&HT, 15);
    insertItem(&HT, 7);
    insertItem(&HT, 28);
    insertItem(&HT, 31);
    insertItem(&HT, 20);
    insertItem(&HT, 1);
    insertItem(&HT, 38);
    printHashTable(&HT);

    return 0;
}