#include <stdio.h>

struct Student
{
	int id;
	char* name;
	float grade;
};

void print_student(struct Student* student);

int main()
{

	char name_arr[3][10] = { "Willaim", "Fin", "Bob" };
	struct Student students[3];

	for(int i = 0; i < 3; i++)
	{
		students[i].name = name_arr[i];
		students[i].id = i + 1;
		students[i].grade = (i + 1) * 1.5f;
	}

	for(int i = 0; i < 3; i++)
	{
		print_student(&students[i]);
	}

	return 0;
}

void print_student(struct Student* student)
{
	printf("ID: %d\nName: %s\nGrade: %.1f\n\n", student->id, student->name, student->grade);
}
