#include <stdio.h>
#include <stdlib.h>

void CountElements(int A[], int n)
{
    int c1 = 0;
    int c2 = 0;
    int c3 = 0;

    for(int i=0; i<n; i++)
    {
        int d = 0;
        d = abs(A[i]) % 10;

        if(0 <= d && d <= 4)
            c1++;
        if(4 <= d && d <= 8)
            c2++;
        if(d == 9)
            c3++;
    }
    printf("last digit 이 0-4 인 원소 갯수는 %d 개입니다.\n", c1);
    printf("last digit 이 4-8 인 원소 갯수는 %d 개입니다.\n", c2);
    printf("last digit 이 9 인 원소 갯수는 %d 개입니다.\n", c3);
}

void main()
{
    int A[] = {0, -10, -18, -16};
    CountElements(A, 4);    
}