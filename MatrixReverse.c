//
// Created by tianyao on 25-3-17.
//

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

 void Reverse_Matrix(double **matrix, int n, double det) {
     if (det==0) {
         printf("It is a singular matrix.\n");
         return;
     }
     else {
         printf("It is a invertible matrix.\n");
         for (int i=0;i<n;i++) {
             for (int j=0;j<n;j++) {
                 printf("%lf ",matrix[i][j+n]);
             }
             printf("\n");
         }
     }
 }
