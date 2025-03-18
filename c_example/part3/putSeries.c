#include <stdio.h>

int main(void)
{
    FILE *fp;
    fp = fopen("output.txt", "a");
    if(fp == NULL)
    {
        printf("파일 열기 실패");
        return 1;
    }
    putc('A', fp);
    putc('A', stdout);
    fputc('B', fp);
    fputc('B', stdout);
    // gets deprecicate 지원 종료 (보안상의 이유로 쓸 수 없다.)
    fputs("puts로 문자가 간다.", fp);
    fputs("puts로 문자가 간다.", stdout);

    fprintf(fp, "printf 로 문자가 간다.");
    fprintf(stdout, "printf 로 문자가 간다.");
    // EOF == -1; -- end of file 의 약자,숫자상으로는 -1 (-1을 대신 써도 됨)
    fclose(fp);
    return 0;
}