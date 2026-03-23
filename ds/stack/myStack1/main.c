#include "stack.h"

int main(void)
{
    push(100);
    push(200);
    push(300);

    printf("첫 pop() 리턴 값: %d\n", pop());
    printf("두번째 pop() 리턴 값: %d\n", pop());
    printf("세번째 pop() 리턴 값: %d\n", pop());
    return 0;
}