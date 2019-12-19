/*
Final Project - EXTRAORDINARYSCHOOL
Purpose: This project presents a menu to user chose if he want to enter students grade, or displays the students record, 
class average, or student average.
Int the enter students average, the user can enter first and last name, after input all students the user can 
entry with grades by class code.
By: Iara Santos
Date: 12/8/19
*/

#include "stdio.h"
#include <stdlib.h>
#include <string.h>

//struct
typedef struct student {
	char name[30];
		float grade[5][5];
}s;
//global variables
int iMenu = 0;
int courseCode = 0;
//index
int x = 0;
int names, y, z;

//list of names
s std[5];
//list of grade
s stdG;

//prototype
int inputName();
int mainMenu();
int menuCourse();
float inputGrade(int y, s* std, int names);
int main() {
	//local variables
	float sum = 0;
	float average[5] = { 0 };
	char kGoing = 'y';
	char menuGrade = 'y';
	int countGrade = 0;	
	char nameCompare[15] = { 0 };
	float studentAverage = 0;

		//repeat Main Menu
	do {

		iMenu = mainMenu();
		while (iMenu < 1 || iMenu > 5) {
			printf("\nInvalid option. Try again!\n\n");
			iMenu = mainMenu();
		}
		if (iMenu == 1) {
			printf("\n\tEXTRAORDINARY SCHOOL - INSERT DATA");
			printf("\n==========================================================\n");
			names = inputName();

			//repeat Code Course Menu
			do {
				courseCode = menuCourse();
				while (courseCode != 314 && courseCode != 222 && courseCode != 345 && courseCode != 572 && courseCode != 123) {
					printf("\nInvalid option. Try again!\n\n");
					courseCode = menuCourse();
				}
				//Input Grades
				if (courseCode == 314) {
					y = 0;
					printf("\nEnter Math grade\n");
					average[y] = inputGrade(y, std->name, names);					
				}
				if (courseCode == 222) {
					printf("\nEnter English grade\n");
					y = 1;
					average[y] = inputGrade(y, std->name, names);
				}
				if (courseCode == 345) {
					printf("\nEnter History grade\n");
					y = 2;
					average[y] = inputGrade(y, std->name, names);
				}
				if (courseCode == 572) {
					printf("\nEnter Geography grade\n");
					y = 3;
					average[y] = inputGrade(y, std->name, names);
				}
				if (courseCode == 123) {
					printf("\nEnter Science grade\n");
					y = 4;
					average[y] = inputGrade(y, std->name, names);
				}
				printf("\nIs there more grades? ");
				scanf(" %c", &menuGrade);

				system("cls");

			} while (menuGrade == 'y' || menuGrade == 'Y');
		}
		//Display Students Record
		if (iMenu == 2) {
			printf("\n\tEXTRAORDINARY SCHOOL - STUDENTS RECORD");
			printf("\n==========================================================\n");
			for (z = 0; z < names; z++) {
				printf("\n%s: ", std[z].name);
				for (y = 0; y < 5; y++) {
					if (y == 0 && stdG.grade[y][z] != 0) {
						printf("\nMath: ");
						printf(" %.2f", stdG.grade[y][z]);
					}
					else if (y == 1 && stdG.grade[y][z] != 0) {
						printf("\nEnglish: ");
						printf(" %.2f", stdG.grade[y][z]);
					}
					else if (y == 2 && stdG.grade[y][z] != 0) {
						printf("\nHistory: ");
						printf(" %.2f", stdG.grade[y][z]);
					}

					else if (y == 3 && stdG.grade[y][z] != 0) {
						printf("\nGeography: ");
						printf(" %.2f", stdG.grade[y][z]);
					}
					else if (y == 4 && stdG.grade[y][z] != 0) {
						printf("\nScience: ");
						printf(" %.2f", stdG.grade[y][z]);
					}
				}
				printf("\n==========================================================\n");
			}
		}
		//display class average by code
		if (iMenu == 3) {
			printf("\n\tEXTRAORDINARY SCHOOL - CLASS AVERAGE");
			printf("\n==========================================================\n");
			
			do {
				courseCode = menuCourse();
				while (courseCode != 314 && courseCode != 222 && courseCode != 345 && courseCode != 572 && courseCode != 123) {
					printf("\nInvalid option. Try again!\n\n");
					courseCode = menuCourse();
				}
				printf("\n==========================================================\n");
				if (courseCode == 314) {
					y = 0;
					printf("\tMath Average");					
					printf("\nThe class average is %.2f", average[y]);
					printf("\n==========================================================\n");
					
				}
				if (courseCode == 222) {					
					y = 1;
					printf("\tEnglish Average");
					printf("\nThe class average is %.2f", average[y]);
					printf("\n==========================================================\n");
				}
				if (courseCode == 345) {
					
					y = 2;
					printf("\tHistory Average");
					printf("\nThe class average is %.2f", average[y]);
					printf("\n==========================================================\n");
				}
				if (courseCode == 572) {					
					y = 3;
					printf("\tGeography Average");
					printf("\nThe class average is %.2f", average[y]);
					printf("\n==========================================================\n");
				}
				if (courseCode == 123) {
					
					y = 4;
					printf("\tScience Average");
					printf("\nThe class average is %.2f", average[y]);
					printf("\n==========================================================\n");
				}
				printf("\nDo you want to see another grade[y/n]? ");
				scanf(" %c", &menuGrade);

				system("cls");

			} while (menuGrade == 'y' || menuGrade == 'Y');
		}
			//display student average by first and last name
			if (iMenu == 4) {	
				countGrade = 0;				
				sum = 0;
				printf("\n\tEXTRAORDINARY SCHOOL - RECORD BY STUDENT");
				printf("\n==========================================================\n");
					printf("\nEnter student's name: ");
					getchar();
					gets(nameCompare);					
					for (z = 0; z < names; z++) {
						for (y = 0; y < 5; y++) {
							if (strstr(nameCompare, std[z].name) != NULL) {																
								if (y == 0 && stdG.grade[y][z] != 0) {
									printf("\nMath: ");
									printf(" %.2f", stdG.grade[y][z]);
									sum += stdG.grade[y][z];
									countGrade++;
								}									
								else if (y == 1 && stdG.grade[y][z] != 0) {
									printf("\nEnglish: ");
									printf(" %.2f", stdG.grade[y][z]);
									sum += stdG.grade[y][z];
									countGrade++;
								}									
								else if (y == 2 && stdG.grade[y][z] != 0) {
									printf("\nHistory: ");
									printf(" %.2f", stdG.grade[y][z]);
									sum += stdG.grade[y][z];
									countGrade++;
								}									
								else if (y == 3 && stdG.grade[y][z] != 0) {
									printf("\nGeography: ");
									printf(" %.2f", stdG.grade[y][z]);
									sum += stdG.grade[y][z];
									countGrade++;
								}									
								else if(y == 4 && stdG.grade[y][z] != 0) {
									printf("\nScience: ");
									printf(" %.2f", stdG.grade[y][z]);
									sum += stdG.grade[y][z];
									countGrade++;
								}									
							}							
						}
					}
					if (countGrade == 0) {
						printf("\nStudent not found!");							
					}
					else {
						studentAverage = sum / countGrade;
						printf("\nThe student average is %.2f", studentAverage);
						printf("\n==========================================================\n");
					}
			}				
			
			printf("\nDo you want to continue [y/n]? ");
			scanf(" %c", &kGoing);
			system("cls");

		} while (kGoing == 'y' || kGoing == 'Y');
		printf("\nThe Extraordinary School thanks you for your visit!!\n");

	return 0;
}
//function read name and return amount
int inputName() {
	char answer;
	
		do {
			//to allow max 5 name's input
			if (x < 5) {
				printf("%d# Student name: ", x + 1);
				getchar();
				gets(std[x].name);
				//increment struct index 
				x++;
				//to allow less than 5 input
				printf("\nIs there more students? [y/n]: ");
				scanf(" %c", &answer);
				printf("\n");				
				
			}			
		} while (x <= 4 && answer == 'y' || answer == 'Y');
		system("cls");
	return x;
}
//options to input data or display data
int mainMenu() {	
	
	printf("\n\tREPORT CARD - EXTRAORDINARY SCHOOL");
	printf("\n==========================================================");
	printf("\n||\t\t\t\t\t\t\t||");
	printf("\n||\t1. Create a student record: \t\t\t||");
	printf("\n||\t2. Display the students record: \t\t||");
	printf("\n||\t3. Display a class average: \t\t\t||");//maybe casting
	printf("\n||\t4. Display a student average: \t\t\t||"); //sort	
	printf("\n||\t5. Exit: \t\t\t\t\t||");
	printf("\n||\t\t\t\t\t\t\t||");
	printf("\n==========================================================");
	printf("\nEnter your choice: ");
	scanf(" %d", &iMenu);
	//clean screen
	system("cls");
	return iMenu;
}
//menu course to chose by code
int menuCourse() {	
	
	printf("\tSUBJECT\t\t | COURSE CODE");
	printf("\n==========================================================");
	printf("\n||\t\t\t\t\t\t\t||");
	printf("\n||\tMath\t\t | 314\t\t\t\t||");
	printf("\n||\tEnglish\t\t | 222\t\t\t\t||");
	printf("\n||\tHistory\t\t | 345\t\t\t\t||");
	printf("\n||\tGeography\t | 572\t\t\t\t||");
	printf("\n||\tScience\t\t | 123\t\t\t\t||");
	printf("\n||\t\t\t\t\t\t\t||");
	printf("\n==========================================================");
	printf("\nEnter Course Code: ");
	scanf("%d", &courseCode);
	
	return courseCode;	
}
//function to accept grade input and return the average of this grades
float inputGrade(int y, s *std, int index) {
	float sum = 0;
	int countGrade = 0;
	float average[6] = {0};	
	for (z = 0; z < names; z++) {
		printf("%s: ", std[z].name);		
		scanf("%f", &stdG.grade[y][z]);
		sum += stdG.grade[y][z];
		countGrade++;			
	}	
	return average[y] = sum / countGrade;
}





