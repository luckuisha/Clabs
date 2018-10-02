#include <stdio.h>

int main(int argc, char **argv)
{
	char letter1, letter2, letter3, letter4;
	double band1 = 0, band2 = 0, resistance = 0;
	double multiplier = 1, tolerance = 0;
	
	puts("Please enter the 1st band:");
	scanf(" %c", &letter1);						//User inputs variables
	
	puts("Please enter the 2nd band:");
	scanf(" %c", &letter2);
	
	puts("Please enter the multiplier band:");
	scanf(" %c", &letter3);
	
	puts("Please enter the tolerance band:");
	scanf(" %c", &letter4);
	
	printf("Resistor bands: ");
	
		if (letter1 == 'K' || letter1 == 'k')		//these if and else if statements are assigning each letter to a specific color
		{
			band1 = 0.0;							//for each letter, a number is assigned to either band1, band2, multiplier, and tolerance
			printf("Black ");					//in order for the program to print the color, this printf statement is located here so that it prints according to the corresponding letter
		} 
		else if (letter1 == 'B' || letter1 == 'b')
		{
			band1 = 10.0;
			printf("Brown ");
		}
		else if (letter1 == 'R' || letter1 == 'r')
		{
			band1 = 20.0;
			printf("Red ");
		}
		else if (letter1 == 'O' || letter1 == 'o')
		{
			band1 = 30.0;
			printf("Orange ");
		}
		else if (letter1 == 'E' || letter1 == 'e')
		{
			band1 = 40.0;
			printf("Yellow ");
		}
		else if (letter1 == 'G' || letter1 == 'g')
		{
			band1 = 50.0;
			printf("Green ");
		}
		else if (letter1 == 'U' || letter1 == 'u')
		{
			band1 = 60.0;
			printf("Blue ");
		}
		else if (letter1 == 'V' || letter1 == 'v')
		{
			band1 = 70.0;
			printf("Violet ");
		}
		else if (letter1 == 'Y' || letter1 == 'y')
		{
			band1 = 80.0;
			printf("Grey ");
		}
		else if (letter1 == 'W' || letter1 == 'w')
		{
			band1 = 90.0;
			printf("White ");
		}
	
	
	
		if (letter2 == 'K' || letter2 == 'k')
		{
			band2 = 0.0;
			printf("Black ");
		}
		else if (letter2 == 'B' || letter2 == 'b')
		{
			band2 = 1.0;
			printf("Brown ");
		}
		else if (letter2 == 'R' || letter2 == 'r')
		{
			band2 = 2.0;
			printf("Red ");
		}
		else if (letter2 == 'O' || letter2 == 'o')
		{
			band2 = 3.0;
			printf("Orange ");
		}
		else if (letter2 == 'E' || letter2 == 'e')
		{
			band2 = 4.0;
			printf("Yellow ");
		}
		else if (letter2 == 'G' || letter2 == 'g')
		{
			band2 = 5.0;
			printf("Green ");
		}
		else if (letter2 == 'U' || letter2 == 'u')
		{
			band2 = 6.0;
			printf("Blue ");
		}
		else if (letter2 == 'V' || letter2 == 'v')
		{
			band2 = 7.0;
			printf("Violet ");
		}
		else if (letter2 == 'Y' || letter2 == 'y')
		{
			band2 = 8.0;
			printf("Grey ");
		}
		else if (letter2 == 'W' || letter2 == 'w')
		{
			band2 = 9.0;
			printf("White ");
		}
	
	
		if (letter3 == 'K' || letter3 == 'k')
		{
			multiplier = 1.0;
			printf("Black ");
		}
		else if (letter3 == 'B' || letter3 == 'b')
		{
			multiplier = 10.0;
			printf("Brown ");
		}
		else if (letter3 == 'R' || letter3 == 'r')
		{
			multiplier = 100.0;
			printf("Red ");
		}
		else if (letter3 == 'O' || letter3 == 'o')
		{
			multiplier = 1000.0;
			printf("Orange ");
		}
		else if (letter3 == 'E' || letter3 == 'e')
		{
			multiplier = 10000.0;
			printf("Yellow ");
		}
		else if (letter3 == 'G' || letter3 == 'g')
		{
			multiplier = 100000.0;
			printf("Green ");
		}
		else if (letter3 == 'U' || letter3 == 'u')
		{
			multiplier = 1000000.0;
			printf("Blue ");
		}
		else if (letter3 == 'V' || letter3 == 'v')
		{
			multiplier = 10000000.0;
			printf("Violet ");
		}
		else if (letter3 == 'L' || letter3 == 'l')
		{
			multiplier = 0.1;
			printf("Gold ");
		}
		else if (letter3 == 'S' || letter3 == 's')
		{
			multiplier = 0.01;
			printf("Silver ");
		}
	
		
		if (letter4 == 'B' || letter4 == 'b')
		{
			tolerance = 1.0;
			printf("Brown");
		}
		else if (letter4 == 'R' || letter4 == 'r')
		{
			tolerance = 2.0;
			printf("Red");
		}
		else if (letter4 == 'G' || letter4 == 'g')
		{
			tolerance = 0.5;
			printf("Green");
		}
		else if (letter4 == 'U' || letter4 == 'u')
		{
			tolerance = 0.25;
			printf("Blue");
		}
		else if (letter4 == 'V' || letter4 == 'v')
		{
			tolerance = 0.1;
			printf("Violet");
		}
		else if (letter4 == 'Y' || letter4 == 'y')
		{
			tolerance = 0.05;
			printf("Grey");
		}
		else if (letter4 == 'L' || letter4 == 'l')
		{
			tolerance = 5.0;
			printf("Gold");
		}
		else if (letter4 == 'S' || letter4 == 's')
		{
			tolerance = 10.0;
			printf("Silver");
		}
	
	resistance = (band1 + band2) * multiplier;
	
	
	if (resistance >= 1000 && resistance < 1000000)
	{
		resistance /= 1000;	
		printf("\nResistance: %.2lf kOhms +/- %.2lf% \n", resistance, tolerance);
	}
	else if (resistance >= 1000000)
	{
		resistance /= 1000000;	
		printf("\nResistance: %.2lf MOhms +/- %.2lf% \n", resistance, tolerance);
	}
	else 
		printf("\nResistance:%.2lf Ohms +/- %.2lf% \n", resistance, tolerance);
	
	return 0;
}
