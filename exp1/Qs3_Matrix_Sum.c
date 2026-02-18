// Question: Find sum of rows and columns of a matrix of given order.
#include <stdio.h>
int main() {
    int r, c, mat[10][10];
    scanf("%d %d", &r, &c);
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++) scanf("%d", &mat[i][j]);
    for(int i=0; i<r; i++) {
        int rs = 0;
        for(int j=0; j<c; j++) rs += mat[i][j];
        printf("Row %d: %d\n", i+1, rs);
    }
    for(int j=0; j<c; j++) {
        int cs = 0;
        for(int i=0; i<r; i++) cs += mat[i][j];
        printf("Col %d: %d\n", j+1, cs);
    }
    return 0;
}