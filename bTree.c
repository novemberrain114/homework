#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_TREE_SIZE 100
/*
 * 顺序存储二叉树结点
 * - data：结点数据
 * - used：当前位置是否有结点
 */
typedef struct {
    int data;
    bool used;
} SeqTreeNode;

/*
 * 顺序存储二叉树
 * - nodes：结点数组
 * - size：数组最大容量
 */
typedef struct {
    SeqTreeNode nodes[MAX_TREE_SIZE+1];
    int size;
} SeqBiTree;



void init_tree(SeqBiTree *tree){
    if(tree==NULL){
        return;
    }
    tree->size=MAX_TREE_SIZE;
    for(int i=0;i<=MAX_TREE_SIZE;i++){
        tree->nodes[i].used = false;
    }
}

bool set_root(SeqBiTree *tree, int value){
    if(tree==NULL){
        return false;
    }
    if(tree->nodes[1].used == true){
        return false;
    }
    tree->nodes[1].used=true;
    tree->nodes[1].data=value;
    return true;
}
bool set_left_child(SeqBiTree *tree, int parent_node, int value){
    if(tree==NULL){
        return false;
    }
    if(parent_node*2>MAX_TREE_SIZE){
        return false;
    }
    if(tree->nodes[parent_node*2].used == true){
        return false;
    }
    tree->nodes[parent_node*2].used=true;
    tree->nodes[parent_node*2].data=value;
    return true;
}
bool set_right_child(SeqBiTree *tree, int parent_node, int value){
    if(tree==NULL){
        return false;
    }
    if(parent_node*2+1>MAX_TREE_SIZE){
        return false;
    }
    if(tree->nodes[parent_node*2+1].used == true){
        return false;
    }
    tree->nodes[parent_node*2+1].used=true;
    tree->nodes[parent_node*2+1].data=value;
    return true;
}
void level_order(SeqBiTree *tree){
    if(tree==NULL){
        return;
    }
    for(int i=1,j=1;i<=MAX_TREE_SIZE;i++){
        if(tree->nodes[i].used==true){
            printf("%d ",tree->nodes[i].data);
        }
        else{
            printf("  ");
        }
        if(i==j){
            printf("\n");
            j=2*j+1;
        }
    }
}
int main(){
    SeqBiTree tree;
    init_tree(&tree);
    set_root(&tree, 1);
    set_left_child(&tree, 1, 2);
    set_right_child(&tree, 1, 3);
    set_left_child(&tree, 2, 4);
    set_right_child(&tree, 3, 7);
    level_order(&tree);
    return 0;
}