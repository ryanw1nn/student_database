#include <stdio.h>
#include <stdlib.h>
#include "student_database.h"

void option6(Node *head){

	int IDNum;
	Node* current;
	
	int choice1;
	int choice2;
	int choice3;
	float newScore;
	char newline;	

printf("Enter the Student ID #: ");
	scanf("%d", &IDNum); 

	current = traversePtr(IDNum, head);

	

	printf("Insert a score for %s? Enter 1 if yes, enter 2 if no: ", current->Student.student_name);
	scanf("%d", &choice1);


	if(choice1 == 1) {

        	printf("What category?\n");
        	printf("1) Quizzes \n2) Midterms \n3) Homework \n4) Final\n");
        	scanf("%d", &choice2);
		
		switch(choice2){

		case 1:
			
        		printf("\nWhich score?\n");
        		printf("Enter 1, 2 or 3\n");
        		scanf("%d", &choice3);

			printf("Enter new score: ");
                        scanf("%f", &newScore);

			switch(choice3){
				case 1:			
					current->Student.Cat1.score1 = newScore;
					break;
				case 2:
                                        current->Student.Cat1.score2 = newScore;
				        break;
				case 3:
					current->Student.Cat1.score3 = newScore;
                                        break;
				default:
					printf("Error: invalid individual score\n");
			}
		break;
		case 2:
                        
                        printf("\nWhich score?\n");
                        printf("Enter 1, 2 or 3\n");
                        scanf("%d", &choice3);

                        printf("Enter new score: ");
                        scanf("%.2f", &newScore);

			switch(choice3){
                                case 1:
                                        current->Student.Cat2.score1 = newScore;
                                        break;
                                case 2:
                                        current->Student.Cat2.score2 = newScore;
                                        break;
                                case 3:
                                        current->Student.Cat2.score3 = newScore;
                                        break;
                                default:
                                        printf("Error: invalid individual score\n");
			}
		break;
		case 3:

                        printf("\nWhich score?\n");
                        printf("Enter 1, 2 or 3\n");
                        scanf("%d", &choice3);

                        printf("Enter new score: ");
                        scanf("%f", &newScore);

                        switch(choice3){
                                case 1:
                                        current->Student.Cat3.score1 = newScore;
                                        break;
                                case 2:
                                        current->Student.Cat3.score2 = newScore;
                                        break;                          
			        case 3:
                                        current->Student.Cat3.score3 = newScore;
                                        break;
                                default:
                                        printf("Error: invalid individual score\n");
			}
		break;
		case 4:

                        printf("\nWhich score?\n");
                        printf("Enter 1, 2 or 3\n");
                        scanf("%d", &choice3);

                        printf("Enter new score: ");
                        scanf("%f", &newScore);

                        switch(choice3){
                                case 1:
                                        current->Student.Cat4.score1 = newScore;
                                        break;
                                case 2:
                                        current->Student.Cat4.score2 = newScore;
                                        break;
                                case 3:
                                        current->Student.Cat4.score3 = newScore;
                                        break;
                                default:
                                        printf("Error: invalid individual score\n");
			}
                        break;
		default:	
			printf("Error: invalid category\n");
			return;
		}

	}else if(choice1 == 0) {
		printf("Exiting option 6.\n");
		return;
	}else {
		printf("Error: invalid input\n");
		return;
	}	
	
	printf("\n");

	
	while ((newline = getchar()) != '\n' && newline != EOF);
}

