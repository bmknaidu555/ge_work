#include <stdio.h>
#include <stdlib.h>

int main()
{
	unsigned long int i;
	char **__file_names;
	FILE *_fp, *_fp1;
	unsigned long int line_count = 0;
	char choice;

	/*    ==============>  Fetch file names from C <===============   */
	printf("please rename source file directory to \"SOURCE\""
			"& object files directory to \"OBJECT\"(y/n)");
	scanf("%c",&choice);

	if(choice == 'n')
		return 0;

	system("ls object -1 | sed -e 's/\\.c$//' > temp.txt");
	_fp = fopen("temp.txt", "r");

	/*   ========>  Allocating memory dynamically for filenames <====== */	


	/*  "flcount()" will get the line count in a fie   */

	line_count = flcount( _fp );
	__file_names = (char**) malloc( line_count * sizeof(char *) );

	for(i = 0; i < line_count; i++)
	{
		//line number starts from 1
	    //allocating mmry dynmclly to each and evry filename

		int size = flccount(i+1, _fp);
		__file_names[i] =(char *) malloc( sizeof(char) * size);	
	}

	// read C file names into  multi dimensional array
	for(i = 0; i < line_count; i++)
		flread( __file_names , i+1, _fp );

	//clear the file if have or create one if dont have
	char executable[100];
	printf("Enter executable file name : ");
	scanf("%s", executable);

	_fp1 = fopen("makefile", "w");
	
	if(_fp != NULL)
		fwrite("",0,0,_fp);

	_fp1 = fopen("makefile", "a+");
	
	fwrite(&executable,1 ,strlen(executable) ,_fp1);
	fwrite(" : ",1,3,_fp1);


	for(i = 0;i < line_count; i++)
	{
		 fwrite("object/", 1, 9, _fp1);
		fwrite(__file_names[i],1 ,strlen(__file_names[i]), _fp1);
		fwrite(".o", 1, 2, _fp1);
		fwrite(" ",1 , 1,_fp1);
	}
	
	fwrite("\n\tgcc -o ", 1, 9, _fp1);

	fwrite(&executable,1 ,strlen(executable) ,_fp1);
	
	fwrite(" ",1,1,_fp1);	
	for(i = 0;i < line_count; i++)
	{
		fwrite(__file_names[i],1 ,strlen(__file_names[i]), _fp1);
		fwrite(".o", 1, 2, _fp1);
		fwrite(" ",1 , 1,_fp1);
	}
	
	 fwrite("\n",1,1,_fp1);

	for(i = 0; i < line_count; i++ )
	{
		// main.o : main.c
		fwrite(__file_names[i],1 ,strlen(__file_names[i]), _fp1);
        fwrite(".o", 1, 2, _fp1);
		fwrite(" : ",1,3,_fp1);

		fwrite(__file_names[i],1 ,strlen(__file_names[i]), _fp1);
		fwrite(".c", 1, 2, _fp1);

		fwrite("\n\t\tgcc -c ", 1, 10, _fp1);
		fwrite(__file_names[i],1 ,strlen(__file_names[i]), _fp1);
		fwrite(".c", 1, 2, _fp1);		
	
		fwrite("\n",1,1,_fp1);	
	
	}


	
//	for(int i=0; i< n; i++)
	
	


		
}
 
