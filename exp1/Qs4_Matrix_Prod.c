// Question: Find the product of two matrix using pointers.
#include <stdio.h>
int main() {
    int r1, c1, r2, c2, a[5][5], b[5][5], res[5][5];
    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
    for(int i=0; i<r1; i++) for(int j=0; j<c1; j++) scanf("%d", (*(a+i)+j));
    for(int i=0; i<r2; i++) for(int j=0; j<c2; j++) scanf("%d", (*(b+i)+j));
    for(int i=0; i<r1; i++) {
        for(int j=0; j<c2; j++) {
            *(*(res+i)+j) = 0; 
            for(int k=0; k<c1; k++)
                *(*(res+i)+j) += (*(*(a+i)+k)) * (*(*(b+k)+j));
            printf("%d ", *(*(res+i)+j));
        }
        printf("\n");
    }
    return 0;
}