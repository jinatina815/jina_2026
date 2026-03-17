// a ~ b 까지의 합을 출력 하세요. for 문을 사용해서

#include <stdio.h>

int main(void)
{
int a, b;
    printf("정수 a 와 b를 넣으세요:");
    scanf("%d %d", &a, &b);

    int sum = 0;
    for(int i = a; i <= b; ++i)
    {
        sum = sum + i + 1;
    }
    printf("%d 부터 %d까지의 합은 : %d\n", a, b, sum);
    return 0;
}

