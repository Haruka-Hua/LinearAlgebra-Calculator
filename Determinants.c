#include <stdio.h>
#include <stdlib.h>
#include "Elimination.h"

double Determinant_Calculator(double **matrix, int n) {
    int sgn = Elimination(matrix,n,0);
    return sgn * Multi_Diag(matrix,n);
}

int main() {
    int n;
    printf("Please enter the order of the matrix:\n");
    scanf("%d",&n);
    printf("Please enter the matrix:\n");
    double **matrix = (double **)malloc(sizeof(double*)*n);
    for(int i=0;i<n;i++) {
        matrix[i] = (double *)malloc(sizeof(double)*n);
    }
    for(int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            scanf("%lf",&matrix[i][j]);
        }
    }
    double determinant_val = Determinant_Calculator(matrix,n);
    printf("The determinant of the matrix is: %lf \n",determinant_val);
    for(int i=0;i<n;i++) {
       free(matrix[i]);
    }
    free(matrix);
    printf("Enter anything to exit.\n");
    getchar();
    getchar();
    return 0;
}
