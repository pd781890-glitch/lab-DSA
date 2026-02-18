// Question: Convert uppercase string to lower case using loops.
#include <stdio.h>
int main() {
    char s[100];
    scanf("%s", s);
    for(int i=0; s[i] != '\0'; i++) {
        if(s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] + 32;
        }
    }
    printf("Lowercase: %s\n", s);
    return 0;
}