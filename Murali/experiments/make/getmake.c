
#include "HEADER/header.h"
int main()
{
	unsigned long int i;
	char **__file_names;	
	char executable[100];
	FILE *_fp, *_fp1;
	unsigned long int line_count = 0;
	char choice;

	/*    ==============>  Display makegen rules to user <===============   */

	


	printf( "=======>  Welcome to makegen (Auto makefile generator) v1.o  <======\n\n"
		    " * Please do following changes : \n"
		    " - Create directory \"SOURCE\" and move all source files to this directory.\n"	
		    " - Create directory \"OBJECT\" and move all object files to this directory.\n"
		    " - Create directory \"HEADER\" and move all header files to this directory.\n\n"
		    " - create headerfile in \"HEADER\" folder & name it as header.h"
		      " & add all prototypes &  header paths in this file.\n\n"
		    " - Now open your all of your c source files in your SOURCE directory"
			  " & \n  change the header as #include \"../HEADER/header.h\"\n\n"
		    " - \"makegen\" will remove all files other than *.c in SOURCE directory."
		    " please backup them\n\n"
			" - if you succesfully made all above changes .....\n"
		    " -  press 'y' to continue else 'n' to exit.(y/n) : "
		  );

	scanf("%c",&choice);

	if(choice == 'n')
		return 0;
	
	/*  Remove files other than .c */

	system(	"rm SOURCE/*.o SOURCE/*.o~ SOURCE/*.s SOURCE/*.s~"
			" SOURCE/*.txt SOURCE/*.text~ SOURCE/*.c~ 2> trash.txt"
		  );

	/*  list out the source files in source directory and move them to 
			SOURCE directory. */

	system("ls SOURCE -1 | sed -e 's/\\.c$//' > temp.txt");
	_fp = fopen("temp.txt", "r");



	/*   ========>  Allocating memory dynamically for filenames <====== */	
	/*  "flcount()" will get the line count in a file   */
	/*  "flccount()" will get the character count in line */
	/*  "flread()" will read line in a file */

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

	printf("Enter executable file name : ");
	scanf("%s", executable);

	// open makefile
	_fp1 = fopen("makefile", "w");
	
	// if makefile have any data clear it
	if(_fp != NULL)
		fwrite("",0,0,_fp);

	// open makefile in "append" mode
	_fp1 = fopen("makefile", "a+");
	
	fwrite(&executable,1 ,strlen(executable) ,_fp1);
	fwrite(" : ",1,3,_fp1);


	for(i = 0;i < line_count; i++)
	{
		fwrite("OBJECT/", 1, 7, _fp1);
		fwrite(__file_names[i],1 ,strlen(__file_names[i]), _fp1);
		fwrite(".o", 1, 2, _fp1);
		fwrite(" ",1 , 1,_fp1);
	}
	
	fwrite("\n\tgcc -Wall -o ", 1,15 , _fp1);

	fwrite(&executable,1 ,strlen(executable) ,_fp1);
	
	fwrite(" ",1,1,_fp1);
	
	for(i = 0;i < line_count; i++)
	{
		fwrite("OBJECT/", 1, 7, _fp1);
		fwrite(__file_names[i],1 ,strlen(__file_names[i]), _fp1);
		fwrite(".o", 1, 2, _fp1);
		fwrite(" ",1 , 1,_fp1);
	}
	
	 fwrite("\n",1,1,_fp1);

	for(i = 0; i < line_count; i++ )
	{
		// main.o : main.c
		
        fwrite("OBJECT/", 1, 7, _fp1);
		fwrite(__file_names[i],1 ,strlen(__file_names[i]), _fp1);
		fwrite(".o", 1, 2, _fp1);
		fwrite(" : ",1,3,_fp1);

		fwrite("SOURCE/", 1, 7, _fp1);
		fwrite(__file_names[i],1 ,strlen(__file_names[i]), _fp1);
		fwrite(".c", 1, 2, _fp1);

		fwrite("\n\t\tgcc -Wall -c ", 1, 16, _fp1);

		fwrite("-o ", 1, 3, _fp1);
		fwrite("OBJECT/", 1, 7, _fp1);
	    fwrite(__file_names[i],1 ,strlen(__file_names[i]), _fp1);
     	fwrite(".o ", 1, 3, _fp1);

		
		fwrite("SOURCE/", 1, 7, _fp1);
		fwrite(__file_names[i],1 ,strlen(__file_names[i]), _fp1);
		fwrite(".c", 1, 2, _fp1);		
	
		fwrite("\n",1,1,_fp1);	
	
	}


	fclose(_fp1);
	fclose(_fp);
	remove("temp.txt");
	remove("trash.txt");
	
//	for(int i=0; i< n; i++)
	
	


		
}
 
