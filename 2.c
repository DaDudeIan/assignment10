#include <stdio.h>
#include <stdlib.h>

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

void free_list(node* p) {
    if (p->next != NULL) {
        free_list(p->next);
    }
    free(p);
    //printf("freed! ");
}

int sum_squares(node* p) {
    if (p->next != NULL) {
        return sq(p->value) + sum_squares(p->next);
    } else {
        return sq(p->value);
    }
}

int sq(int n) {
    return n * n;
}

int main(void) {
    int sum;
    node* head = make_list();

    sum = sum_squares(head);

    printf("The sum is %d!\n", sum);

    free_list(head);
}