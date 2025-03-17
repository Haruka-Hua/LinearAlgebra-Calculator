//
// Created by tianyao on 25-3-17.
//

#ifndef ELIMINATION_H
#define ELIMINATION_H

#endif //ELIMINATION_H

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
    for(int k=i;k<n*2;k++) {
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

// void BackSubstitution() {
//
// }