#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

#include<stdlib.h>

int build_matrix(int osx, int osy)
{
	
	int start;
	int j, i; // first matrix
	int n, m; // secd matrix

	int matrix_1;
	int matrix_2;
	int* matr_1[4][4];
	int* matr[4][4];
	


	scanf("pass value x : &d", &osx);
	scanf("pass value x : &d", &osy);
	scanf("%d", &start);

	if (start != NULL)
	{
		for (j = 0; j < osx; j++)
		{
			for (i = 0; i < osy; i++)
			{
				matr[j][i] = 21;
				matrix_1 = matr[j][i];
				printf("%d\t", matr[j][i]); // frst matrix
			}
			printf("\n");
		}

		printf("   \t     +");
		printf("\n");



		for (n = 0; n < osx; n++)
		{
			for (m = 0; m < osy; m++)
			{
				matr_1[n][m] = 6;
				matrix_2 = matr_1[n][m];

				printf("%d\t", matr_1[n][m]);  //secd matrix
			}
			printf("\n");
		}

		printf("   \t     =");
		int sum_matrix = matrix_1 + matrix_2;
		int d, c;
		printf("\n");


		for (d = 0; d < osx; d++)
		{
			for (c = 0; c < osy; c++)
			{
				printf("%d\t", sum_matrix);
			}
			printf("\n");
		}

	}


}
