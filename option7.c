#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student_database.h"

void option7(Node *head) {

        double cQuiz = 0;
        double cMid = 0;
        double cHW = 0;
        double cFinal = 0;
        double cGrade = 0;

        /* Initialize variables to store maximum column widths */
        int nameWidth = 0;
        int idWidth = 0;
	Node *current;
        
	int currentIdWidth;
        int currentNameWidth;
	int nodeCount = 0;

	double aQuiz;
	double aMid;
	double aHW;
	double aFinal;
	double aGrade;
        
	current = head;
	printf("\nStudent Name\tID#\t\tQuizzes\t\t\t\tMidterms\t\t\tHomework\t\t\tFinal\t\t\t\tCurrent\tFinal\n");
        printf("\t\t\t1\t2\t3\tCum\t1\t2\t3\tCum\t1\t2\t3\tCum\t1\t2\t3\tCum\tGrade\tGrade\n");

        while(current != NULL) {

                current->Student.Final_Grade = current->Student.Current_Grade;

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
                cMid += current->Student.Cat2.Cumulative;
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

                printf("Class Averages for Quizzes: %.2f, Midterms: %.2f, Homework: %.2f, Final: %.2f, Final Grade: %.2f\n", aQuiz, aMid, aHW, aFinal, aGrade);

        return;

	

}
