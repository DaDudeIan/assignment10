#include <stdio.h>
#include <stdlib.h>

typedef int (*sf) (int n);

typedef struct node node;

struct node {
    int value;
    node* next;
};


node* make_node(int x, node* n_node) {
    node* no = (node*) malloc(sizeof(node));
    no->value = x;
    no->next = n_node;
    return no;
}

node* make_list() {
    node* list = make_node(1, 
                    make_node(2, 
                        make_node(3,
                            make_node(4,
                                make_node(5, NULL)
                            )
                        )
                    )
                );
    
    return list;
}

int square(int x) {
    return x * x;
}

void print_list(node* p) {
    printf("%d ", p->value); //print node as you get to it

    if (p->next != NULL) {
        print_list(p->next);
    }
}

void elements_squared(node* X, sf sf) {
    if (X == NULL) {
        return;
    }
    elements_squared(X->next, sf);
    X->value = sf(X->value);
}

int main(void) {
    node* X = make_list();

    print_list(X);
    printf("\n");

    elements_squared(X, square);

    print_list(X);

    return 0;
}