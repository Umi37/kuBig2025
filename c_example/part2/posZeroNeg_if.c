// 숫자를 입력 받아서 양수, 제로, 음수를 출력하는 프로그램
// if else 구문으로 만드세요.
// printf 는 한 번 만 쓰세요.

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int num;
    char *string;
    printf("숫자를 넣으시오: ");
    scanf("%d", &num);
    if (num>0){
        string = "양수";
    }   
    else if(num < 0){
        string = "음수";
    }   
    else{
        string = "Zero";
    }
    
    printf("%d 이 숫자는 %s 입니다.", num, string);

    return 0 ;
    
}