#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void row_reduce(double **map,int i,int j,int n){
    double multiple;
    if (map[i][i]==0) multiple = 0;
    //todo: for determinants that need row exchange
    else multiple  = map[j][i]/map[i][i];
    for(int k=i;k<n;k++) {
        map[j][k] -= map[i][k] * multiple;
    }
}

void Elimination(double **map, int n) {
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            row_reduce(map,i,j,n);
        }
    }
}

double Multi_Diag(double **map, int n) {
    double ans = 1;
    for (int i=0;i<n;i++) {
        ans *= map[i][i];
    }
    return ans;
}

double Determinant_Calculator(double **map, int n) {
    Elimination(map,n);
    return Multi_Diag(map,n);
}

int main() {
    int n;
    printf("Please enter the order of the matrix: ");
    scanf("%d",&n);
    printf("Please enter the matrix: ");
    double **map = (double **)malloc(sizeof(double*)*n);
    for(int i=0;i<n;i++) {
        map[i] = (double *)malloc(sizeof(double)*n);
    }
    for(int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            scanf("%lf",&map[i][j]);
        }
    }
    double determinant_val = Determinant_Calculator(map,n);
    printf("The determinant of the matrix is: %lf",determinant_val);
    for(int i=0;i<n;i++) {
       free(map[i]);
    }
    free(map);
    return 0;
}