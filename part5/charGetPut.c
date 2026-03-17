#include <stdio.h>

int main(void)
{
    char ch;
    char str[100];
    printf("문자를 입력하세요: ");
    ch = getc(stdin);
    ch = fgetc(stdin);
    ch = getchar();
    printf("%d, %d, %d", stdin->_fileno, stdout->_fileno, stderr->_fileno);
    printf("입력한 문자는 %c 입니다.\n", ch);
    while(getchar() != '\n');
    ch = fgetc(stdin);
    printf("입력한 문자는 %c 입니다.\n", ch);
    scanf("%s", str);
    printf("입력한 문자는 %s 입니다.\n", str);

    return 0;
}