//
// Created by tianyao on 25-3-17.
//

#include <stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include "Elimination.h"

 void Set_Identity(double **matrix, int n) {
     for (int i=0;i<n;i++) {
         for (int j=0;j<n;j++) {
             matrix[i][j+n] = (i==j) ? 1 : 0;
         }
     }
 }


void Matrix_Reverse(double **matrix, int n) {
     Elimination(matrix,n,n);
     if (Multi_Diag(matrix,n)==0) {
         printf("Singular matrix.\n");
         return;
     }
     BackSubstitution(matrix,n,n);
     printf("Invertible matrix. The inverse of the matrix is: \n");
     for (int i=0;i<n;i++) {
         for (int j=0;j<n;j++) {
             printf("%lf ",matrix[i][j+n]);
         }
         printf("\n");
     }
}

int main() {
     int n;
     printf("Please enter the order of the matrix:\n");
     scanf("%d",&n);
     printf("Please enter the matrix:\n");
     double **matrix = (double **)malloc(sizeof(double*)*n);
     for(int i=0;i<n;i++) {
         matrix[i] = (double *)malloc(sizeof(double)*n*2);
     }
     for(int i=0;i<n;i++) {
         for (int j=0;j<n;j++) {
             scanf("%lf",&matrix[i][j]);
         }
     }
     Set_Identity(matrix,n);
     Matrix_Reverse(matrix,n);
     for(int i=0;i<n;i++) {
         free(matrix[i]);
     }
     free(matrix);
     printf("Enter anything to exit.\n");
     getchar();
     getchar();
     return 0;
 }