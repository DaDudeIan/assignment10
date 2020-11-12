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
    if(x <= t->value) {
        if(t->lchild == NULL) {
            t->lchild = make_node(x, NULL, NULL);
        } else if (t->lchild != NULL) {
            Insert(x, t->lchild);
        }
    }
    else if (x > t->value) {
        if(t->rchild == NULL) {
            t->rchild = make_node(x, NULL, NULL);
        } else if (t->rchild != NULL) {
            Insert(x, t->rchild);
        }
    }
    
}

tree_node* FindMin(tree_node* t) {
    while(t->lchild != NULL) {
        t = t->lchild;
        return t;
    }
}

tree_node* Remove(int value, tree_node* t) {  
    // If tree is empty return root
    if (t == NULL) {
        return;
    } 
    // If the value is less then the data in the root - the value is in the left subtree.
    else if (value < t->value) {
        t->lchild = Remove(value, t->lchild);
    }
    else if (value > t->value) {
        t->rchild = Remove(value, t->rchild);
    }
    // If the value is not less or greater then it must be equal to - meaning it found the value
    else {
        // if No Children
        if (t->lchild == NULL && t->rchild == NULL) {
            free(t);
            t = NULL;
        }
        // if One Child
        else if (t->lchild == NULL) {
            tree_node* tmp = t;
            t = t->rchild;
            free(tmp);
        }
        else if (t->rchild == NULL) {
            tree_node* tmp = t;
            t = t->lchild;
            free(tmp);
        }
        // if Two Children
        else {
            tree_node* tmp = FindMin(t->rchild);
            t->value = tmp->value;
            t->rchild = Remove(tmp->value, t->rchild);
        }
    }
    return t;
}

bool Contains(int x, tree_node* t) {
    if (t == NULL) {
        return; 
    }

    if (t->value == x) {
        printf("Value found! '%d'\n", x);
        return true;
    } else if (t->lchild != NULL) {
        Contains(x, t->lchild);
    } else if (t->rchild != NULL) {
        Contains(x, t->rchild);
    } else {
        return false;
    }
}

void Initialize(tree_node* t) {
    tree_node *no = (tree_node*) malloc(sizeof(tree_node));
    make_node(0, NULL, NULL);
    printf("Initialized!\n");
}

bool Full(tree_node* t) {
    return false;
}

bool Empty(tree_node* t) {
    if (t->rchild == NULL && t->lchild == NULL) {
        printf("It's empty alright!\n");
        return true;
    } else {
        printf("It ain't empty!\n");
        return false;
    }
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

    Initialize(tree);
    
    int x = 0;


    //Test A
    printf("=====Test A begin=====\n");
    tree_node* Test_A = make_node(0, NULL, NULL);
    Initialize(Test_A);
    Empty(tree);

    printf("=====Test A end=======\n");

    
    //Test B
    printf("=====Test B begin=====\n");
    tree_node* Test_B = make_node(0, NULL, NULL);
    Initialize(Test_B);

    x = 2;
    Insert(x, Test_B);
    Contains(x, Test_B);
    Empty(Test_B);

    Remove(x, Test_B);
    Contains(x, Test_B);
    Empty(Test_B);

    printf("=====Test B end=======\n");
    

    //Test C
    printf("=====Test C begin=====\n");
    tree_node* Test_C = make_node(0, NULL, NULL);
    Initialize(Test_C);
    
    x = 3;
    Insert(x, Test_C);
    
    bool y = Contains(x, Test_C);
    if (y) {
        printf("Test C success\n");
    }

    printf("=====Test C end=======\n");

    

    //Test D
    printf("=====Test D begin=====\n");
    tree_node* Test_D = make_node(0, NULL, NULL);
    Initialize(Test_D);

    x = 4;
    int Dy = 5;
    Insert(x, Test_D);
    Insert(Dy, Test_D);
    Remove(x, Test_D);

    bool z = Contains(Dy, Test_D);

    if (z) {
        printf("Test D success\n");
    }
    
    printf("=====Test D end=======\n");

    
    //Test E
    printf("=====Test E begin=====\n");
    tree_node* Test_E = make_node(0, NULL, NULL);
    Initialize(Test_E);

    int Ex = 5;
    Insert(Ex, Test_E);
    Insert(Ex, Test_E);
    Remove(Ex, Test_E);
    bool Ey = Contains(Ex, Test_E); //true
    if (Ey) {
        printf("Found first time!\n");
    }
    Remove(Ex, Test_E);
    bool Ez = Contains(Ex, Test_E); //false
    if (Ez) {
        printf("Found second time!\n");
    }

    printf("=====Test E end=======\n");

    free_tree(tree);
    free_tree(Test_A);
    free_tree(Test_B);
    free_tree(Test_C);
    free_tree(Test_D);
    free_tree(Test_E);
    return 0;
}