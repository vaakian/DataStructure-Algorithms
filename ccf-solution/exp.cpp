#include<bits/stdc++.h>
using namespace std;
// 逆波兰表达式->二叉树->求解
typedef struct NODE {
    char val;
    NODE* left;
    NODE* right;
}NODE;

NODE* create_node(char val) {
    NODE* node = (NODE*)malloc(sizeof(NODE));
    node->val = val;
    return node;
}
NODE* parse(string exp) {
    stack<NODE*> s;
    for(auto c: exp) {
        if(isdigit(c)) {
            s.push(create_node(c-0x30)); // 转数字
        } else {
            NODE* new_node = create_node(c);
            new_node->right = s.top();
            s.pop();
            new_node->left = s.top();
            s.pop();
            s.push(new_node);
        }
    }
    return s.top();
}
int calc(int x, char p, int y)
{
    printf("%d %c %d\n", x, p, y);
    int result;
    switch (p)
    {
    case '+':
        result = x + y;
        break;
    case '-':
        result = x - y;
        break;
    case '*':
        result = x * y;
        break;
    case '/':
        result = x / y;
        break;

    default:
        break;
    }
    return result;
}
bool isopt(char c) {
    for(auto _c: "+-*/") if(_c == c) return true;
    return false;
}
int calc_next(NODE* root) {
    if(!isopt(root->val)) return root->val;
    return calc(calc_next(root->left), root->val, calc_next(root->right));
}
int main()
{
    string exp = "48+5*";
    NODE* root = parse(exp);
    // int result = calc_next(root);
    cout<<calc_next(root)<<endl;
    return 0;
}