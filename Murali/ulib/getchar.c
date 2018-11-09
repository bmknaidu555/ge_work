#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


// unBuffered Version of getchar()

int ugetchar()
{	
	unsigned char c;
	return read(0,&c, 1) ? c: EOF;
	
}

//Buffered version of getchar()

int ugetchar2()
{	
	static unsigned char storage [BUFSIZ];
	static char *ptr = storage;
	static int n = 0;
	
	if (n == 0)
	{
		n = read(0, storage, sizeof storage);	
		ptr = storage;	
	}	

	if(--n >= 0)
	{	
		return *(ptr++);		
	} 

}

