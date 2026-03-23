#include <stdio.h>

void push(int data);
int pop(void);
int stack[50];
int tos = 0;

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

void push(int data)
{
    stack[tos] = data;
    ++tos;
}

int pop(void)
{
    --tos;
    return stack[tos];
}