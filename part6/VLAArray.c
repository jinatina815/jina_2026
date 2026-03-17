#include <stdio.h>
#include <stdbit.h>

int main(void)
{
    int size;
    scanf("%d", &size);

    int num[size];

    for (int i = 0; i < size;++i)
    {
        num[i] = i + i;
    }
    for(int i = 0; i < size;++i)
    {
        printf("%d, ", num[i]);
    }
    printf("\n");
    return 0;
}