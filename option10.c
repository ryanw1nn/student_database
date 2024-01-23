#include <stdio.h>
#include <stdlib.h>
#include "student_database.h"

void option10(Node *head, char* output_name){

	Node*current;
	int count;
	FILE *outputFile = fopen(output_name, "w");
	
	if (outputFile == NULL){
		printf("Can’t open file %s\n", output_name);
		exit(EXIT_FAILURE);
	}

	fprintf(outputFile, "Quizzes Midterms Homework Final\n");	

	current = head;
	count = 0;

	while(current != NULL) {
		
		fprintf(outputFile, "%s\n", current->Student.student_name);

		fprintf(outputFile, "%d\n", current->Student.student_ID);
		fprintf(outputFile, "%.2f\t%.2f\t%.2f\t\n", current->Student.Cat1.score1, current->Student.Cat1.score2, current->Student.Cat1.score3);
                fprintf(outputFile, "%.2f\t%.2f\t%.2f\t\n", current->Student.Cat2.score1, current->Student.Cat2.score2, current->Student.Cat2.score3);
                fprintf(outputFile, "%.2f\t%.2f\t%.2f\t\n", current->Student.Cat3.score1, current->Student.Cat3.score2, current->Student.Cat3.score3);
                fprintf(outputFile, "%.2f\t%.2f\t%.2f\t\n", current->Student.Cat4.score1, current->Student.Cat4.score2, current->Student.Cat4.score3);
		current = current->next;
		count++;
	}

	printf("A total of %d students were written into file %s\n", count, output_name); 

	if(fclose(outputFile) != 0) {
		printf("fclose failed\n");
		exit(EXIT_FAILURE);
	}
	
}
