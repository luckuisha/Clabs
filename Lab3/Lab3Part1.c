#include <stdio.h>

int main(int argc, char **argv)
{
	int tval = 1, n1, n2, n3, n4, sval1, sval2, sval3;		//tval is total number of cents, n1 are quarters, n2 are dimes, n3 are nickels, n4 are pennies. sval1, sval2, and sval3 are variable concerning the remainder
	while (tval < 100 && tval > 0)			//tval must satisfy this while in order to work
	{
		printf ("Please give an amount in cents less than 100: ");	//must be within loop so user can input multiple tvals
		scanf("%d", &tval);
		if (tval<100 && tval>0)		//if statement dealing with the tval
		{
			n1 = tval / 25;			//finding number of quarters by dividing
			sval1 = tval % 25;		//obtains remainder to see whats leftover
			n2 = sval1 / 10;		//repeats for other coins
			sval2 = sval1 % 10;
			n3 = sval2 / 5;
			sval3 = sval2 % 5;
			n4 = sval3;
			
			if (tval > 1)					//determines whether to print cents or cent
				printf("%d cents: ", tval);
			else if (tval == 1)
				printf("%d cents: ", tval);
				
				
			if (n1 > 1)	
				printf("%d quarters", n1);
			else if (n1 == 1)
				printf("%d quarter", n1);
			if (n1 != 0 && (n2 != 0 || n3 != 0 || n4 != 0))		//condition to print a comma or not
				printf(", ");
				
				
			if (n2 > 1)
				printf("%d dimes", n2);
			else if (n2 == 1)
				printf("%d dime",n2);
			if (n2 != 0 && (n3 != 0 || n4 != 0))
				printf(", ");
				
			if (n3 > 1)
				printf("%d nickels", n3);
			else if (n3 == 1)
				printf("%d nickel",n3);
			if (n3 != 0 && n4 != 0)
				printf(", ");
				
			if (n4 > 1)
				printf("%d cents", n4);
			else if (n4 == 1)
				printf("%d cent",n4);
			printf(".\n");						//this is included to make sure that the period is always included
			
		}
		else if (tval > 99 || tval < 1)			//if while condition fails, it prints Goodbye
			puts ("Goodbye.");
	}
	
	return 0;
}
