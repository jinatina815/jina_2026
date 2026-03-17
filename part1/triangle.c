#include <stdio.h>

int main(void)
{
    int lenght;
    int height;
    int area;

    printf("삼각형의 길이 와 높이를 넣으세요 : ");
    scanf("%1f %1f", &lenght, &height);
    area = lenght * height / 2;
    printf("삼각형의 넓이는 : %f\n", area);
    return 0;
}