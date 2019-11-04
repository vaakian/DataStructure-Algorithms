//
// Created by John Killer on 2019/10/28.
//

#include "iostream"
#include "algorithm"

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
        {{'G', 3},
         {'A', 5},
         {'C', 7},
         {'D', 8},
         {'H', 11},
         {'E', 14},
         {'F', 23},
         {'B', 29}};

HuffmanTree CreateHuffmanTree() {
    HuffmanTree root = (HuffmanTree) malloc(sizeof(Node));
    HuffmanTree temp = (HuffmanTree) malloc(sizeof(Node));
    temp->data.weight = nodes[0].weight + nodes[1].weight;
    temp->data.value = -1;
    temp->left = nodes[0];
    temp->right = nodes[1];
    for (int i = 2; i < 7; ++i) {
        HuffmanTree tempNew = (HuffmanTree) malloc(sizeof(Node));
        tempNew->data.weight = temp->data.weight + nodes[2].weight;
        tempNew->data.value = -1;
        if (temp->data.weight < nodes[2].weight) {

        }
    }
}

int main() {
    for (auto node : nodes) {
        cout << node.value << endl;
    }
}

