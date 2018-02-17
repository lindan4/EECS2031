#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000
#define MAX_STUDENTS 20

struct student
{
	char id[MAX_SIZE];
	char name[MAX_SIZE];
	char sex;
	double quizOneScore;
	double quizTwoScore;
	double midtermScore;
	double finalScore;
	double totalScore;
	
};

int main(void)
{
	
	int i, pos;
	pos = 0;
	
	struct student *list = (student *) malloc(MAX_STUDENTS * sizeof(student));
	struct student One = {"1234", "Lind", 'm', 10, 23, 23, 33, 33};
	*(list + pos) = One;
	pos++;
	struct student Two = {"3456", "Yon", 'm', 10 , 10, 10, 10, 10};
	*(list + pos) = Two;
	
	
	
	
	
	return 0;
}
