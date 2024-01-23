/* contains function prototypes in header file */

#ifndef STUDENT_DATABASE_H
#define STUDENT_DATABASE_H

#include <stdio.h>

struct Cat_Grade{
        float score1;
        float score2;
        float score3;
        float Cumulative;
};

struct Data {
	char* student_name;
        int student_ID;
        struct Cat_Grade Cat1;
        struct Cat_Grade Cat2;
        struct Cat_Grade Cat3;
        struct Cat_Grade Cat4;
        float Current_Grade;
        float Final_Grade;
};

typedef struct Node {
        struct Data Student;
        struct Node *next;
} Node;

Node* readFile(FILE* input_file);

void calculateGrades(Node* node);

void option3(Node* head);

void sortList(struct Node** head);

void option1(Node* head);

Node* traversePtr(int ID, Node* head);

void option2(Node* head);

Node* traversePtrChar(const char* lName, Node* head);

void option4(Node* head);

void option5(Node* head);

void option6(Node* head);

void option7(Node* head);

Node *merge(Node *left, Node *right);

void mergeSort(Node** head);

void option8(Node **head);

void option9(Node **head);

void option10(Node *head, char* output_name);

#endif

