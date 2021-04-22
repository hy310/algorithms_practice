#include <stdio.h>

int main()
{
    float num1 = 0.01f;               // float는 숫자 뒤에 f를 붙임
                                     

    double num2 = 3867.2158208888;    // double은 숫자 뒤에 아무것도 붙이지 않음 
                                     

    long double num3 = 9.327513l;     // long double은 숫자 뒤에 l을 붙임
                                     

    // float와 double은 %f로 출력, long double은 %Lf로 출력
    printf("%f %.15f %Lf\n", num1, num2, num3);    // 0.100000 3867.215820 9.327513

    return 0;
}