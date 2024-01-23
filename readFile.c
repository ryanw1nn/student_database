#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student_database.h"

Node* readFile(FILE* input_file){

	char buffer[2024];
	Node* head;
	Node* current;
	Node* prev;
	size_t name_length;

        if(input_file == NULL) {
                perror("Error opening file");
                return NULL;
        }
	
        head = NULL;
        current = NULL;
	prev = NULL;

        /* ignores first line */
        fgets(buffer, sizeof(buffer), input_file);

        /* Loop to read and process data until EOF */
        while(!feof(input_file)) {

	        struct Node* node = (struct Node*)malloc(sizeof(struct Node)); 
		/* Allocate memory for the node */

	    	node->Student.student_name = (char*)malloc(40 * sizeof(char));
	

                if(fgets(node->Student.student_name, 40, input_file) == NULL) {
			free(node->Student.student_name); /* Free the allocated memory for student_name */
        		free(node); /* Free the allocated memory for the node */
                        break;
                        /* EOF */
                }
		
		/* removes extra \n at the end of the student name input */
		name_length = strlen(node->Student.student_name);
		if (name_length > 0 && node->Student.student_name[name_length - 1] == '\n') {
    			node->Student.student_name[name_length - 1] = '\0';
		}




                if (fscanf(input_file, "%d", &node->Student.student_ID) != 1) {
                        fprintf(stderr, "Error reading student ID\n");
                        fclose(input_file);
                        return NULL;
                }



                /* Read the scores for Cat1 */
                if (fscanf(input_file, "%f %f %f", &node->Student.Cat1.score1, &node->Student.Cat1.score2, &node->Student.Cat1.score3) != 3) {
                        fprintf(stderr, "Error reading Cat1 scores\n");
                        fclose(input_file);
                        return NULL;
                }


                /* Read the scores for Cat2 */
                if (fscanf(input_file, "%f %f %f", &node->Student.Cat2.score1, &node->Student.Cat2.score2, &node->Student.Cat2.score3) != 3) {
                        fprintf(stderr, "Error reading Cat2 scores\n");                        
			fclose(input_file);
                        return NULL;
                }


                /* Read the scores for Cat3 */
                if (fscanf(input_file, "%f %f %f", &node->Student.Cat3.score1, &node->Student.Cat3.score2, &node->Student.Cat3.score3) != 3) {
                        fprintf(stderr, "Error reading Cat3 scores\n");
                        fclose(input_file);
                        return NULL;
                }


                /* Read the scores for Cat4 */
                if (fscanf(input_file, "%f %f %f", &node->Student.Cat4.score1, &node->Student.Cat4.score2, &node->Student.Cat4.score3) != 3) {
                        fprintf(stderr, "Error reading Cat4 scores\n");
                        fclose(input_file);
                        return NULL;
                }



		calculateGrades(node);


               	if (prev == NULL) {
    			head = current = node;
		}  else {
                        prev->next = node; /* Link the previous node to the new node */
                        current = node;
                }


		prev = current;


                /* Consume the empty line */
                fgets(buffer, sizeof(buffer), input_file);
        }
	
	return head;

}
 
