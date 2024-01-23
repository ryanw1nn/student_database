#include <stdio.h>
#include <stdlib.h>
#include "student_database.h"

void option4(Node *head) {
	
	int ID;	
	Node *current;
	printf("What is the Student ID for the scores you want to recalculate? ");
	printf(" Student ID: ");
	scanf("%d", &ID);
	current = traversePtr(ID, head);

	if(current == NULL) {	
	printf("Error: could not find ID\n");
	}else{

		printf("Recalculating grades for  %s, Student ID Number: %d\n", current->Student.student_name, current->Student.student_ID);

		calculateGrades(current);
   
		printf("Quizzes Culmulative: %.2f\n", current->Student.Cat1.Cumulative);
		printf("Midterms Culmulative: %.2f\n", current->Student.Cat2.Cumulative);
		printf("Homework Culmulative: %.2f\n", current->Student.Cat3.Cumulative);
		printf("Final Culmulative: %.2f\n", current->Student.Cat4.Cumulative);
		printf("Current Grade is: %.2f\n", current->Student.Current_Grade);
		current->Student.Final_Grade = 0;	
		printf("Student's Final Grade was deleted\n");

	}

	return;
}
