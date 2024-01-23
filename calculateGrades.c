#include <stdio.h>
#include <stdlib.h>
#include "student_database.h"

void calculateGrades(Node* node){

        float totalGrade = 0;
        int count = 0;
	int ch1;
	int ch2;
	int ch3;
	int ch4;

        /* Calculate cumulative grade for Cat1 */
        if (node->Student.Cat1.score1 >= 0) {
                totalGrade += node->Student.Cat1.score1;
                count++;
        }
	if (node->Student.Cat1.score2 >= 0) {
                totalGrade += node->Student.Cat1.score2;
                count++;               
        }
	if (node->Student.Cat1.score3 >= 0) {
                totalGrade += node->Student.Cat1.score3;
                count++;
        }

	if (count > 0) {
                node->Student.Cat1.Cumulative = totalGrade / count;
        } else {
                node->Student.Cat1.Cumulative = -1;
        }

	/* Reset total grades for Cat2 */
        totalGrade = count = 0;

        /* Calculate cumulative grade for Cat2 */
        if (node->Student.Cat2.score1 >= 0) {
                totalGrade += node->Student.Cat2.score1;
                count++;
        }
	if (node->Student.Cat2.score2 >= 0) {
                totalGrade += node->Student.Cat2.score2;
                count++;
        }
	if (node->Student.Cat2.score3 >= 0) {
                totalGrade += node->Student.Cat2.score3;
                count++;
        }
	if (count > 0) {
                node->Student.Cat2.Cumulative = totalGrade / count;
        } else {
                node->Student.Cat2.Cumulative = -1;
        }

	/* Repeat the same process for Cat3 */
        totalGrade = count = 0;

        /* Calculate cumulative grade for Cat3 */
        if (node->Student.Cat3.score1 >= 0) {
                totalGrade += node->Student.Cat3.score1;
                count++;
        }
	if (node->Student.Cat3.score2 >= 0) {
                totalGrade += node->Student.Cat3.score2;
	        count++;
        }
	if (node->Student.Cat3.score3 >= 0) {
                totalGrade += node->Student.Cat3.score3;
                count++;
        }

	if (count > 0) {
                node->Student.Cat3.Cumulative = totalGrade / count;
        } else {
                node->Student.Cat3.Cumulative = -1;
        }
                totalGrade = count = 0;

        /* Calculate cumulative grade for Cat4 */
        if (node->Student.Cat4.score1 >= 0) {
                totalGrade += node->Student.Cat4.score1;
                count++;
        }
                if (node->Student.Cat4.score2 >= 0) {
                        totalGrade += node->Student.Cat4.score2;
                        count++;
                }
                if (node->Student.Cat4.score3 >= 0) {
                        totalGrade += node->Student.Cat4.score3;
                        count++;
                }
                if (count > 0) {
                        node->Student.Cat4.Cumulative = totalGrade / count;
                } else {
                        node->Student.Cat4.Cumulative = -1;
                }

		ch1, ch2, ch3, ch4 = 0;

		if (node->Student.Cat1.Cumulative == -1) {
    			node->Student.Cat1.Cumulative = 100;
			ch1 = 1;
		}
		if (node->Student.Cat2.Cumulative == -1) {
    			node->Student.Cat2.Cumulative = 100;
			ch2 = 1;
		}
		if (node->Student.Cat3.Cumulative == -1) {
    			node->Student.Cat3.Cumulative = 100;
			ch3 = 1;
		}
		if (node->Student.Cat4.Cumulative == -1) {
    			node->Student.Cat4.Cumulative = 100;
			ch4 = 1;
		}

                node->Student.Current_Grade = (.15 * node->Student.Cat1.Cumulative) + (.3 * node->Student.Cat2.Cumulative) + (.2 * node->Student.Cat3.Cumulative) + (.35 * node->Student.Cat4.Cumulative);

		if (ch1 == 1){
			node->Student.Cat1.Cumulative = -1;
		}
                if (ch2	== 1){ 
                        node->Student.Cat2.Cumulative =	-1;
                }
                if (ch3	== 1){ 
                        node->Student.Cat3.Cumulative =	-1;
                }
                if (ch4	== 1){ 
                        node->Student.Cat4.Cumulative =	-1;
                }		
}
