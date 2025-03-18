//
// Created by tianyao on 25-3-18.
//
#include <stdio.h>
#include <stdlib.h>
#include "Elimination.h"



void Equation_Solver(double **matrix, int n) {
    Elimination(matrix,n,1);
    if (Multi_Diag(matrix,n)==0) {
        printf("No solution or infinite solutions.\n");
        return;
    }
    BackSubstitution(matrix,n,1);
    printf("The solution of the equation is: \n");
    for (int i=0;i<n;i++) {
        printf("x%d = %lf\n",i+1,matrix[i][n]);
    }
}

int main() {
    int n;
    printf("Please enter the number of unknowns:\n");
    scanf("%d",&n);
    double **matrix = (double **)malloc(sizeof(double*)*n);
    for(int i=0;i<n;i++) {
        matrix[i] = (double *)malloc(sizeof(double)*(n+1));
    }
    printf("The standard form of a equation is Ax = b. \n");
    printf("Please enter matrix A: \n");
    for(int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            scanf("%lf",&matrix[i][j]);
        }
    }
    printf("Now please enter the right-hand side b:\n");
    for (int i=0;i<n;i++) {
        scanf("%lf",&matrix[i][n]);
    }
    Equation_Solver(matrix,n);
    for(int i=0;i<n;i++) {
        free(matrix[i]);
    }
    free(matrix);
    printf("Enter anything to exit.\n");
    getchar();
    getchar();
    return 0;
}