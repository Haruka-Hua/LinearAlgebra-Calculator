//
// Created by tianyao on 25-3-18.
//

#ifndef MATRIX_H
#define MATRIX_H

#endif //MATRIX_H

#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct Node {
    char name[32];
    int r;
    int c;
    double **matrix;
    struct Node *next;
    struct Node *prev;
} node;

void CreateNode(int r, int c, double **matrix, const char *name, node **head, node **tail) { //create a node;
    node *new_matrix = (node *) malloc(sizeof(node));
    new_matrix->r = r;
    new_matrix->c = c;
    new_matrix->matrix = matrix;
    strcpy(new_matrix->name,name);
    new_matrix->next = NULL;
    new_matrix->prev = *tail;
    if (*head==NULL) {
        *head = new_matrix;
        *tail = new_matrix;
    }
    else {
        (*tail)->next = new_matrix;
    }
}
void DelMatrix(const node *target) { //delete a matrix in a node;
    double **matrix = target->matrix;
    int row = target->r;
    for (int i=0;i<row;i++) {
        free(matrix[i]);
    }
    free(matrix);
}
void RemoveNode(node *target, node **head, node **tail) { //remove a node;
    DelMatrix(target);
    if (target==*head && target==*tail) {
        *head = NULL;
        *tail = NULL;
        free(target);
    }
    else if (target==*head) {
        *head = target->next;
        target->next->prev = NULL;
        free(target);
    }
    else if (target==*tail) {
        *tail = target->prev;
        target->prev->next = NULL;
        free(target);
    }
    else {
        target->prev->next = target->next;
        target->next->prev = target->prev;
        free(target);
    }
}