// 피라미드 형태 출력 이중 for 문 사용.
//      *
//     ***
//    *****
//   *******
//  *********

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    system("clear");
    int height;
    printf("피라미드의 높이를 넣으세요 : \n");
    scanf("%d", &height);
    
    for (int i = 1; i <= 5; ++i)
    {
        for (int j =1; j <= 5 - i; ++j)
        {
            printf(" ");
        }

        for (int j =1; j <= 2 * i - 1; ++j)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}