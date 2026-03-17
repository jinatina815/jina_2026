#include <stdio.h>

int main(void)
{
    // 출력합니다.
    char *string1 = "배열입니다.";
    char string2[100];
    printf("printf로 터미널에 출력합니다.! %s\n", string1);
    fprintf(stderr, "printf로 터미널에 출력합니다.! %s\n", string1);
    sprintf(string2, "배열에 문자열을 출력합니다. %d", 15);
    return 0;
}