#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned long flcount(FILE *fp);
unsigned long flccount(unsigned long, FILE*);
void flread(char *, unsigned long , FILE *);
void strlwr(char *);
int isValid(char *string);

struct node
{
	char *name;
	int roll_no;
};
void bubble_sort(struct node *, unsigned long);

FILE *NameSorting(FILE *stu_name)
{
	/* Get Line count in the file */
	long int line_count = flcount(stu_name); 
	
	struct node student_base[line_count];

	/* Move File pointer to 0th position */
	fseek(stu_name, 0, SEEK_SET);
	
	/* Get no of character in each line to allocate
		memory dynamically for each and evry name */
	int i = 0;
	long line_char_count = 0;

	for( i = 0; i < line_count; i++)
	{	
		line_char_count = flccount(i+1, stu_name);
		student_base[i].name = (char *) malloc(sizeof(char) * line_char_count );
	}

	/* Move the pointer to zero th position to read data */


	/* Memory is allocated dynamically for evry name 
	   Now read the names into array */

	for(i = 0; i < line_count; i++){
		flread(student_base[i].name, i+1, stu_name);	
	//	printf("%s\n", student_base[i].name);
		strlwr(student_base[i].name);		
		student_base[i].name[0] = student_base[i].name[0] - 32;
	}
	/* Now sort the list using sorting algorithm */

	bubble_sort(student_base, line_count);

	/* now assign roll no to every student */
	int roll_count;
	for(i = 0, roll_count = 804080; i < line_count; i++){
		
		// if valid it returns 1 else returns 0
		if(isValid(student_base[i].name))
		{
			student_base[i].roll_no = roll_count;
			roll_count++;
		}			
		else
			student_base[i].roll_no = -1;
	}

 	/* open a file and write into it */

	FILE *fp1;
	fp1 = fopen("student_info.txt", "w");
	
	for( i = 0; i < line_count; i++)
	{
		if(student_base[i].roll_no != -1)
			fprintf(fp1,"%s -> %d\n", student_base[i].name, student_base[i].roll_no);	
	}
	
	return fp1;

}

int isValid(char *string)
{
	while(*string != '\0')
	{
		if((*string >='a' && *string <= 'z') ||
								 (*string >= 'A' && *string <= 'Z'))
			string++;
		else
			 return 0;
		
	}
	return 1;
}

void strlwr(char *string)
{
	while(*string != '\0')
	{
		if(*string >= 'A' && *string <= 'Z'){
		*string = *string +32 ;
		}
		string++;
	
	}
}



unsigned long flcount(FILE *_fp)
{
	char data[100];
	unsigned long size;
	unsigned int count = 0;
	unsigned int i = 0;

	fseek(_fp, 0, SEEK_SET);

	while((size = fread(data, sizeof(char), 100, _fp)) > 0)
		for(i = 0; i < size; i++)
			if(data[i] == '\n')
				count++;
	return count;
}

unsigned long flccount(unsigned long line_no, FILE *_fp)
{
	char data[100];
	unsigned int size;
	unsigned int counter = 0; 
	unsigned int count = 0;
	unsigned int i = 0;

	fseek(_fp, 0, SEEK_SET);

	while((size = fread(data, 1, 100, _fp)) > 0) {			
		for(i = 0; (i < size) && count < line_no ; i++){
			if(count == (line_no-1))
				counter++;

			if(data[i] == '\n')
				count++;
		}
	}	
	
	// function returns the counter as (i.e length(filename)) + 1 
	// +1 is for NULL character '\0' 
	return counter;
}

void flread(char *__buffer, unsigned long line_no, FILE *_fp)
{
	char data[100];
	unsigned long size;
	unsigned long counter = 0; 
	unsigned long count = 0;
	unsigned int i = 0;
	fseek(_fp, 0, SEEK_SET);

	while((size = fread(data, 1, 100, _fp)) > 0)
	{
		/* made a loop from i = 0 -> entire size
			(i.e how many charcters read by fread ) */
		for(i = 0; (i < size) && (count < line_no) ; i++)
		{
			/*  if any character equals to '\n'
				 it indicates that end of the filename */
			if(data[i] == ' ')
				continue;

			if(data[i] == '\n'){
				count++;
			/*	if data[i] == '\n' then skip to next character position    */
				continue;	
			}

			if(count == (line_no-1))
			{
				__buffer[counter] = data[i];
				counter++;
			}
		}
	}
	__buffer[counter] = '\0';
	// function returns the counter as (i.e length(filename)) + 1 
	// +1 is for NULL character '\0' 
}


void bubble_sort(struct node *student_base, unsigned long size)
{
	struct node temp;
	unsigned long i = 0;
	unsigned long j = 0;

	for(i = 1; i < size; i++){
		for(j = 0; j < (size - i); j++){	
			if(strcmp(student_base[j].name, student_base[j+1].name) > 0){
				temp.name = student_base[j].name;
				student_base[j].name = student_base[j+1].name;
				student_base[j+1].name = temp.name;	
			}
		}	
	}

}
