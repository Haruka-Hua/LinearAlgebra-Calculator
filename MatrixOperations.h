//
// Created by tianyao on 25-3-24.
//

#ifndef MATRIXOPERATIONS_H
#define MATRIXOPERATIONS_H

#endif //MATRIXOPERATIONS_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "matrix.h"

node *GetMatrix(const char *matrix_name, node *head, node *tail) {
    node *current = head;
    while (current) {
        if (strcmp(matrix_name,current->name)==0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void Query(node *head, node *tail) { //query a matrix
    char matrix_name[32];
    printf("Please enter the name of the matrix you want to query:\n");
    scanf("%s",matrix_name);
    const node *target = GetMatrix(matrix_name,head,tail);
    if (target==NULL) {
        printf("\"%s\" does not exist. Please define it first.\n",matrix_name);
        return;
    }
    else {
        const int r = target->r;
        const int c = target->c;
        printf("name: %s\n",matrix_name);
        printf("%d by %d\n",r,c);
        for (int i=0;i<r;i++) {
            for (int j=0;j<c;j++) {
                printf("%lf ",target->matrix[i][j]);
            }
            printf("\n");
        }
        return;
    }
}

void Rename(node *head, node *tail) { //rename a matrix;
    char prev_name[32];
    printf("Please enter the name of the matrix you want to rename:\n");
    scanf("%s",prev_name);
    node *target = GetMatrix(prev_name,head,tail);
    if (target==NULL) {
        printf("\"%s\" does not exist. Please define it first.\n",prev_name);
        return;
    }
    else {
        char new_name[32];
        printf("Please enter the new name:\n");
        scanf("%s",new_name);
        node *check = GetMatrix(new_name,head,tail);
        if (check) {
            printf("\"%s\" already exist. Try again with another name.\n",new_name);
            return;
        }
        else {
            strcpy(target->name,new_name);
            printf("Rename success!\n");
            return;
        }
    }
}

void Delete(node **head, node **tail) { //delete a certain matrix;
    char matrix_name[32];
    printf("Please enter the name of the matrix you want to delete:\n");
    scanf("%s",matrix_name);
    node *target = GetMatrix(matrix_name,*head,*tail);
    if (target==NULL) {
        printf("\"%s\" does not exist.\n",matrix_name);
        return;
    }
    else {
        RemoveNode(target,head,tail);
        printf("Delete success!\n");
    }
}

void Create(node **head, node **tail) {
    char matrix_name[32];
    printf("Name of the new matrix: ");
    scanf("%s",matrix_name);
    node *check = GetMatrix(matrix_name,*head,*tail);
    if (check) {
        printf("\"%s\" already exist. Try again with another name.\n",matrix_name);
        return;
    }
    int row,col;
    printf("Number of rows: ");
    scanf("%d",&row);
    printf("Number of columns: ");
    scanf("%d",&col);
    printf("Please enter the matrix:\n");
    double **matrix = (double **) malloc(sizeof(double *) * row);
    for (int i=0;i<row;i++) {
        matrix[i] = (double*)malloc(sizeof(double) * col);
    }
    for (int i=0;i<row;i++) {
        for (int j=0;j<col;j++) {
            scanf("%lf",&matrix[i][j]);
        }
    }
    CreateNode(row,col,matrix,matrix_name,head,tail);
    printf("\"%s\" created!\n",matrix_name);
}

void MultiPlus(node **head, node **tail, int multiplier1, int multiplier2) {
    char matrixA_name[32],matrixB_name[32];
    printf("first matrix:");
    scanf("%s",matrixA_name);
    printf("second matrix:");
    scanf("%s",matrixB_name);
    node *matrixA = GetMatrix(matrixA_name,*head,*tail);
    node *matrixB = GetMatrix(matrixB_name,*head,*tail);
    if (matrixA==NULL) {
        printf("\"%s\" does not exist.\n",matrixA_name);
    }
    if (matrixB==NULL) {
        printf("\"%s\" does not exist.\n",matrixB_name);
    }
    if (matrixA==NULL || matrixB==NULL) {
        return;
    }
    if (matrixA->r != matrixB->r || matrixA->c != matrixB->c) {
        printf("Invalid matrix type!\n");
        return;
    }
    int row = matrixA->r;
    int col = matrixA->c;
    char matrixC_name[32];
    while (1) {
        printf("Please name the answer matrix:\n");
        scanf("%s",matrixC_name);
        node *check = GetMatrix(matrixC_name,*head,*tail);
        if (check) {
            printf("\"%s\" already exist. Choose another name.\n",matrixC_name);
            continue;
        }
        break;
    }
    double **matrixC = (double **) malloc(sizeof(double*)*row);
    for (int i=0;i<row;i++) {
        matrixC[i] = (double *)malloc(sizeof(double)*col);
    }
    for (int i=0;i<row;i++) {
        for (int j=0;j<col;j++) {
            matrixC[i][j] = multiplier1 * matrixA->matrix[i][j] + multiplier2 * matrixB->matrix[i][j];
        }
    }
    CreateNode(row,col,matrixC,matrixC_name,head,tail);
    printf("The answer is:\n");
    printf("%d by %d\n",row,col);
    for (int i=0;i<row;i++) {
        for (int j=0;j<col;j++) {
            printf("%lf ",matrixC[i][j]);
        }
        printf("\n");
    }
}

void Mult(node **head, node **tail) {
    char matrixA_name[32],matrixB_name[32];
    printf("first matrix:");
    scanf("%s",matrixA_name);
    printf("second matrix:");
    scanf("%s",matrixB_name);
    node *matrixA = GetMatrix(matrixA_name,*head,*tail);
    node *matrixB = GetMatrix(matrixB_name,*head,*tail);
    if (matrixA==NULL) {
        printf("\"%s\" does not exist.\n",matrixA_name);
    }
    if (matrixB==NULL) {
        printf("\"%s\" does not exist.\n",matrixB_name);
    }
    if (matrixA==NULL || matrixB==NULL) {
        return;
    }
    if (matrixA->c != matrixB->r) {
        printf("Invalid matrix type!\n");
        return;
    }
    int row = matrixA->r;
    int col = matrixB->c;
    char matrixC_name[32];
    while (1) {
        printf("Please name the answer matrix:\n");
        scanf("%s",matrixC_name);
        node *check = GetMatrix(matrixC_name,*head,*tail);
        if (check) {
            printf("\"%s\" already exist. Choose another name.\n",matrixC_name);
            continue;
        }
        break;
    }
    double **matrixC = (double **) malloc(sizeof(double*)*row);
    for (int i=0;i<row;i++) {
        matrixC[i] = (double *)malloc(sizeof(double)*col);
    }
    for (int i=0;i<row;i++) {
        for (int j=0;j<col;j++) {
            matrixC[i][j]=0;
            for (int k=0;k<matrixA->c;k++) {
                matrixC[i][j] += matrixA->matrix[i][k] * matrixB->matrix[k][j];
            }
        }
    }
    CreateNode(row,col,matrixC,matrixC_name,head,tail);
    printf("The answer is:\n");
    printf("%d by %d\n",row,col);
    for (int i=0;i<row;i++) {
        for (int j=0;j<col;j++) {
            printf("%lf ",matrixC[i][j]);
        }
        printf("\n");
    }
}

void Welcome() {
    printf("----------Instructions----------\n");
    printf("Welcome to my matrix Calculator!\n");
    printf("You can choose from these operations:\ncreate / delete / query / plus / minus "
           "/ mult / rename / memory / quit\n");
    printf("create: create a new matrix.\n");
    printf("delete: delete a certain matrix from memory.\n");
    printf("query: get information of a certain matrix from memory.\n");
    printf("plus: add two matrices together and add the answer matrix to memory.\n");
    printf("minus: subtract the second matrix from the first matrix.\n");
    printf("mult: multiply two matrices together and add the answer matrix to memory.\n");
    printf("rename: rename a certain matrix in memory.\n");
    printf("memory: show memory information.\n");
    printf("quit: quit the programme.\n");
    printf("----------Dividing line----------\n");
}

void MemQuery(node *head) {
    if (head==NULL) {
        printf("Memory empty!\n");
        return;
    }
    node *current = head;
    int cnt = 0;
    printf("| ");
    while (current) {
        printf("%s | ",current->name);
        current = current->next;
        cnt++;
    }
    printf("\n%d matrices in total.\n",cnt);
}