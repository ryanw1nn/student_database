#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student_database.h"

void option8(Node **head) {

	char newName[40];
	size_t len;
	int newID;
	Node* idCheck;
	
	float sc11;
        float sc12;
        float sc13;
        float sc21;
        float sc22;
        float sc23;
        float sc31;
        float sc32;
        float sc33;
        float sc41;
        float sc42;
        float sc43;
	
	struct Node* current;
	struct Node* prev;

	/* Clear the input buffer */
	int c;
	while ((c = getchar()) != '\n' && c != EOF);

	printf("Enter the Student's Name (last, first): ");
	
	fgets(newName, sizeof(newName), stdin);

    	/* Remove the trailing newline character if present */
    	len = strlen(newName);
    	if (len > 0 && newName[len - 1] == '\n') {
        	newName[len - 1] = '\0';
    	}

	printf("\nEnter the student's ID number: ");
	
 	scanf("%d", &newID);

	idCheck = traversePtr(newID, *head);
	
	if(idCheck != NULL){
		printf("Error: duplicate ID\n");
		return;	
	}

		
	
	printf("\nEnter first Quizzes score (use -1 if there is no score): ");

	scanf("%f", &sc11);

        printf("\nEnter second Quizzes score (use -1 if there is no score): ");
	
        scanf("%f", &sc12);

        printf("\nEnter third Quizzes score (use -1 if there is no score): ");

        scanf("%f", &sc13);



        printf("\nEnter first Midterms score (use -1 if there is no score): ");
	
        scanf("%f", &sc21);

        printf("\nEnter second Midterms score (use -1 if there is no score): ");
	
        scanf("%f", &sc22);

        printf("\nEnter third Midterms score (use -1 if there is no score): ");
	
        scanf("%f", &sc23);



        printf("\nEnter first Homework score (use -1 if there is no score): ");
	
        scanf("%f", &sc31);
	
        printf("\nEnter second Homework score (use -1 if there is no score): ");
	
        scanf("%f", &sc32);

        printf("\nEnter third Homework score (use -1 if there is no score): ");

        scanf("%f", &sc33);	



        printf("\nEnter first Final score (use -1 if there is no score): ");
	 
        scanf("%f", &sc41);

        printf("\nEnter second Final score (use -1 if there is no score): ");
	
        scanf("%f", &sc42);

        printf("\nEnter third Final score (use -1 if there is no score): ");
	
        scanf("%f", &sc43);
	
	

current = (struct Node*)malloc(sizeof(struct Node));
if (current == NULL) {
    /* Handle memory allocation failure */
    printf("Memory allocation failed. Unable to add a new student.\n");
    return;
}
	
/* Initialize the new node */
current->Student.student_ID = newID;
current->Student.student_name = (char*)malloc(strlen(newName) + 1);  /* Allocate memory for the name */
if (current->Student.student_name == NULL) {
    /* Handle memory allocation failure */
    printf("Memory allocation failed for student name. Unable to add a new student.\n");
    free(current);  /* Free the allocated memory for the node */
    return;
}


strcpy(current->Student.student_name, newName);

        current->Student.student_ID = newID;

        current->Student.Cat1.score1 = sc11;
        current->Student.Cat1.score2 = sc12;
        current->Student.Cat1.score3 = sc13;

        current->Student.Cat2.score1 = sc21;
        current->Student.Cat2.score2 = sc22;
        current->Student.Cat2.score3 = sc23;

        current->Student.Cat3.score1 = sc31;
        current->Student.Cat3.score2 = sc32;
        current->Student.Cat3.score3 = sc33;

        current->Student.Cat4.score1 = sc41;
        current->Student.Cat4.score2 = sc42;
        current->Student.Cat4.score3 = sc43;
    	
    /* If the list is empty or the new node should be inserted at the beginning */
    if (*head == NULL || newID < (*head)->Student.student_ID) {
        current->next = *head;
        *head = current;
	return;
	}
    

    /* Find the appropriate position to insert the new node */
    prev = *head;
    while (prev->next != NULL && newID > prev->next->Student.student_ID) {
        prev = prev->next;
    }
    
    /* Insert the new node */
    current->next = prev->next;
    prev->next = current;


	calculateGrades(current);

	printf("\n%s, Student ID#: %d has been added with the following information:", newName, newID); 

        printf("\nStudent Name\t ID#\t\tQuizzes\t\t\t\tMidterms\t\t\tHomework\t\t\tFinal\t\t\t\tCurrent\tFinal\n");
        printf("\t\t\t1\t2\t3\tCum\t1\t2\t3\tCum\t1\t2\t3\tCum\t1\t2\t3\tCum\tGrade\tGrade\n");
        printf("%s\t\t%d\t", current->Student.student_name, current->Student.student_ID);
        printf("%.2f\t%.2f\t%.2f\t%.2f\t", current->Student.Cat1.score1, current->Student.Cat1.score2, current->Student.Cat1.score3, current->Student.Cat1.Cumulative);
        printf("%.2f\t%.2f\t%.2f\t%.2f\t", current->Student.Cat2.score1, current->Student.Cat2.score2, current->Student.Cat2.score3, current->Student.Cat2.Cumulative);
        printf("%.2f\t%.2f\t%.2f\t%.2f\t", current->Student.Cat3.score1, current->Student.Cat3.score2, current->Student.Cat3.score3, current->Student.Cat3.Cumulative);
        printf("%.2f\t%.2f\t%.2f\t%.2f\t", current->Student.Cat4.score1, current->Student.Cat4.score2, current->Student.Cat4.score3, current->Student.Cat4.Cumulative);
        printf("%.2f\t%.2f\n", current->Student.Current_Grade, current->Student.Final_Grade);
	

}
