#include <stdio.h>
#include <math.h>    // fmod 함수가 선언된 헤더 파일

int main()
{
    // 실수의 나머지 연산은 fmod, fmodf 함수를 사용

    double num1 = 10.843;
    double num2 = 3.79;
    printf("%f\n", fmod(num1, num2));    // 3.263000

    float num3 = 10.843f;
    float num4 = 3.79f;
    printf("%f\n", fmodf(num3, num4));    // 3.263000


    return 0;
}