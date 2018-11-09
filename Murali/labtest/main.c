#include <stdio.h>
#include <string.h>
FILE *NameSorting(FILE *);


int main()
{
	FILE *input, *output;
	input = fopen("student_name.txt", "r");
	output = NameSorting(input);
	return 0;
}
