#include <stdio.h>
#include <stdlib.h>
#include "student_database.h"

void mergeSort(Node** head){
    Node* current = *head;
    Node* left;
    Node* right;
    Node* mid;
    if (current == NULL || current->next == NULL) {
        return; /* Base case: 0 or 1 element */
    }

    /* Split the list into two halves */
    left = current;
    right = current->next;

    while (right != NULL) {
        right = right->next;
        if (right != NULL) {
            left = left->next;
            right = right->next;
        }
    }

    /* Split the list into two halves and make sure left's next is NULL */    
    mid = left->next;
    left->next = NULL;

    /* Recursively sort both halves */
    mergeSort(&current);
    mergeSort(&mid);

    /* Merge the sorted halves */
    *head = merge(current, mid);
}
