#include <stdio.h>

int main(int argc, char **argv)
{
	int n = 1, i = 0, j = 0, a = -1, b, c;		//i are rows, and j are columns
	printf("Enter the number of rows in the triangle: ");
	scanf("%d", &n);							//n is the rows of pyramids

		
	for(i = 1; i <= n - 1; i++)					//this is n-1 so that the last row can be filled with chevrons
	{
		for(j = 1; j <= n - i; j++)
		{
			printf(" ");						//this figures out the spacing before the chevrons
		}
		printf("^");							//this prints the first set of chevrons
		
		if(i != 1)								//this is to make sure that it prints no space at the first row
		{
		a = a + 2;								//this figures out the spacing in between the chevrons
		for(b = 1; b <= a; b++)
			printf(" ");						//this prints the spaces
			printf("^");						//this prints the chevron after the spaces
		}

		printf("\n");							//adds a new line after the process is done
	}
	
	if(i == n)
		for (c = 0; c < (2 * n) - 1 ;c++)		//this makes sure that the last line is just all chevrons
			printf("^");
		printf("\n");
	
	return 0;
}