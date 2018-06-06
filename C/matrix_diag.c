/*
 JTSK-320111
 a5_p8_m1.c
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
            printf("Enter number: ");
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("The entered matrix is:\n");
    print_matrix(matrix, dim);
    printf("The main diagonal is:\n");
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
            if (j == i) {
                printf("%5d", matrix[i][j]);
            }
        }
    }
    printf("\n");
}
