#include <stdio.h>
#include <stdlib.h>
#include "student_database.h"

Node* traversePtr(int ID, Node* head) {

	Node* current;
	printf("Hunting for %d\n", ID);	

	/* traverses structure to find exact ID number */
	current = head;
		while(current != NULL) {
			if(current->Student.student_ID == ID) {
				return current;
			}
			current = current->next;
		}
	
	return NULL;
}
