# comments in a Makefile start with sharp

# target all means all targets currently defined in this file
all: student_database.zip student_database_main 

# this target is the .zip file that must be submitted to Carmen
student_database.zip: Makefile student_database_main.c student_database.h readFile.c option3.c calculateGrades.c sortList.c option1.c traversePtr.c option2.c traversePtrChar.c option4.c option5.c option6.c option7.c merge.c mergeSort.c option8.c option10.c option9.c
	zip student_database.zip Makefile student_database_main.c student_database.h readFile.c option3.c calculateGrades.c sortList.c option1.c traversePtr.c option2.c traversePtrChar.c option4.c option5.c option6.c option7.c merge.c mergeSort.c option8.c option10.c option9.c

# this target is the bit cipher executable that requires redirected stdin
student_database_main: student_database_main.o readFile.o option3.o calculateGrades.o sortList.o option1.o traversePtr.o option2.o traversePtrChar.o option4.o option5.o option6.o option7.o merge.o mergeSort.o option8.o option10.o option9.o
	gcc student_database_main.o readFile.o option3.o calculateGrades.o sortList.o option1.o traversePtr.o option2.o traversePtrChar.o option4.o option5.o option6.o option7.o merge.o mergeSort.o option8.o option10.o option9.o -o student_database_main
 

# this target is the dependency for student_database_main
student_database_main.o: student_database_main.c student_database.h
	gcc -ansi -pedantic -g -c -o student_database_main.o student_database_main.c

# this target is the dependency for readFile
readFile.o: readFile.c student_database.h
	gcc -ansi -pedantic -g -c -o readFile.o readFile.c

# this target is the dependence for option3
option3.o: option3.c student_database.h
	gcc -ansi -pedantic -g -c -o option3.o option3.c

# this target is the dependence for calculateGrades
calculateGrades.o: calculateGrades.c student_database.h
	gcc -ansi -pedantic -g -c -o calculateGrades.o calculateGrades.c

# this target is the dependence for sortList
sortList.o: sortList.c student_database.h
	gcc -ansi -pedantic -g -c -o sortList.o sortList.c

# this target is the dependence for option1
option1.o: option1.c student_database.h
	gcc -ansi -pedantic -g -c -o option1.o option1.c

#this target is the dependence for traversePtr
traversePtr.o: traversePtr.c student_database.h
	gcc -ansi -pedantic -g -c -o traversePtr.o traversePtr.c

#this target is the dependence for option2
option2.o: option2.c student_database.h
	gcc -ansi -pedantic -g -c -o option2.o option2.c

#this target is the dependence for traversePtrChar
traversePtrChar.o: traversePtrChar.c student_database.h
	gcc -ansi -pedantic -g -c -o traversePtrChar.o traversePtrChar.c

#this target is the dependence for option4
option4.o: option4.c student_database.h
	gcc -ansi -pedantic -g -c -o option4.o option4.c

#this target is the dependence for option5
option5.o: option5.c student_database.h
	gcc -ansi -pedantic -g -c -o option5.o option5.c

#this target is the dependence for option6.c
option6.o: option6.c student_database.h
	gcc -ansi -pedantic -g -c -o option6.o option6.c

#this target is the dependence for option7.c
option7.o: option7.c student_database.h
	gcc -ansi -pedantic -g -c -o option7.o option7.c

#this target is the dependence for merge.c
merge.o: merge.c student_database.h
	gcc -ansi -pedantic -g -c -o merge.o merge.c

#this target is the dependence for mergeSort.c
mergeSort.o: mergeSort.c student_database.h
	gcc -ansi -pedantic -g -c -o mergeSort.o mergeSort.c

#this target is the dependence for option8.c
option8.o: option8.c student_database.h
	gcc -ansi -pedantic -g -c -o option8.o option8.c

#this target is the dependence for option10.c
option10.o: option10.c student_database.h
	gcc -ansi -pedantic -g -c -o option10.o option10.c

#this target is the dependence for option9.c
option9.o: option9.c student_database.h
	gcc -ansi -pedantic -g -c -o option9.o option9.c

# this target deletes all files produced from the Makefile
# so that a completely new compile of all items is required
clean:
	rm -rf *.o student_database_main student_database.zip