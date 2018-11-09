#include <stdio.h>
#include "declaration.c"
#include "formatting.c"
#define BUFFER 1000

char* format_data(char *, ...);
//FILE *flseek( const unsigned int, const FILE *);

char part_2[] = "wa3rsnmglgbt0qc0m3aju55n";
char part_6[] = "2018-10-23";
char part_8[] = "10%2F23%2F2018";
char part_10[] = "2018-10-23";
char part_12[] = "2018-10-23";
char part_14[] = "2018-10-24";
char part_16[] = "10%2F23%2F2018";
char part_18[] = "2018%2C10%2C24";
char part_20[] = "2018%2C10%2C24";
char part_22[] = "2018-10-24";
char part_24[] = "3";
char part_26[] = "3";
char part_28[] = "3";
char part_30[] = "1";
char part_32[] = "15";
char part_34[] = "15";
char part_36[] = "Assignments";
char part_38[] = "worked+on+single+linked+list";


int main()
{

	FILE *fp;
	char *temp;
	//int status = 0;	
	
	temp = format_data("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s", part_1, part_2, part_3, part_4, part_5, part_6,part_7, part_8, part_9, part_10, part_11, part_12, part_13, part_14, part_15, part_16, part_17, part_18, part_19, part_20, part_21, part_22, part_23, part_24, part_25, part_26, part_27, part_28, part_29, part_30, part_31, part_32, part_33, part_34, part_35, part_36, part_37, part_38, part_39);

system (temp);

}



