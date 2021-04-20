#include <stdio.h>
#include <stdlib.h>

// 배열로 리스트 구현
#define SIZE 100

// 리스트를 배열로 구현하기 때문에 array list 라는 이름으로 정의
typedef struct
{
    int V[SIZE];         // 리스트 역할을 할 배열 V
    int n;               // 요소의 개수를 기억할 변수 n
}ArrayList;              // 이 구조체 이름을 arraylist 라고 선언함

// 초기화 함수 만들기
void init(ArrayList *L)     // 주소가 날아오니 포인터변수 L로 받기
{
    L->n = 0;            // L의 원소의 개수는 0개
}

// traverse(순회) 함수 만들기
void traverse(ArrayList *L)    // ArrayList 전달해주고 반복문돌리기
{
    for (int i=0; i < L->n; i++)
        printf("[%d] ", L->V[i]);
    printf("\n");
}

// add 함수 만들기
void add(ArrayList *L, int pos, int item)
{
    if (L->n == SIZE)
    {
        printf("fullListException...\n");
        exit(1);
    }
    if (pos < 0 || pos > L->n)
    {
        printf("invalidRankException...\n");
    }

    for (int i = L->n-1; i>=pos; i--)
        L->V[i+1] = L -> V[i];
    L->V[pos] = item;
    L->n++;
}

int remove1(ArrayList *L, int pos)
{
    if (pos < 0 || pos > L->n-1)
    {
        printf("invalidRankException...\n");
    }
    if (L->n == 0)
    {
        printf("emptyListException...\n");
        return 0;
    }

    int item = L->V[pos];
    for (int i = pos+1; i <= L->n - 1; i++ )
        L->V[i-1] = L->V[i];
    L->n--;
    return item;
}


void main()
{
    ArrayList list;      // main 함수에서 ArrayList 를 사용하기 위해 구조체 변수 선언하기

    init(&list);          // init 함수로 초기화하기. 구조체 포인터로 전달
    
    add(&list, 0, 10); traverse(&list);
    add(&list, 0, 20); traverse(&list);
    add(&list, 1, 30); traverse(&list);
    add(&list, 1, 40); traverse(&list);
    add(&list, 3, 50); traverse(&list);

    remove1(&list, 2); traverse(&list);
    remove1(&list, 3); traverse(&list);

}