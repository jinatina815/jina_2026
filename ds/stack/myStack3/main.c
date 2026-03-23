#include <stdio.h>
#include "stack3.h"

int main(void)
{
    Stack s1, s2;

    initStack(&s1, 10);
    initStack(&s2, 100);

    push(&s1, 100);
    push(&s1, 200);
    push(&s1, 300);
    
    printf("첫 pop(): 리턴 값: %d\n", pop(&s1)); // 100
    printf("두번째 pop(): 리턴 값: %d\n", pop(&s1)); // 200
    printf("세번째 pop(): 리턴 값: %d\n", pop(&s1)); // 300

    push(&s2, 700);
    push(&s2, 800);
    push(&s2, 900);

    printf("첫 pop(): 리턴 값: %d\n", pop(&s2)); // 700
    printf("두번째 pop(): 리턴 값: %d\n", pop(&s2)); // 800
    printf("세번째 pop(): 리턴 값: %d\n", pop(&s2)); // 900

    cleanupStack(&s1);
    cleanupStack(&s2);
    return 0;
}