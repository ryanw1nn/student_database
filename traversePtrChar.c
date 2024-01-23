#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student_database.h"

Node* traversePtrChar(const char* lName, Node* head) {

	Node *current;
	char nameCopy[40];
	char* token;        
printf("Hunting for %s", lName);

        current = head;
	while(current != NULL) {
		strncpy(nameCopy, current->Student.student_name, sizeof(nameCopy));
		
		token = strtok(nameCopy, ",");
		if(strcmp(token, lName) == 0) {
        	        return current;
                }
                current = current->next;
        }

        perror("Error: Student Name not found in the list.\n");
        exit(EXIT_FAILURE);
}



