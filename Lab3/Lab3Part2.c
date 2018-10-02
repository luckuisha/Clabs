#include <stdio.h>

int main(int argc, char **argv)
{
	double n1, n2;
	char lettr;
	
		printf ("Enter first number: ");
		scanf ("%lf", &n1);
		printf ("Enter second number: ");
		scanf ("%lf", &n2);
		printf ("Enter calculation command (one of a, s, m, or d): ");
		scanf (" %c", &lettr);
		
		if (lettr =='a')
			printf("Sum of %.2lf and %.2lf is %.2lf \n", n1, n2, n1 + n2);		//%.2lf is to make sure its 2 decimal places
		else if (lettr == 's')
			printf("Difference of %.2lf from %.2lf is %.2lf \n", n1, n2, n1 - n2);
		else if (lettr == 'm')
			printf("Product of %.2lf and %.2lf is %.2lf \n", n1, n2, n1 * n2);
		else if (lettr == 'd')
		{
			if (n2==0)					//requires if statement in case the divisor is 0
			printf("Error, trying to divide by zero \n");
			else
			printf("Division of %.2lf by %.2lf is %.2lf \n", n1, n2, n1 / n2);
		}
		else
			printf("Error, unknown calculation command given \n");		//prints error incase a different letter is used
	
	return 0;
}