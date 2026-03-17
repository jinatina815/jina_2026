// 입력받은 char 가 알파벳인지 아닌지 출력하세요!
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    char ch;
    printf("char 를 입력하세요: ");
    scanf("%c", &ch);

    bool isAlpha;
    isAlpha= ('A' <= ch && ch <= 'Z') || ('a' <= ch && ch <= 'z');
    printf("%c 는 %s\n", ch, isAlpha? "알파벳 입니다." : "알파벳 아닙니다.");
    return 0;
}