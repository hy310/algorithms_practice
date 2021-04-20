#include <stdio.h>
#include <stdlib.h>

// �迭�� ����Ʈ ����
#define SIZE 100

// ����Ʈ�� �迭�� �����ϱ� ������ array list ��� �̸����� ����
typedef struct
{
    int V[SIZE];         // ����Ʈ ������ �� �迭 V
    int n;               // ����� ������ ����� ���� n
}ArrayList;              // �� ����ü �̸��� arraylist ��� ������

// �ʱ�ȭ �Լ� �����
void init(ArrayList *L)     // �ּҰ� ���ƿ��� �����ͺ��� L�� �ޱ�
{
    L->n = 0;            // L�� ������ ������ 0��
}

// traverse(��ȸ) �Լ� �����
void traverse(ArrayList *L)    // ArrayList �������ְ� �ݺ���������
{
    for (int i=0; i < L->n; i++)
        printf("[%d] ", L->V[i]);
    printf("\n");
}

// add �Լ� �����
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
    ArrayList list;      // main �Լ����� ArrayList �� ����ϱ� ���� ����ü ���� �����ϱ�

    init(&list);         // init �Լ��� �ʱ�ȭ�ϱ�. ����ü �����ͷ� ����
    
    add(&list, 0, 10); traverse(&list);
    add(&list, 0, 20); traverse(&list);
    add(&list, 1, 30); traverse(&list);
    add(&list, 1, 40); traverse(&list);
    add(&list, 3, 50); traverse(&list);

    remove1(&list, 2); traverse(&list);
    remove1(&list, 3); traverse(&list);

}