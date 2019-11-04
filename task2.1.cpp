#include "iostream"
#include "stdlib.h"
#include "string.h"

#define STACK_SIZE 100
struct Stack {
    char base[STACK_SIZE];
    int top;
};

int IsEmpty(Stack stack) {
    return stack.top == 0;
}

int IsFull(Stack stack) {
    return stack.top == STACK_SIZE;
}

Stack CreateStack() {
    Stack stack;
    stack.top = 0;
    return stack;
}

void Push(Stack &stack, char c) {
    if (!IsFull(stack)) {
        stack.base[stack.top++] = c;
    }
}

char Pop(Stack &stack) {
    if (!IsEmpty(stack)) {
        return stack.base[--stack.top];
    }
    return '#';
}

char GetTop(Stack stack) {
    if(!IsEmpty(stack)) {
        return stack.base[stack.top - 1];
    }
}

int main() {
    char c;
    Stack stack = CreateStack();
    printf("ÇëÊäÈëÕ»ÔªËØ£º");
    while ((c = getchar()) != '\n') {
        Push(stack, c);
    }
    while (!IsEmpty(stack)) {
        printf("µ¯³ö£º%c ", Pop(stack));
        printf("Õ»¶¥£º%c ", GetTop(stack));
        printf("Õ»×´Ì¬£º%s\n", IsEmpty(stack) ? "¿Õ": "·Ç¿Õ");
    }
}