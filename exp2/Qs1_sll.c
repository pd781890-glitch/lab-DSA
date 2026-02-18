//Implement a single linked list data structure and its operations like delete, insert at the beginnings, end and inth position, and display the items stored in the list
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
void display(struct Node* h) {
    while(h) { printf("%d -> ", h->data); h = h->next; }
    printf("NULL\n");
}
void insBeg(struct Node** h, int v) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = v; n->next = *h; *h = n;
}
void insEnd(struct Node** h, int v) {
    struct Node* n = malloc(sizeof(struct Node)), *t = *h;
    n->data = v; n->next = NULL;
    if(!*h) { *h = n; return; }
    while(t->next) t = t->next;
    t->next = n;
}
void insNth(struct Node** h, int v, int p) {
    if(p == 1) { insBeg(h, v); return; }
    struct Node* n = malloc(sizeof(struct Node)), *t = *h;
    n->data = v;
    for(int i=1; t && i<p-1; i++) t = t->next;
    if(!t) return;
    n->next = t->next; t->next = n;
}
void del(struct Node** h, int k) {
    struct Node *t = *h, *p = NULL;
    if(t && t->data == k) { *h = t->next; free(t); return; }
    while(t && t->data != k) { p = t; t = t->next; }
    if(!t) return;
    p->next = t->next; free(t);
}
int main() {
    struct Node* head = NULL;
    insEnd(&head, 10); insBeg(&head, 5); insNth(&head, 7, 2);
    display(head);
    del(&head, 7);
    display(head);
    return 0;
}