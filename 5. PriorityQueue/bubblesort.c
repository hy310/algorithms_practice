#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define MAX_SIZE 15

// ������ �̵����� ��ũ���Լ� (�ܼ�ġȯ
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

/*
bubble sort (�� �ں��� ���� ��)
5 3 8 1 2 7  (1,2 ��)
3 5 8 1 2 7  (2,3 ��)
3 5 8 1 2 7  (3,4 ��)
3 5 1 8 2 7
3 5 1 2 8 7
3 5 1 2 7 8  (1�ܰ� ��. �� �� 8�� ���ĵ� ����)
3 5 1 2 7 8  (2�ܰ� ����(1,2��). <3 5 1 2 7> �� ���� ���� ����)
3 1 5 2 7 8  (2,3 ��)
3 1 2 5 7 8  (3,4 ��)
3 1 2 5 7 8  (4,5 ��. 2�ܰ� ��. �� �� <7,8> ���� �Ϸ�)
1 3 2 5 7 8  (3�ܰ� ����(1,2��) <3 1 2 5> �� ���� ����)
1 2 3 5 7 8  (2,3 ��)
1 2 3 5 7 8  (3,4 ��. 3�ܰ� ��. <5,7,8> ���� �Ϸ�)
bubble ���� ��
*/

void bubble_sort(int list[], int n)
{
    int temp;
    printf("������ ���� : ");
    for (int t =0; t<n; t++)
        printf("%d ", list[t]);
    printf("\n\n-----------���� ���� ����-----------");

    for(int i= n-1; i>0; i--)
    {
        printf("\n %d �ܰ�>>", n-i);
        for(int j=0; j<i; j++)
            if(list[j] > list[j+1])
                SWAP(list[j], list[j+1], temp);
        for(int t=0; t<n; t++)
            printf("%3d ", list[t]);
    }
}

void main()
{
    int list[6] = {5,3,8,1,2,7};
    bubble_sort(list, 6);
} 