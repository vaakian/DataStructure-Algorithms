#include <iostream>

using namespace std;
typedef struct Node {
    int data;
    Node *left;
    Node *right;
} *BinaryTree;
string tree = "EI#JG###BK##ACF##D###";
int cursor = 0;

BinaryTree CreateTree(BinaryTree bt);

void PreOrder(BinaryTree root);

void InOrder(BinaryTree root);

void PostOrder(BinaryTree root);

int CountNode(BinaryTree root);

int CountLeaf(BinaryTree root);

int CountTwo(BinaryTree root);

int CountSingle(BinaryTree root);

int main() {
    BinaryTree root;
//    EI#JG###BK##ACF##D###
    root = CreateTree(root);
//    PreOrder(root);
//    putchar('\n');
//    InOrder(root);
//    putchar('\n');
//    PostOrder(root);

//    计算二叉树深度、所有结点总数、叶子结点数、双孩子结点个数、单孩子结点个数。
    cout << CountLeaf(root) << endl;
    cout << CountTwo(root) << endl;
    cout << CountSingle(root) << endl;

    return 0;
}

BinaryTree CreateTree(BinaryTree bt) {
    char c;
    c = tree[cursor++];
    if (c == '#') {
        bt = NULL;
    } else {
        bt = (BinaryTree) malloc(sizeof(bt));
        bt->data = c;
        bt->left = CreateTree(bt->left);
        bt->right = CreateTree(bt->right);
    }
    return bt;
}

void PreOrder(BinaryTree root) {
    if (root) {
        printf("%c ", root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void InOrder(BinaryTree root) {
    if (root) {
        InOrder(root->left);
        printf("%c ", root->data);
        InOrder(root->right);
    }
}

void PostOrder(BinaryTree root) {
    if (root) {
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%c ", root->data);
    }
}

int CountSingle(BinaryTree root) {
    return NULL == root ? 0 : (root->left == NULL ^ root->right == NULL)
                              + CountSingle(root->left) + CountSingle(root->right);
}

int CountNode(BinaryTree root) {
    return NULL == root ? 0 : 1 + CountNode(root->left) + CountNode(root->right);
}

int CountLeaf(BinaryTree root) {
    return NULL == root ? 0 : !(root->left || root->right)
                              + CountLeaf(root->left) + CountLeaf(root->right);
}

int CountTwo(BinaryTree root) {
    return NULL == root ? 0 : (root->left && root->right)
                              + CountTwo(root->left) + CountTwo(root->right);
}
