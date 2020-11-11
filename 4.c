/*
 * The nodes (and leafs) in a binary tree are ordered such that,
 * the left child of a node is smaller or equal than the item of the node and the right
 * child is larger.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tree_node tree_node;

struct tree_node {
    int value;
    tree_node* lchild;
    tree_node* rchild;
};

tree_node* make_node(int x, tree_node* left, tree_node* right) { //incomplete
    tree_node *no = (tree_node*) malloc(sizeof(tree_node));
    no->lchild = left;
    no->rchild = right;
    no->value = x;

    return no;
}

void Insert(int x, tree_node* t) {
    if(t->lchild == NULL && t->rchild == NULL) {
        if(x <= t->value) {
            t->lchild = make_node(x, NULL, NULL);
        } else if (x > t->rchild) {
            t->rchild = make_node(x, NULL, NULL);
        } else {
            printf("Something went wrong. Aborting...");
            abort();
        }
    }
}

void Remove(int x, tree_node* t) {
    ;
}

bool Contains(int x, tree_node* t) {
    return true;
}

tree_node* Initialize(tree_node* t) {
    tree_node *no = (tree_node*) malloc(sizeof(tree_node));
    no->lchild = NULL;
    no->rchild = NULL;
    printf("Initialized!\n");

    return no;
}

bool Full(tree_node* t) {
    return false;
}

bool Empty(tree_node* t) {
    //If root is null node:
    if (t == NULL) {
        return true;
    }
    //If root is first node:
    if (t->rchild == NULL && t->lchild == NULL) {
        return true;
    }
    return false;
}

tree_node* free_tree(tree_node* t) {
    if(t->lchild != NULL) {
        free_tree(t->lchild);
    }
    if(t->rchild != NULL) {
        free_tree(t->rchild);
    }
    free(t);
    printf("Freed! ");
}

int main(void) {
    tree_node* tree;

    tree = make_node(NULL, NULL, NULL);

    tree_node* root;

    //Test A
    root = Initialize(tree);

    //Test B
    Insert(3, tree);
    Remove(3, tree);

    //Test C
    Insert(4, tree);
    if (Contains(4, tree)) {
        printf("Test C success\n");
    }
    Remove(4, tree);

    //Test D
    Insert(5, tree);
    Insert(6, tree);
    

    //Test E

    if(Empty(root)) {
        printf("It's empty!\n");
    }

    free_tree(root);
    return 0;
}