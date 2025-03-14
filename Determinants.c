#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int Exchangeable_Row(double **map, int i, int n) {
    for (int j=i+1;j<n;j++) {
       if (map[j][i]!=0) return j;
    }
    return -1;
}

void Row_Exchange(double **map, int i, int j) {
    double *temp = map[i];
    map[i] = map[j];
    map[j] = temp;
}

double Get_Multiple(double **map, int i, int j, int n) {
    if (map[i][i]==0) {
        int exchangeable_row = Exchangeable_Row(map,i,n);
        if (exchangeable_row == -1) {
            return 0;
        }
        else {
            Row_Exchange(map,i,exchangeable_row);
        }
    }
    return map[j][i]/map[i][i];
}
void Row_Reduce(double **map,int i,int j,int n){
    double multiple = Get_Multiple(map,i,j,n);
    for(int k=i;k<n;k++) {
        map[j][k] -= map[i][k] * multiple;
    }
}

void Elimination(double **map, int n) {
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            Row_Reduce(map,i,j,n);
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
    printf("Please enter the order of the matrix:\n");
    scanf("%d",&n);
    printf("Please enter the matrix:\n");
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