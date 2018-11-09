#include <stdio.h>
#include <elf.h>

int main()
{
	Elf32_Ehdr elf_p;
	Elf32_Ehdr *p;

	printf("size of structure is %d",sizeof(elf_p));
	p = &elf_p;
	int size;
	FILE *_fp;
	char a[16];
	_fp = fopen("abc", "r");
	printf("%ld",ftell(_fp));
	size = fread(p, 1, 52, _fp);
	
	printf("Magic number is : ");
	int i;

	for(i = 0;i < 16; i++)
		printf("%02x ", p -> e_ident[i]);	
	
		


}
