// Question: Store n numbers in array, conduct linear search and report success or failure.
#include <stdio.h>
int main() {
    int n, key, a[100], found = 0;
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    scanf("%d", &key);

    for(int i=0; i<n; i++) {
        if(a[i] == key) {
            found = 1;
            break;
        }
    }
    if(found) printf("Success\n");
    else printf("Failure\n");
    return 0;
}