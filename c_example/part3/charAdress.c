#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char * str1= "apple";   // 변하지 않는 메모리
    char str2[] = "apple";  // 스택에 있는 변할수 있는 메모리
    char *str3;
    str3 = (char *)malloc(sizeof(char)* 6);
    strcpy(str3, str2);
    printf("apple : %s adress %p\n", "apple", "apple"); // str1과 같은 주소로 출력
    printf("str1 : %s adress: %p\n", str1, str1);
    printf("str2 : %s adress: %p\n", str2, str2);
    printf("str3 : %s adress: %p\n", str3, str3);

    free(str3);
    return 0;
}