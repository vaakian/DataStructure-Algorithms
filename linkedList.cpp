#include<stdio.h>
#include<malloc.h>
#define FALSE 0
#define TRUE 1
typedef struct NODE
{
  /* data */
  int age;
  // link
  NODE* pNext;
  NODE* pPrev;
}NODE;

NODE* createNode(int data);
NODE* appendNode(NODE* pHead, NODE* pNode);
int travelList(NODE* pHead);


int main()
{
  NODE* pHead = createNode(656);
  travelList(pHead);
  for(int i = 0; i<10; i++)
  {
    NODE* pTemp = appendNode(pHead, createNode(i*20));
    printf("success: %d\n", pTemp->age);
  }
  printf("***TRAVELLIST***\n");
  travelList(pHead);
  return 0;
}

int travelList(NODE* pHead)
{
  if(NULL == pHead) {
    return FALSE;
  } else {
    printf("%9d\n", pHead->age);
    if(NULL != pHead->pNext) {
      travelList(pHead->pNext);
    }
    return TRUE;
  }
}
NODE* createNode(int data)
{
  NODE* pNode = (NODE*)malloc(sizeof(NODE));
  if(pNode) {
    pNode->pNext = NULL;
    pNode->pPrev = NULL;
    pNode->age = data;
    return pNode;
  } else {
    return NULL;
  }
}

NODE* appendNode(NODE* pHead, NODE* pNode)
{
  if(NULL == pHead || NULL == pNode) {
    return FALSE;
  } else {
    NODE* pTemp = pHead;
    while(NULL != pTemp->pNext)
    {
      pTemp = pTemp->pNext;
    }
    pTemp->pNext = pNode;
    return pNode;
  }
}
// NODE* deleteNode(NODE **ppHead, int age)
// {
//   if()
// }