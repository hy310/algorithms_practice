#include <stdio.h>
 
int main()
{
    unsigned char num1 = 3;     //  3: 0000 0011
    unsigned char num2 = 24;    // 24: 0001 1000
    unsigned char num3 = 36;    // 36: 0010 0100

    unsigned char num4 = 32;
 
    printf("%u\n", num1 << 3);  // 24: 0001 1000: num1�� ��Ʈ ���� �������� 3�� �̵�
    printf("%u\n", num2 >> 2);  //  6: 0000 0110: num2�� ��Ʈ ���� ���������� 2�� �̵�
    printf("%u\n", num3 >> 2);

    num4 = num4 >> 4 << 1;
    printf("%u\n", num4);
    
    return 0;
}