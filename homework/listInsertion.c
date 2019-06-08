#include<stdio.h>
#include<malloc.h>
typedef struct NODE {
    int digit;
    struct NODE *next;
}NODE;

// 头插法，需返回新的头
void Prepend(NODE *(*head), int digit)
{
    NODE *newHead = (NODE*)malloc(sizeof(NODE));
    // 内存分配成功
    if(newHead) {
        newHead->digit = digit;
        newHead->next = *head;
        // 解一次引用，指针目标类型是NODE*，则修改的是原变量的值
        // 使*head指向新的头
        *head = newHead;
    }
}
void Append(NODE* (*head), int digit)
{
    // 解引用
    NODE *pTemp = *head;
    NODE *newNode = (NODE*)malloc(sizeof(NODE));
    if(NULL != newNode) {
        if(NULL == *head) {
            *head = newNode;
        } else {
            newNode->digit = digit;
            newNode->next = NULL;
            // 迭代到尾部
            while (pTemp->next)
            {
                /* code */
                pTemp = pTemp->next;
            }
            pTemp->next = newNode;
        }
    }
}
void TravelList(NODE *head)
{
    printf("%d\n", head->digit);
    if(head->next) TravelList(head->next);
}
int main()
{
    NODE *head = NULL;
    Prepend(&head, 15);
    Prepend(&head, 5);
    Prepend(&head, -215);
    Prepend(&head, 655);
    Append(&head, 123);
    TravelList(head);
    /* output:
    655
    -215
    5
    15
    123
     */
    return 0;
}