#include <stdio.h>
#define new() printf("\n\n")

int getChoice()
{		
		new ();
		new ();
		int choice;

		new();
		printf("Please enter your choice : ");

		new();
		printf("1. Swap the bit values between s and d");
				
		new();
		printf("2. swap bit values between source ");
		printf("and destination of different numbers");
		
		new();
		printf("3. Copying n bits (right adjusted)");
		printf(" from bit position s in snum to bit position d in dnum.");

		new();
		printf("4. Toggle even bits and odd bits respectively");

		new();
		printf("5. Macro to test and set a bit position in a number");
	
		new();
		printf("6. Bit rotations");
	
		new();
		printf("7. Count the number of bits set and number of bits cleared");

		new();
		printf("8. Counting Leading and trailing bits");

		new();
		printf("10. Returns number with the ‘n’ bits that begin at");
		printf(" position p set to the right most n bits of y, "); 
		printf("leaving the other bits unchanged.");

		new();
		printf("11. Returns x with n bits that begin at position p inverted,");
		printf(" leaving others unchanged.");
		
		new();
		printf("12. Return (left adjusted) n-bit field of number");
		printf("that begins at position p.");
		
		new ();
		new ();
		new ();
		printf("Please enter your choice  :	");	
		
		scanf ("%d", &choice);
		return choice;

	
}
