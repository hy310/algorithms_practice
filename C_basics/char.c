#include <stdio.h>
 
int main()
{
    char c1 = 'a';    // 문자 변수를 선언하고 문자 a를 저장
    char c2 = 'b';    // 문자 변수를 선언하고 문자 b를 저장
    char c3 = 97;     // a 의 ASCII 코드값 97 저장
    char c4 = '0';    // 문자 0 저장
    char c5 = 0;      // 숫자 0 저장
 
    // char를 %c로 출력하면 문자가 출력되고, %d로 출력하면 정숫값이 출력됨
    printf("%c, %d\n", c1, c1);    // a, 97: a의 ASCII 코드값은 97
    printf("0x%x\n", c1);          // a를 16진수로 출력
    printf("%c, %d\n", c2, c2);    // b, 98: b의 ASCII 코드값은 98
    printf("%c\n", c3);

    printf("%c %d\n", c4, c4);     // 0  48 : 문자 상태로 0이 출력
                                   // 문자 0의 아스키코드 48 출력
    printf("%c %d\n", c5, c5);     // 0 : 아스키코드 0은 널문자이므로 아무것도 출력 X, 정수 0 
    return 0;
}