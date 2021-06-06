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

int h(int key)    // 해시 함수
{
    return key % M;
}

void insertItem(HashType* HT, int key)
{
    int v = h(key);
    HashType* node = (HashType*)malloc(sizeof(HashType));
    node->key = key;
    node->next = HT[v].next;  // insert First
    // 원래 첫번째 있던 애가 두번째가 되는 것
    HT[v].next = node;
    // 내가 첫번째가 되는 것
}

int removeElement(HashType* HT, int key)
{
    int v = h(key);
    int count = 0;
    // 단순 연결리스트이기 때문에 삭제 했을 때 그 전 값 기억하기 위해
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
        // 내가 보고 있는 곳이 hash table 에서 몇번 버켓에 
        // 연결되었는지 확인 ( 0 ~ 12 )
        printf("HT[%02d] : ", i);  // 두자리수이고, 한자리수라면 앞에 0을 집어넣음
        for(p = HT[i].next; p != NULL; p = p->next)
            printf("(%d) ", p->key);
        printf("\n");
    }
}

int main()
{
    HashType HT[M];    // 배열로 만들어주기
    init(HT);

    srand(time(NULL));

    for(int i=0; i<20; i++)
        insertItem(HT, rand() % 90 + 10);   // 두자리수로 맞춰주기 위해 90 mod 한 다음 10 더하기
    
    printHash(HT);

    printf("\n삭제할 키 입력 : ");
    int key;
    scanf("%d", &key);
    
    printf("\n키 값 %d가 %d개 삭제되었습니다. \n\n", key, removeElement(HT, key));
    printHash(HT);

    return 0;
}