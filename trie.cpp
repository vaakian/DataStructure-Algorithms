#include<iostream>
using namespace std;
typedef struct NODE {
    char c;
    int isEmpty;
    struct NODE *child[26];
}NODE;
void TravelTrie(NODE *root)
{
    if(NULL != root) {
        cout<<root->c<<endl;
        for(auto pTemp: root->child)
        {
            if(NULL != pTemp) TravelTrie(pTemp);
            else return;
        }
    }
}
NODE* InsertNode(NODE *root, NODE *node)
{
    /*
        如果对比到root->c == node->c，不用插入，返回该节点，给下一个字母插入。
        若没对比到，则遍历子节点
        遍历到子最后没对比到，则插入。
     */
    if(NULL != root) {
        // if(root->isEmpty) {
        //     root->child[0]
        //     return root;
        // }
        if(root->c == node->c) return root;
        else {
            
            for(auto ptemp: root->child)
            {
                if(NULL != ptemp) 
                    return InsertNode(ptemp, node);
            }

            // 全部没遍历到，就插入，怎么做？
        }

    }
}
int main()
{
    char search[100] = "afde";
    NODE root = {'a'};
    // Todo
    return 0;
}