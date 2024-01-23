#include <stdio.h>
#include <stdlib.h>
#include "student_database.h"

void option5(Node *head) {

	Node *current = head;

	char stuName[40];
	int cQuiz;
	int cMid;
	int cHW;
	int cFinal;
	int cGrade;
	printf("\n");

	while(current != NULL) {

		calculateGrades(current);

		printf("Student Name: %s ", current->Student.student_name);
		printf("\tQuizzes Cumlative: %.2f ", current->Student.Cat1.Cumulative);
		printf("\tMidterms Cumulative: %.2f ", current->Student.Cat2.Cumulative);
		printf("\tHomework Cumulative: %.2f ", current->Student.Cat3.Cumulative);
		printf("\tFinal Cumulative: %.2f ", current->Student.Cat4.Cumulative);
		printf("\tCurrent Grade: %.2f\n", current->Student.Current_Grade);		


		current = current->next;
	}
	printf("\n");

}
