#include <stdio.h>
#include <stdlib.h>
#include "student_database.h"

void option9(Node **head){

	int idNum;
	Node * current;
	Node *prev;
	int deleteCh;

	if(*head == NULL) {
		printf("List is empty. Nothing to delete.\n");
		return;
	}
	
	
	printf("Please enter the student ID number you wish to delete, followed by enter.\n");
	scanf("%d", &idNum);

	current = *head;
    	prev = NULL;
	
    	/* If the node to delete is the head node */
    	if (current != NULL && current->Student.student_ID == idNum) {
        	*head = current->next; /* Update the head */
        	printf("\nDo you really want to delete student ID number %d, %s?\n", current->Student.student_ID, current->Student.student_name);
		printf("If yes, enter 1. If no, enter 2: ");
		
		scanf("%d", &deleteCh);
		if(deleteCh == 1){
			printf("\nStudent ID Number: %d, %s was deleted.", current->Student.student_ID, current->Student.student_name); 
			current->next = NULL;
		}else{
			printf("Student was not deleted.\n");
		}

        	return;
	}

	current = traversePtr(idNum, *head);
	if(current == NULL) {
		printf("Error: could not find student\n");
		return;
	}else{
		
	        printf("Student ID Number: %d, %s\n", current->Student.student_ID, current->Student.student_name);

        	/* Ask for confirmation */
        	
        	printf("Do you really want to delete this student?\n");
        	printf("If yes, enter 1. If no, enter 2: ");
        	scanf("%d", &deleteCh);

 		if (deleteCh == 1) {
            	/* Delete the student node by detaching it */
            		if (prev == NULL) {
                		/* The student to delete is the head node */
                		*head = current->next;
            		} else {
               			/* The student to delete is not the head node */
                		prev->next = current->next;
            		}
            	current->next = NULL; /* Detach the node */
            	printf("\nStudent with ID %d, %s was detached.\n", idNum, current->Student.student_name);
	 	free(current);	 
		} else {
        		printf(" \nStudent was not deleted.\n");		
		}
	}	
	printf("\n");
	
}
