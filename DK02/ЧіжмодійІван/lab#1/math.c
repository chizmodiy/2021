#include<stdio.h>
#include"math.h"




float factorial(int number) {
	long result = 1;

	if (number < 0) {
		printf("Error...(<0)\n\t");

	}

	for (int i = 1; i <= number; i++) { // create factorial
		result *= i;
	}

	return result;
}


float sum_factor(int start, int finish)
{
	long result = 0;
	if (start < 0) start = -start;
	if (finish < 0) finish = -finish;

	for (int i = start; i < finish; i++)
	{  // for factorial make sum of numbers
		result += factorial(i + finish);
	}

	return result;
}



float  my_sqr(int number) {
	int temp = 0, x = 1;
	if (number < 0)
	{
		printf("Error...(<0)\n\t");
	}


	while (temp != x) {
		temp = number / x;
		if (temp == x) return x;
		x++;
	}

}

double result(int A, int B, int C)
{
	return (double)A * (double) (  dil( my_sqr (B + C)  , B ) + (double)sum_factor(0, A));  // function for print result of functions
}

float dil(float a, float b)
{
	if (b == 0)
	{
		printf("\tError! Values greater than 0\n");
		

	}
	else
	{
		return (float)(a / b);
	}
}

