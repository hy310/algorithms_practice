#include <stdio.h>
#include <stdbool.h>

int main()
{
    bool b1 = true;
    bool b2 = false;

    if (b1 && b1)
        printf("Âü\n");
    else
        printf("°ÅÁş\n");
    
    printf("%s\n", b2 || b2 ? "Âü" : "°ÅÁş");

    return 0;
}