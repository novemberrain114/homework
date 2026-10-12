#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;                       // 节点存储的数据
    struct TreeNode *left;          // 左子树指针
    struct TreeNode *right;         // 右子树指针
} TreeNode;
TreeNode* create_node(int value){
    TreeNode* newnode=(TreeNode*)malloc(sizeof(TreeNode));
    if(newnode==NULL){
        return;
    }
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
void preorder(TreeNode **tree){
    printf("%d ",(*tree)->data);
    if((*tree)->left!=NULL){
        preorder((*tree)->left);
    }
    if((*tree)->right!=NULL){
        preorder((*tree)->left);
    }
}
void inorder(TreeNode **tree){
    if((*tree)->left!=NULL){
        inorder((*tree)->left);
    }
    printf("%d ",(*tree)->data);
    if((*tree)->right!=NULL){
        inorder((*tree)->left);
    }
}
void postorder(TreeNode **tree){
    if((*tree)->left!=NULL){
        postorder((*tree)->left);
    }
    if((*tree)->right!=NULL){
        postorder((*tree)->left);
    }
    printf("%d ",(*tree)->data);
}
int depth(TreeNode *root, int current_depth, int max_depth) {
    if (root == NULL) {
        return max_depth;
    }
    if (current_depth > max_depth) {
        max_depth = current_depth;
    }
    int left_max = depth(root->left, current_depth + 1, max_depth);
    int right_max = depth(root->right, current_depth + 1, left_max);
    return right_max;
}