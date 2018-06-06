/*
 JTSK-320111
 a5_p9_m1.c
 Steven Abreu
 s.abreu@jacobs-university.de
 */

#include <stdio.h>

void print_matrix(int matrix[50][50], int dim);
void print_matrix_diagonal(int matrix[50][50], int dim);
int main() {
    int matrix[50][50], dim, i, j;

    printf("Enter dimension of square matrix: ");
    scanf("%d", &dim);

    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            printf("Enter number for %dx%d: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("The entered matrix is:\n");
    print_matrix(matrix, dim);
    printf("The secondary diagonal is:\n");
    print_matrix_diagonal(matrix, dim);

    return 0;
}

void print_matrix(int matrix[50][50], int dim) {
    int i, j;
    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            printf("%5d", matrix[i][j]);
        }
        printf("\n");
    }
}

void print_matrix_diagonal(int matrix[50][50], int dim) {
    int i, j;
    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            if (i+j+2 == dim+1) {
                printf("%5d", matrix[i][j]);
            }
        }
    }
    printf("\n");
}
