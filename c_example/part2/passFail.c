// 60 이상이면 합격 을 출력
// 함수는 인자를 받을 수 있다

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("인자를 하나 넣어서 실행하세요.\n");
        return 0 ;
    }
    printf("score: %s --- %s\n", argv[1], atoi(argv[1]) >= 60 ? "합격" : "실패"); //argument value **함수가 인자를 받을 때 취하는 형식 공부해보기!!
    return 0 ;
    
}