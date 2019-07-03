#include<stdio.h>
#include<malloc.h>
// https://leetcode-cn.com/problems/maximum-binary-tree/
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct TreeNode* create(int val){
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->left = node->right = NULL;
    node->val = val;
    return node;
}
void construct(int *nums, struct TreeNode** root, int left, int right){
	if(left > right)
        return;
    // 找到了最大值索引
   int maxIndex = left;
    int i = left+1;
    for(; i<=right; ++i) {
        if(nums[i] > nums[maxIndex]) maxIndex = i;
    }
    // 把当前节点设为最大值
    *root = create(nums[maxIndex]);
    // 继续遍历数组左右
	construct(nums, &((*root)->left), left, maxIndex-1);
    construct(nums, &((*root)->right), maxIndex+1, right);
}
struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize){
    struct TreeNode* root;
    construct(nums, &root, 0, numsSize-1);
    return root;
}
void travel(struct TreeNode* root) {
    if(!root) return;
    printf("%d, ", root->val);
    travel(root->left);
    travel(root->right);
}
int main()
{
    struct TreeNode* root;
    int nums[10] = {23, 2, -4, 5, 28, 50, 150, 15, 60, 5565};
    root = constructMaximumBinaryTree(nums, 10);
    travel(root);
    return 0;
}