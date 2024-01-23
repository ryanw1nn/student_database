#include <stdio.h>
#include <stdlib.h>
#include "student_database.h"


void option1(Node* head) {

	Node *current;
	int ID_Num;
        printf("Enter the Student ID #: ");
	

	scanf("%d", &ID_Num); 
	
	current = traversePtr(ID_Num, head);
	
	/* check if ID is NULL */
	if(current == NULL) {
		printf("Error: ID Not found");
	}else {
	
		printf("\nStudent Name\t\tID#\t\tQuizzes\t\t\t\tMidterm\t\t\tHomework\t\t\tFinal\t\t\t\tCurrent\tFinal\n");
        	printf("\t\t\t\t1\t2\t3\tCum\t1\t2\t3\tCum\t1\t2\t3\tCum\t1\t2\t3\tCum\tGrade\tGrade\n");
       		printf("%s\t%d\t", current->Student.student_name, current->Student.student_ID);
        	printf("%.2f\t%.2f\t%.2f\t%.2f\t", current->Student.Cat1.score1, current->Student.Cat1.score2, current->Student.Cat1.score3, current->Student.Cat1.Cumulative);
        	printf("%.2f\t%.2f\t%.2f\t%.2f\t", current->Student.Cat2.score1, current->Student.Cat2.score2, current->Student.Cat2.score3, current->Student.Cat2.Cumulative);
        	printf("%.2f\t%.2f\t%.2f\t%.2f\t", current->Student.Cat3.score1, current->Student.Cat3.score2, current->Student.Cat3.score3, current->Student.Cat3.Cumulative);
        	printf("%.2f\t%.2f\t%.2f\t%.2f\t", current->Student.Cat4.score1, current->Student.Cat4.score2, current->Student.Cat4.score3, current->Student.Cat4.Cumulative);
        	printf("%.2f\t%.2f\n", current->Student.Current_Grade, current->Student.Final_Grade);
	}
}

