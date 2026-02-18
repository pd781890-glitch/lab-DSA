//Implement double linked list and it's operations
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next, *prev;
};
void display(struct Node* h) {
    while (h) {
        printf("%d %s ", h->data, h->next ? "<->" : "-> NULL\n");
        h = h->next;
    }
}

void insBeg(struct Node** h, int v) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = v; n->prev = NULL; n->next = *h;
    if (*h) (*h)->prev = n;
    *h = n;
}

void insEnd(struct Node** h, int v) {
    struct Node *n = malloc(sizeof(struct Node)), *t = *h;
    n->data = v; n->next = NULL;
    if (!*h) { n->prev = NULL; *h = n; return; }
    while (t->next) t = t->next;
    t->next = n; n->prev = t;
}

void del(struct Node** h, int k) {
    struct Node* t = *h;
    while (t && t->data != k) t = t->next;
    if (!t) return;
    if (t->prev) t->prev->next = t->next;
    else *h = t->next;
    if (t->next) t->next->prev = t->prev;
    free(t);
}

int main() {
    struct Node* head = NULL;
    insEnd(&head, 10); insEnd(&head, 20); insBeg(&head, 5);
    display(head);
    del(&head, 10);
    display(head); 
    return 0;
}