#include <stdio.h>

int main()
{
    float num1 = 0.01f;               // float�� ���� �ڿ� f�� ����
                                     

    double num2 = 3867.2158208888;    // double�� ���� �ڿ� �ƹ��͵� ������ ���� 
                                     

    long double num3 = 9.327513l;     // long double�� ���� �ڿ� l�� ����
                                     

    // float�� double�� %f�� ���, long double�� %Lf�� ���
    printf("%f %.15f %Lf\n", num1, num2, num3);    // 0.100000 3867.215820 9.327513

    return 0;
}