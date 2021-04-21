#include <stdio.h>

void test1(int i, int j)
{
    while(i & j)
    {
        printf("loop 1\n");
        i--;
        j++;
    }
}

void test2(int i, int j)
{
    while(i | j)
    {
        printf("loop 2\n");
        i--;
    }
}

void test3(int i, int j)
{
    while(i&&j)
    {
        printf("loop3\n");
        i--;
        j++;
    }
}

int main()
{
    float a = 11.1;
    float b = 0.3;
    int c = 1;

    printf("a: %f, b: %f, c:%d\n", a, b, c);

    test1(a,c);
    test2(a,b);
    test3(a,c);

    printf("a: %f, b: %f, c:%d\n", a, b, c);    

    return 0;
}