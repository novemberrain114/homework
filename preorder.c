#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;                       // 节点存储的数据
    struct TreeNode *left;          // 左子树指针
    struct TreeNode *right;         // 右子树指针
} TreeNode;
typedef struct Stack {
    TreeNode **arr;
    int top;
    int capacity;
} Stack;
Stack *createStack(int capacity) {
    Stack *stack = malloc(sizeof(Stack));
    stack->arr = malloc(sizeof(TreeNode *) * capacity);
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}
int isEmpty(Stack *stack) {
    return stack->top == -1;
}
void push(Stack *stack, TreeNode *node) {
    if (stack->top == stack->capacity - 1) {
        return;
    }
    stack->arr[++stack->top] = node;
}
TreeNode *pop(Stack *stack) {
    if (isEmpty(stack)) {
        return NULL;
    }
    return stack->arr[stack->top--];
}

void preorderTraversal(TreeNode *root){
    Stack* stack=createStack(100);
    push(stack, root);
    while(!isEmpty(stack)){
        TreeNode* node=pop(stack);
        printf("%d ",node->data);
        if(node->left!=NULL){
            preorderTraversal(node->left);
        }
        if(node->right!=NULL){
            preorderTraversal(node->right);
        }
    }
    free(stack->arr);
    free(stack);
}