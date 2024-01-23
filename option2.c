#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student_database.h"

void option2(Node* head) {
	
	int c;
	char lastName[40];
	Node* current;
	printf("Enter the student's last name: ");
		
	
	while ((c = getchar()) != '\n' && c != EOF);
	fgets(lastName, sizeof(lastName), stdin);
	lastName[strcspn(lastName, "\n")] = '\0'; 
		
	current = traversePtrChar(lastName, head);

	/*print statements */
        printf("\nStudent Name\t\tID#\t\tQuizzes\t\t\t\tMidterms\t\t\tHomework\t\t\tFinal\t\t\tCurrent\tFinal\n");
        printf("\t\t\t\t1\t2\t3\tCum\t1\t2\t3\tCum\t1\t2\t3\tCum\t1\t2\t3\tCum\tGrade\tGrade\n");
        printf("%s\t%d\t", current->Student.student_name, current->Student.student_ID);
        printf("%.2f\t%.2f\t%.2f\t%.2f\t", current->Student.Cat1.score1, current->Student.Cat1.score2, current->Student.Cat1.score3, current->Student.Cat1.Cumulative);
        printf("%.2f\t%.2f\t%.2f\t%.2f\t", current->Student.Cat2.score1, current->Student.Cat2.score2, current->Student.Cat2.score3, current->Student.Cat2.Cumulative);
        printf("%.2f\t%.2f\t%.2f\t%.2f\t", current->Student.Cat3.score1, current->Student.Cat3.score2, current->Student.Cat3.score3, current->Student.Cat3.Cumulative);
        printf("%.2f\t%.2f\t%.2f\t%.2f\t", current->Student.Cat4.score1, current->Student.Cat4.score2, current->Student.Cat4.score3, current->Student.Cat4.Cumulative);
        printf("%.2f\t%.2f\n", current->Student.Current_Grade, current->Student.Final_Grade);

}
