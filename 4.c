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
        if(x < t->value) {
            t->lchild = make_node(x, NULL, NULL);
        } else if (x > t->rchild) {
            t->rchild = make_node(x, NULL, NULL);
        } else {
            printf("Something went wrong. Aborting...");
            abort();
        }
        
    }
    if(x < t->value) {
        Insert(x, t->lchild);
    } else {
        Insert(x, t->rchild);
    }
}

void Remove(int x, tree_node* t) {
    ;
}

bool Contains(int x, tree_node* t) {
    ;
}

tree_node* Initialize(tree_node* t) {
    tree_node *no = (tree_node*) malloc(sizeof(tree_node));
    no->lchild = NULL;
    no->rchild = NULL;
    printf("Initialized!\n");

    return no;
}

bool Full(tree_node* t) {
    ;
}

bool Empty(tree_node* t) {
    return (t->lchild == NULL && t->rchild == NULL);
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

    root = Initialize(tree);


    if(Empty(root)) {
        printf("It's empty!\n");
    }

    free_tree(root);
    return 0;
}