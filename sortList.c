#include <stdio.h>
#include <stdlib.h>
#include "student_database.h"

void sortList(struct Node** head) {

	struct Node* sortedList;
	struct Node* current;
	struct Node* next;

	if(*head == NULL || (*head)->next == NULL) return;

	sortedList = NULL;
	current = *head;
	while(current != NULL) {
		next = current->next;
		if (*head == NULL || (*head)->Student.student_ID >= sortedList->Student.student_ID) {
        		current->next = *head;
        		*head = current;
    		} else {
			struct Node* temp = sortedList;
        		while (temp->next != NULL && temp->next->Student.student_ID < current->Student.student_ID) {
            			temp = temp->next;
        		}
        		current->next = temp->next;
        		temp->next = current;
    		}	
		current = next;
	}
	*head = sortedList;
}
