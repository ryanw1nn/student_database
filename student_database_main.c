#include "student_database.h"
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]) {


        /*input & initial variables */
        char *file_name = argv[1];
        FILE *input_file;
        char *output_name;
        Node* head;
        int optionVal;
        int endFunc;
        Node *current;


        printf("Reading student information from file %s\n\n", file_name);


        /*opening file */
        input_file = fopen(file_name, "r");
        if(input_file == NULL) {
                perror("Error opening file");
                return 1;
        }

	/*reading file */
        output_name = argv[2];
        head = readFile(input_file);

        fclose(input_file);


        mergeSort(&head);

        endFunc = 0;


        while(endFunc != 1) {
                printf("\nPlease enter an option between 1 and 10:\n");
                printf("1) Print Student Scores by Student ID\n");
                printf("2) Print Student Scores by Last Name\n");
                printf("3) Print Student Scores for All Students\n");
                printf("4) Recalculate Student Scores for a Single Student ID\n");
                printf("5) Recalculate All Student Scores\n");
                printf("6) Insert a score for a specific Student ID\n");
                printf("7) Calculate Final Grades\n");
                printf("8) Add a new student\n");
                printf("9) Delete a student\n");
                printf("10) Exit Program\n");

                printf("\nOption: ");
                scanf("%d", &optionVal);
                printf("\n");

                switch(optionVal) {

                        case 1:
                               	option1(head);
                                break;
                        case 2:
                               	option2(head);
                                break;
                        case 3:
                               	option3(head);
                                break;
                        case 4:
                               	option4(head);
                                break;
                        case 5:
                               	option5(head);
                                break;
                        case 6:
                               	option6(head);
                                break;
                        case 7:
                               	option7(head);
                                break;
                        case 8:
                               	option8(&head);
                                break;
                        case 9:
                               	option9(&head);
                                break;
                        case 10:
                                option10(head, output_name);
                                endFunc = 1;
                                break;
                        default:
                                endFunc = 1;
                                printf("Error: invalid option selected\n");
                                break;
                }
        }
	current = head;
        while (current != NULL) {
                struct Node* next = current->next;
                free(current->Student.student_name); /* Free the student name string */
                free(current);
                current = next;
        }

	return 0;
}
