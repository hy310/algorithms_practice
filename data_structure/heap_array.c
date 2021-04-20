#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENT 100

typedef struct 
{
    int heap[MAX_ELEMENT];
    int heap_size;
}HeapType;

void init(HeapType *h)
{
    h->heap_size = 0;
}

void upHeap(HeapType *h)
{
    int i = h->heap_size; // 현재의 heap size 임의의 일반변수에 저장
    int key = h->heap[i]; // 제일 뒤에 있는 값

// 루트가 아니거나 키값이 부모노드보다 작을 때 swap 
    while ((i!=1) && (key < h->heap[i/2]))
    {
        h->heap[i] = h->heap[i/2]; //부모노드로 올라가고
        i /= 2; //원래 값 부모노드로 바꾸는 격
    }
    h->heap[i] = key; // 이동이 멈추면 i 번 인덱스에 키를 집어넣기
}

void downHeap(HeapType *h)
{
    int temp = h->heap[1];
    int parent = 1, child = 2;

    while(child <= h->heap_size)
    {
        if((child < h->heap_size) && (h->heap[child] > h->heap[child + 1]))
            child++;
        if(temp <= h->heap[child])
            break;
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
}

void insertItem(HeapType *h, int key)
{
    //새로운 키값 삽입
    h -> heap_size += 1;
    h -> heap[h->heap_size] = key;
    upHeap(h);

}

int removeMin(HeapType *h)
{
    int key = h->heap[1];
    h->heap[1] = h->heap[h->heap_size]; // last node 를 root 에 넣어주기
    h->heap_size -= 1;
    downHeap(h);
    return key;
}

void printHeap(HeapType *h)
{
    for(int i = 1; i <= h->heap_size; i++)
        printf("[%d] ", h->heap[i]);
    printf("\n");
}

void heapSort(HeapType *h, int list[])
{
    HeapType heap;
    init(&heap);
    for(int i=1; i <= h->heap_size; i++)
    {
        heap.heap[i] = h->heap[i];
        heap.heap_size++;
    }
    for(int i=1; i <= h->heap_size; i++)
        list[i] = removeMin(&heap);  //removeMin 을 통해 작은값부터 순차적으로 저장
}

void printArray(int list[], int n)
{
    for(int i = 1; i <= n; i++)
        printf("[%d] ", list[i]);
    printf("\n");
}

void inPlaceHeapSort(HeapType *h)
{
    int size = h->heap_size;
    int key;
    for(int i = 0; i<size; i++)
    {
        key = removeMin(h);
        h -> heap[h->heap_size + 1] = key;
    }
}

void main()
{
    HeapType heap;
    int list[MAX_ELEMENT] = {0};
    srand(time(NULL));
    init(&heap);
    for(int i=0; i<5; i++)
        insertItem(&heap, rand() % 100);
    printHeap(&heap);
//    inPlaceHeapSort(&heap);
//    for(int i = 1; heap.heap[i] > 0; i++)
//        printf("[%d] ", heap.heap[i]);
}
