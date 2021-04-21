#include <stdio.h>
#include <stdlib.h>

int fcn(int n)
{
    if (n==1)
        return 1;
    else if (n==2)
        return 2;
    else
    {
        int a = fcn(n-1);
        int b = 2*fcn(n-2);
        int c = 4*n;

        if (a>=b && a>=c)
            return a + 10;
        else if (b>=a && b>=c)
            return b + 10;
        else
            return c + 10;
    }
}

void main()
{
    printf("f(n) 의 결과는 %d 입니다\n", fcn(6));
}