#include <stdio.h>

int main(void)
{
    FILE *a; // file 을 저장할 때
    a = fopen("test dat", "w");
    if ( a == NULL){
        printf("cna't open file\n");
        return 1; // 지금까지의 리턴은 0으로 했는데, 리턴 0의 의미는 다른 프로그램이나 프로그래머들이 이 프로그램이 정상 종료되었다는 것을 알리기위해
    }
    fprintf(a, "이것은 파일로 저장되는 예시 데이터 입니다.");
    fclose(a);
    
    return 0;
}