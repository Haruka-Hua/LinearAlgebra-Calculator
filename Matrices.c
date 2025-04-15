#include<stdio.h>
#include "MatrixOperations.h"

node *head = NULL;
node *tail = NULL;
char matrix_operator[16] = "";

int main() {
    Welcome();
    while (1) {
        printf("What to do next?\n");
        scanf("%s",matrix_operator);
        if (strcmp(matrix_operator,"quit")==0) {
            break;
        }
        else if (strcmp(matrix_operator,"create")==0) {
            Create(&head,&tail);
        }
        else if (strcmp(matrix_operator,"delete")==0) {
            Delete(&head,&tail);
        }
        else if (strcmp(matrix_operator,"query")==0) {
            Query(head,tail);
        }
        else if (strcmp(matrix_operator,"plus")==0) {
            SuperPlus(&head,&tail,1,1);
        }
        else if (strcmp(matrix_operator,"minus")==0) {
            SuperPlus(&head,&tail,1,-1);
        }
        else if (strcmp(matrix_operator,"multplus")==0) {
            MultPlus(&head,&tail);
        }
        else if (strcmp(matrix_operator,"nummult")==0) {
            NumMult(&head,&tail);
        }
        else if (strcmp(matrix_operator,"mult")==0) {
            Mult(&head,&tail);
        }
        else if (strcmp(matrix_operator,"rename")==0) {
            Rename(head,tail);
        }
        else if (strcmp(matrix_operator,"memory")==0) {
            MemQuery(head);
        }
        else {
            printf("Invalid operator! Try again!\n");
            continue;
        }
    }
    DelList(head);
    return 0;
}