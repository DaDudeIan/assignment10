#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node {
    int value;
    node* next;
};


node* make_node(int x) {
    node* no = (node*) malloc(sizeof(node));
    no->value = x;
    no->next = NULL;
    return no;
}

node* make_list() {
    node* n1 = make_node(3);
    node* n2 = make_node(5);
    node* n3 = make_node(8);
    node* n4 = make_node(1);
    node* n5 = make_node(9);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    
    return n1;
}

void free_list(node* p) {
    if (p->next != NULL) {
        free_list(p->next);
    }
    free(p);
    //printf("freed! ");
}

void print_list(node* p) {
    printf("%d ", p->value); //print node as you get to it

    if (p->next != NULL) {
        print_list(p->next);
    }
}

int main(void) {
    node* head = make_list();

    print_list(head);

    free_list(head);

    printf("\n");
    return 0;
}