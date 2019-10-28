//
// Created by John Killer on 2019/10/28.
//

#include "iostream"

using namespace std;
struct HuffmanNode {
    char value;
    int weight;
};
typedef struct Node {
    HuffmanNode data;
    Node *left;
    Node *right;
} *HuffmanTree;

HuffmanNode nodes[] =
        {{'A', 5},
         {'B', 29},
         {'C', 7},
         {'D', 8},
         {'E', 14},
         {'F', 23},
         {'G', 3},
         {'H', 11}};

HuffmanTree CreateHuffmanTree() {
    HuffmanTree root = (HuffmanTree)malloc(sizeof(Node));

}
int main() {
    for(auto node : nodes) {
        cout<<node.value<<endl;
    }
}

