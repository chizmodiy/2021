#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include"Header.h"

int main(void)
{
	int row, col;
	printf("enter values for the x-axis:");
	scanf("%d", &row);
	printf("enter values for the y-axis:");
	scanf("%d", &col);
	printf("\n");

	
	int** matrix_01 = create_matrix(row, col);
	int** matrix_02 = create_matrix(row, col);

	random_value(matrix_01, row, col);
	random_value(matrix_02, row, col);
	int** suma = suma_matrix(matrix_01, matrix_02, row, col);
	print_matrix(matrix_01, row, col);
	printf("\n");
	print_matrix(matrix_02, row, col);
	printf("\n");
	print_matrix(suma, row, col);
	delete_matrix(suma, row);
	
	



}
