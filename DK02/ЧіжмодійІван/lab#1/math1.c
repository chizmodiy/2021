#include<stdio.h>
#include<math.h>
#include"math1.h"




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





double result(int A, int B, int C)
{
	return  (double)A * (double)(dil(sqrt(B + C), B) + (double)sum_factor(0, A)); // function for print result of functions
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

double sqrt_func(int a )
{
	if ( a< 0 )
	{
		printf("Error\n");
	}
	else
	{
		return sqrt(a);
	}
}
