#include <stdio.h>
#include <string.h>
#define MAX 100
int top = -1;
char stack[MAX];
void push(char c) {
    stack[++top] = c;
}
char pop() {
    return stack[top--];
}
int main() {
    char str[MAX];
    printf("Enter string: ");
    gets(str); 
    int n = strlen(str);
    for (int i = 0; i < n; i++) 
        push(str[i]);
    printf("Reversed: ");
    for (int i = 0; i < n; i++) 
        printf("%c", pop());
    return 0;
}