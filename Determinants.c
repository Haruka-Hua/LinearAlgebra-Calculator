#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int Exchangeable_Row(double **matrix, int i, int n) {
    for (int j=i+1;j<n;j++) {
       if (matrix[j][i]!=0) return j;
    }
    return -1;
}

void Row_Exchange(double **matrix, int i, int j) {
    double *temp = matrix[i];
    matrix[i] = matrix[j];
    matrix[j] = temp;
}

double Get_Multiple(double **matrix, int i, int j, int n) {
    if (matrix[i][i]==0) {
        int exchangeable_row = Exchangeable_Row(matrix,i,n);
        if (exchangeable_row == -1) {
            return 0;
        }
        else {
            Row_Exchange(matrix,i,exchangeable_row);
        }
    }
    return matrix[j][i]/matrix[i][i];
}
void Row_Reduce(double **matrix,int i,int j,int n){
    double multiple = Get_Multiple(matrix,i,j,n);
    for(int k=i;k<n;k++) {
        matrix[j][k] -= matrix[i][k] * multiple;
    }
}

void Elimination(double **matrix, int n) {
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            Row_Reduce(matrix,i,j,n);
        }
    }
}

double Multi_Diag(double **matrix, int n) {
    double ans = 1;
    for (int i=0;i<n;i++) {
        ans *= matrix[i][i];
    }
    return ans;
}

double Determinant_Calculator(double **matrix, int n) {
    Elimination(matrix,n);
    return Multi_Diag(matrix,n);
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
    printf("The determinant of the matrix is: %lf",determinant_val);
    for(int i=0;i<n;i++) {
       free(matrix[i]);
    }
    free(matrix);
    return 0;
}