//Implement a circular linked list and its operations
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void display(struct Node* last) {
    if (!last) { printf("Empty\n"); return; }
    struct Node* t = last->next;
    do {
        printf("%d -> ", t->data);
        t = t->next;
    } while (t != last->next);
    printf("(Head)\n");
}

void insBeg(struct Node** last, int v) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = v;
    if (!*last) {
        n->next = n;
        *last = n;
    } else {
        n->next = (*last)->next;
        (*last)->next = n;
    }
}

void insEnd(struct Node** last, int v) {
    insBeg(last, v);
    *last = (*last)->next;
}

void del(struct Node** last, int k) {
    if (!*last) return;
    struct Node *curr = (*last)->next, *prev = *last;
    do {
        if (curr->data == k) {
            if (curr == *last && curr->next == *last) *last = NULL;
            else {
                prev->next = curr->next;
                if (curr == *last) *last = prev;
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != (*last)->next);
}

int main() {
    struct Node* last = NULL;
    insEnd(&last, 10); insEnd(&last, 20); insBeg(&last, 5);
    display(last); // 5 -> 10 -> 20 -> (Head)
    del(&last, 10);
    display(last); // 5 -> 20 -> (Head)
    return 0;
}