#include <stdio.h>
#include <unistd.h>

int main(void)
{
    char ch = 'a';

    printf("프로그램 시작\n");
    putchar(ch);
    fflush(stdout);
    sleep(1);
    printf("프로그램 실행후\n");
    putc(ch, stdout);
    fflush(stdout);
    sleep(1);
    char *string1 = "스트링1 배열입니다.";
    puts(string1);
    sleep(1);
    printf("프로그램 끝입니다.");
    fputs(string1, stdout);
    sleep(1);
    printf("프로그램 끝입니다.");
    return 0;
}