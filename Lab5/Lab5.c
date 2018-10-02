#include <stdio.h>
int fact(int num);
int ncr(int num1, int num2);
int main(int argc, char **argv)
{
    while(1)							//creates omfomote loop since always true
    {
        int n, i, j, k;
        printf("Enter the number of rows: ");
        scanf("%d", &n);
        if (n < 0)						//if value is less than zero, ends code here
            return 0;
        else
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < n - (i + 1); j++)    //prints spaces on the left, before the pyramid. the i+1 is to skip the first row
                    printf("   ");
                for (k = 0; k <= i; k++)
                {
                if (i==k)
                     printf("%d", ncr(i, k));		//makes sure to not justify on the first value of the first column
                else if(i!=k)
                    printf("%-6d", ncr(i, k));		//makes sure to left justify when the value is not the first value
                }
                printf("\n");
            }
    }
    return 0;
}

int fact(int num)						//function for factorials
{
    int cnt, prod = 1;
    for(cnt = 1; cnt <= num; cnt++)
            prod *= cnt;
    return prod;
}

int ncr(int num1, int num2)				`//function for the values of pascals triangle
{
    int res;
    res = fact(num1) / (fact(num2) * fact(num1 - num2));
    return res;
}


