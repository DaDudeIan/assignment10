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
    if (t != NULL) {
        if (x <= t->value) {
            if (t->lchild != NULL && t->rchild == NULL) {
                if (x >= t->lchild->value) {
                    t->rchild = make_node(x, NULL, NULL);
                } else {
                    Insert(x, t->lchild);
                }
            } else if (t->lchild == NULL) {
                t->lchild = make_node(x, NULL, NULL);
            } else {
                Insert(x, t->lchild);
            }
        } 

        else if (x > t->value) {
            if (t->rchild != NULL && t->lchild == NULL) {
                if (x < t->rchild->value) {
                    t->lchild = make_node(x, NULL, NULL);
                } else {
                    Insert(x, t->rchild);
                }
            } else if (t->rchild == NULL) {
                t->rchild = make_node(x, NULL, NULL);
            } else {
                Insert(x, t->rchild);
            }
        } 
        else {
            printf("Something went wrong. Aborting...");
            abort();
        }
        
    } else if (t == NULL) {
        return;
    } 
    else {
        abort();
    }
}

void Remove(int x, tree_node* t) {
    ;
}

bool Contains(int x, tree_node* t) {
    if (t == NULL) {
        return; 
    }

    if (t->value == x) {
        printf("Value found! '%d'\n", x);
        return true;
    }
    Contains(x, t->lchild);
    Contains(x, t->rchild);
    return false;
}

tree_node* Initialize(tree_node* t) {
    tree_node *no = (tree_node*) malloc(sizeof(tree_node));
    no->value = 0;
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

    tree = make_node(0, NULL, NULL);

    /*
    tree_node* root;

    root = Initialize(tree); */

    /*
    tree->lchild = make_node(2, NULL, NULL);
    tree->lchild->lchild = make_node(3, NULL, NULL);
    tree->lchild->rchild = make_node(4, NULL, NULL);
    tree->rchild = make_node(5, NULL, NULL);
    */

    
    Insert(7, tree);
    Insert(2, tree);
    Insert(9, tree);
    Insert(5, tree);
    Insert(3, tree);

    Contains(9, tree);
    Contains(3, tree);
    Contains(2, tree);
    Contains(5, tree);
    

    //Test A
    printf("=====Test A begin=====\n");
    Initialize(tree);

    printf("=====Test A end=======\n");

    /*
    //Test B
    printf("=====Test B begin=====\n");
    int x = 2;
    Insert(x, tree);
    Remove(x, tree);

    printf("=====Test B end=======\n");

    //Test C
    printf("=====Test C begin=====\n");
    int x = 3;
    Insert(x, tree);
    
    bool y = Contains(x, tree);
    if (y) {
        printf("Test C success\n");
    }

    Remove(x, tree);

    printf("=====Test C end=======\n");

    //Test D
    printf("=====Test D begin=====\n");
    int x = 4;
    int y = 5;
    Insert(x, tree);
    Insert(y, tree);
    Remove(x, tree);

    if (Contains(y, tree)) {
        printf("Test D success\n");
    }
    
    printf("=====Test D end=======\n");

    //Test E
    printf("=====Test E begin=====\n");
    int x = 5;
    Insert(x, tree);
    Insert(x, tree);
    Remove(x, tree);
    bool y = Contains(x, tree); //true
    Remoce(x, tree);
    bool z = Contains(x, tree); //false

    printf("=====Test E end=======\n");

    if(Empty(root)) {
        printf("It's empty!\n");
    }

    */

    free_tree(tree);
    return 0;
}