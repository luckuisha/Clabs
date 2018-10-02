#include <stdio.h>
#include <math.h>

int DtoB(int);					//defines the functions
int BtoD(int);
int main(int argc, char **argv)
{
	char letr;
	int num;
	printf("Enter B for conversion of Binary to Decimal, OR\nEnter D for conversion of Decimal to Binary: ");
	scanf(" %c", &letr);
		if (letr == 'b' || letr == 'd')		//this makes sure that if the letter does not equal B, D, it ends the code
		{
		printf("Invalid Input, Goodbye\n");
		return 0;
		}
	printf("Enter your number: ");
	scanf("%d", &num);
	if(letr == 'B')
		BtoD(num);			//calls the function
	else if(letr == 'D')
		DtoB(num);
	
return 0;
}

int BtoD(int bin)
{
	int rem, val = 0, n = 0, orig;
	orig = bin;				//since original gets changed, this is to make sure a new variable equals the original
	while(bin > 0)
	{
		rem = bin % 10;			
		bin = bin / 10;
		val = val + rem * pow(2, n);
		n++;
	}
	printf("%d in binary = %d in decimal \n", orig, val);
	return val;
}

int DtoB(int dec)
{
	int remain, value = 0, cnt = 0, orig;
	orig = dec;
	while (dec > 0)
	{
		remain = dec % 2;
		dec = dec / 2;
		value = value + remain * pow(10,cnt);
		cnt++;
	}
	printf("%d in decimal = %d in binary\n", orig, value);
	return value;
}