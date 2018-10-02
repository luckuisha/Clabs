#include <stdio.h>
#include <math.h>
int main(int argc, char **argv)
{
	double a,b,c,average,stddev;
	printf("enter three numbers \n");
	scanf("%lf %lf %lf",&a,&b,&c);
	
	average=(a+b+c)/3;
	stddev=(pow((a-average),2)+pow((b-average),2)+pow((c-average),2)/(2));
	stddev=(pow(stddev,0.5));
	printf("\n This is your average and standard deviation respectivly %lf %lf", average, stddev);
	
	return 0;
}
