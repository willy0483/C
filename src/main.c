#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
	int id;
	char* name;
	float grade;
};

void print_student(struct Student* student);

int main()
{
	struct Student students[3];

	for(int i = 0; i < 3; i++)
	{
		char buffer[20];
		printf("Enter name for student %d: ", i);
		if(fgets(buffer, sizeof(buffer), stdin) == NULL)
		{
			fprintf(stderr, "Error reading Name.\n");
			exit(1);
		}
		buffer[strcspn(buffer, "\n")] = 0;
		students[i].name = malloc(strlen(buffer) + 1);
		if(students[i].name == NULL)
		{
			fprintf(stderr, "Memory allocation failed\n");
			exit(1);
		}
		strcpy(students[i].name, buffer);
		students[i].id = i + 1;
		students[i].grade = (i + 1) * 1.5f;
	}

	for(int i = 0; i < 3; i++)
	{
		print_student(&students[i]);
	}

	for(int i = 0; i < 3; i++)
	{
		free(students[i].name);
	}

	return 0;
}

void print_student(struct Student* student)
{
	printf("ID: %d\nName: %s\nGrade: %.1f\n\n", student->id, student->name, student->grade);
}
