#include <stdio.h>
#include <string.h>
#include "student_database.h"

void option3(Node* head) {

/* initial cumulative scores for averages */
	double cQuiz = 0;
	double cMid = 0;
	double cHW = 0;
	double cFinal = 0;
	double cGrade = 0;

	int nameWidth;
	int idWidth;

	int currentIdWidth;
	int currentNameWidth;

	double aQuiz;
	double aMid;
	double aHW;
	double aFinal;
	double aGrade;

	Node *current = head;
	int nodeCount = 0;
	printf("\nStudent Name\t\tID#\t\tQuizzes\t\t\t\tMidterms\t\t\tHomework\t\t\tFinal\t\t\tCurrent\tFinal\n");
        printf("\t\t\t\t1\t2\t3\tCum\t1\t2\t3\tCum\t1\t2\t3\tCum\t1\t2\t3\tCum\tGrade\tGrade\n");

	/* Initialize variables to store maximum column widths */
	nameWidth = 0;
	idWidth = 0;

	while (current != NULL) {

		calculateGrades(current);

    		/* Update column width based on data */
	  	currentNameWidth = strlen(current->Student.student_name);
    		if (currentNameWidth > nameWidth) {
        		nameWidth = currentNameWidth;
    		}

    		/* Update column width based on data */
    		currentIdWidth = snprintf(NULL, 0, "%d", current->Student.student_ID);
    		if (currentIdWidth > idWidth) {
        		idWidth = currentIdWidth;
    		}

	    	printf("%-*s\t%-*d\t", nameWidth, current->Student.student_name, idWidth, current->Student.student_ID);
    		printf("%.2f\t%.2f\t%.2f\t%.2f\t", current->Student.Cat1.score1, current->Student.Cat1.score2, current->Student.Cat1.score3, current->Student.Cat1.Cumulative);
    		printf("%.2f\t%.2f\t%.2f\t%.2f\t", current->Student.Cat2.score1, current->Student.Cat2.score2, current->Student.Cat2.score3, current->Student.Cat2.Cumulative);
    		printf("%.2f\t%.2f\t%.2f\t%.2f\t", current->Student.Cat3.score1, current->Student.Cat3.score2, current->Student.Cat3.score3, current->Student.Cat3.Cumulative);
    		printf("%.2f\t%.2f\t%.2f\t%.2f\t", current->Student.Cat4.score1, current->Student.Cat4.score2, current->Student.Cat4.score3, current->Student.Cat4.Cumulative);
		printf("%.2f\t%.2f\n", current->Student.Current_Grade, current->Student.Final_Grade);
		
		cQuiz += current->Student.Cat1.Cumulative;
		cMid +=	current->Student.Cat2.Cumulative;
		cHW += current->Student.Cat3.Cumulative;
		cFinal += current->Student.Current_Grade;
		cGrade += current->Student.Final_Grade;		

		current = current->next;
		nodeCount++;		
	}
		/*average calculation*/
		aQuiz = cQuiz / nodeCount;
		aMid = cMid / nodeCount;
		aHW  = cHW / nodeCount;
		aFinal = cFinal / nodeCount;
		aGrade = cGrade / nodeCount;

		printf("\nClass Averages for Quizzes: %.2f, Midterms: %.2f, Homework: %.2f, Final: %.2f, Final Grade: %.2f\n", aQuiz, aMid, aHW, aFinal, aGrade);
	
	return;
	
		
}

