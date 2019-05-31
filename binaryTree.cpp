#include<iostream>
#define MALLOC_NODE (NODE*)malloc(sizeof(NODE))
using namespace std;
typedef struct NODE {
    int age;
    NODE* pLeft;
    NODE* pRight;
} NODE;
NODE* createNode(int age);
NODE* insertData(NODE* pRoot, int age);
void travelTree(NODE* pRoot, string orient);
int getTreeDeepth(NODE* pRoot)
{
    if(pRoot) {
        int leftDeepth = getTreeDeepth(pRoot->pLeft);
        int rightDeepth = getTreeDeepth(pRoot->pRight);
        return 1 + (leftDeepth >= rightDeepth ? leftDeepth: rightDeepth);
    } else {
        return 0; 
    }
}int getTreeDeepth(NODE* pRoot);
int main()
{
    int data[] = {125,456,498,54,-45,443};
    NODE* pRoot = createNode(121233);
    for(auto tempData: data)
        insertData(pRoot, tempData);
    auto a = 0;
    while(a!=999) {
        cin>>a;
        insertData(pRoot, a);
        cout<<"***traveling***"<<endl;
        travelTree(pRoot, "root");
        cout<<"deepth: "<<getTreeDeepth(pRoot)<<endl;
    }
    travelTree(pRoot, "root");
    return 0;
}

NODE* createNode(int age)
{
    NODE* pNode = MALLOC_NODE;
    if(pNode) {
        // 内存分配成功
        pNode->pLeft = pNode->pRight = NULL;
        pNode->age = age;
        return pNode;
    } else {
        return NULL;
    }
}

NODE* insertData(NODE* pRoot, int age)
{
    if(pRoot) {
        if(age < pRoot->age) {
            if(NULL == pRoot->pLeft) {
                NODE* pNode = createNode(age);
                pRoot->pLeft = pNode;
                return pNode;
            } else {
                return insertData(pRoot->pLeft, age);
            }
        } else {
            if(NULL == pRoot->pRight) {
                NODE* pNode = createNode(age);
                pRoot->pRight = pNode;
                return pNode;
            } else {
                return insertData(pRoot->pRight, age);
            }
        }
    }
    return NULL;
}

void travelTree(NODE* pRoot, string orient)
{
    cout<<orient<<"=>"<<pRoot->age<<endl;
    if(pRoot->pLeft) travelTree(pRoot->pLeft, "left");
    if(pRoot->pRight) travelTree(pRoot->pRight, "right");
<<<<<<< HEAD
=======
}
int getTreeDeepth(NODE* pRoot)
{
    if(pRoot) {
        int leftDeepth = getTreeDeepth(pRoot->pLeft);
        int rightDeepth = getTreeDeepth(pRoot->pRight);
        return 1 + (leftDeepth >= rightDeepth ? leftDeepth: rightDeepth);
    } else {
        return 0;
    }
>>>>>>> treeDeepth
}