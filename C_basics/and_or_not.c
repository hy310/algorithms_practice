#include <stdio.h>
 
int main()
{
    printf("%d\n", 1 && 1);    // 1: 1 AND 1�� ��
    printf("%d\n", 1 && 0);    // 0: 1 AND 0�� ����
    printf("%d\n", 0 && 1);    // 0: 0 AND 1�� ����
    printf("%d\n", 0 && 0);    // 0: 0 AND 0�� ����
    printf("%d\n", 2 && 3);    // 1: 2 AND 3�� ��
 
    printf("%d\n", 1 || 1);    // 1: 1 OR 1�� ��
    printf("%d\n", 1 || 0);    // 1: 1 OR 0�� ��
    printf("%d\n", 0 || 1);    // 1: 0 OR 1�� ��
    printf("%d\n", 0 || 0);    // 0: 0 OR 0�� ����
    printf("%d\n", 2 || 3);    // 1: 2 OR 3�� ��

    printf("%d\n", !1);    // 0: NOT 1�� ����
    printf("%d\n", !0);    // 1: NOT 0�� ��
    printf("%d\n", !3);    // 0: NOT 3�� ����

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