#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculation.h"
#include "grades.h"
#include "ctype.h"
struct studentData
{
    char name[20];
    int ID; 
    float homework[3], exercise[3];
    float mid, final;
};

struct studentData std[100];
int i, j, n;
char grade = 'F';
FILE *fptr;
float r;

char input[64], checkss[64];

float validation(){
	r = 0;
	while(r == 0){
				printf("\nInput : ");
				gets(checkss);
				
				if (sscanf(checkss, "%f", &r) != 1){
					r = 0;
					printf("Invalid Input, Try Again!\n");
					continue;
				}
				if (r < 0 || r > 100){
					r = 0;
					printf("Invalid Range, Try Again!\n");
					continue;
				}
				else{
					return r;
					break;
				}
			}
}

void inputData(int n){
	int i;

	for(i = 0; i < n; i++){
		printf("=== Student GPA Calculator ===\n");
		printf("\n=== Input Data of Student %d ===\n", i+1);
		printf("\nStudent Name : ");
		scanf("%[^\n]", &std[i].name);
		
		printf("Student ID : ");
		scanf("%d", &std[i].ID);
		
		fflush(stdin);
		
		printf("Homework Grades (3 Grades)\n");
		for(j = 0; j < 3; j++){
			r = 0;
			printf("-- Grade %d --", j+1);
			std[i].homework[j] = validation();
		}
		
		printf("Exercise Grades (3 Grades)\n");
		for(j = 0; j < 3; j++){
			r = 0;
			printf("-- Grade %d--", j+1);
			std[i].exercise[j] = validation();
		}
		printf("-- Mid Exam Grade --");
		std[i].mid = validation();
		printf("-- Final Exam Grade --");
		std[i].final = validation();
		system("CLS");
	}
}

void showData(int n){
	int i;
	fprintf(fptr,"No\tStudent Name\tStudent ID\t HW1\t HW2\t HW3\tAvgHW\t EX1\t EX2\t EX3\tAvgEx\t Mid\tFinal\tTotal\tGrade\n");
	printf("No\tStudent Name\tStudent ID\t HW1\t HW2\t HW3\tAvgHW\t EX1\t EX2\t EX3\tAvgEx\t Mid\tFinal\tTotal\tGrade\n");
	for(i = 0; i < n; i++){
		float avgHomework = avgHw(std[i].homework[0], std[i].homework[1], std[i].homework[2]);
		float avgExercise = avgEx(std[i].exercise[0], std[i].exercise[1], std[i].exercise[2]);
		float totScore = totalScore(avgHomework, avgExercise, std[i].mid, std[i].final);
		grades(&totScore, &grade);
		
		fprintf(fptr,"%d\t%s\t%d\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t  %s\n", i+1,
		std[i].name, std[i].ID, 
		std[i].homework[0], std[i].homework[1], std[i].homework[2], avgHomework,
		std[i].exercise[0], std[i].exercise[1], std[i].exercise[2], avgExercise,
		std[i].mid, std[i].final, totScore, &grade);
		
		printf("%d\t%s\t%d\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t  %s\n", i+1,
		std[i].name, std[i].ID, 
		std[i].homework[0], std[i].homework[1], std[i].homework[2], avgHomework,
		std[i].exercise[0], std[i].exercise[1], std[i].exercise[2], avgExercise,
		std[i].mid, std[i].final, totScore, &grade);
	}
}

int main(){

	printf("=== Welcomoe to Student GPA Calculator ===\n");
	while(n == 0){
		printf("\nInput the number of student : ");
		fgets(input, 63, stdin);
		
		if (sscanf(input, "%d", &n) != 1){
			n = 0;
			printf("Invalid Input\n");
			continue;
		}
		if (n <= 0){
			n = 0;
			printf("Invald num of Student\n");
			continue;
		}
	}
	system("CLS");
	inputData(n);
	fptr = fopen("ResultGPA.txt","w");
	showData(n);
	fclose(fptr);
	printf("\nThe Data Already Saved in ResultGPA.txt\n");
}
