#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)
{
	double n1, n2, n3, average, stddev;		//a, b, and c are the three numbers defined as variables
	printf("Enter three numbers:\n");		//asks user to enter the variables
	scanf("%lf %lf %lf", &n1, &n2, &n3);	//allows user to input the three numbers a,b, and c
	average = (n1 + n2 + n3) / 3.0;			//using the values a,b,c to calculate mean
	stddev = pow(((pow((n1 - average), 2.0) + pow((n2 - average), 2.0) + pow((n3 - average), 2.0)) / (2.0)), 0.5); 	//uses values to calculate standard deviation
	printf("The mean is %.2lf and the standard deviation is %.2lf \n", average, stddev); //prints values on terminal
	
	return 0;
	}
