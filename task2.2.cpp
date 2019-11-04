#include "iostream"
#include "stdlib.h"
#include "string.h"

//typedef char LinkStackType;
//定义链栈的节点结构
typedef struct LinkStackNode {
    char data[20];
    LinkStackNode *next;
} *LinkStack;

void InitLinkStack(LinkStack &stack) {
    stack = NULL;
}

LinkStack CreateNode(const char *data) {
    LinkStack newNode = (LinkStack) malloc(sizeof(LinkStackNode));
    if (newNode) {
        strcpy(newNode->data, data);
        newNode->next = NULL;
    }
    return newNode;
}

// 头插入栈
void Push(LinkStack &stack, const char *data) {
    LinkStack newNode = CreateNode(data);
    newNode->next = stack;
    stack = newNode;
}
// 头删出栈

void Pop(LinkStack &stack, char *rt) {
    strcpy(rt, stack->data);
    LinkStack tempStack = stack;
    stack = stack->next;
    free(tempStack);
}

void GetTop(LinkStack &stack, char *rt) {
    if(stack) {
        strcpy(rt, stack->data);
    } else {
        strcpy(rt, "");
    }
}

int IsEmpty(LinkStack stack) {
    return stack == NULL;
}
int IsFull(LinkStack stack) {
//    ？？？满不了
}
int main() {
    LinkStack stack;
    InitLinkStack(stack);
    Push(stack, "China");
    Push(stack, "Japan");
    Push(stack, "Frawnce");
    Push(stack, "India");
    Push(stack, "Australia");
    char rt[20];
    while(!IsEmpty(stack)) {
        Pop(stack, rt);
        printf("弹出：%s ", rt);
        GetTop(stack, rt);
        printf("栈顶：%s ", rt);
        printf("栈状态：%s\n", IsEmpty(stack) ? "空": "非空");
    }
    return 0;
}