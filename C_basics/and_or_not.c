#include <stdio.h>
 
int main()
{
    printf("%d\n", 1 && 1);    // 1: 1 AND 1Àº Âü
    printf("%d\n", 1 && 0);    // 0: 1 AND 0Àº °ÅÁş
    printf("%d\n", 0 && 1);    // 0: 0 AND 1Àº °ÅÁş
    printf("%d\n", 0 && 0);    // 0: 0 AND 0Àº °ÅÁş
    printf("%d\n", 2 && 3);    // 1: 2 AND 3Àº Âü
 
    printf("%d\n", 1 || 1);    // 1: 1 OR 1Àº Âü
    printf("%d\n", 1 || 0);    // 1: 1 OR 0Àº Âü
    printf("%d\n", 0 || 1);    // 1: 0 OR 1Àº Âü
    printf("%d\n", 0 || 0);    // 0: 0 OR 0Àº °ÅÁş
    printf("%d\n", 2 || 3);    // 1: 2 OR 3Àº Âü

    printf("%d\n", !1);    // 0: NOT 1Àº °ÅÁş
    printf("%d\n", !0);    // 1: NOT 0Àº Âü
    printf("%d\n", !3);    // 0: NOT 3Àº °ÅÁş

    int num1 = 20;
    int num2 = 10;
    int num3 = 30;
    int num4 = 15;
    
    printf("%d\n", (num1 > num2) && (num3 > num4));
    printf("%d\n", (num1 > num2) && (num3 < num4));
    printf("%d\n", (num1 > num2) || (num3 < num4));
    printf("%d\n", (num1 < num2) || (num3 < num4));

    return 0;
}