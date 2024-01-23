#include <stdio.h>
#include <stdlib.h>
#include "student_database.h"

Node* merge(Node *left, Node *right){

	Node* result;
    if (left == NULL) return right;
    if (right == NULL) return left;

    result = NULL;

    if (left->Student.student_ID <= right->Student.student_ID) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}
