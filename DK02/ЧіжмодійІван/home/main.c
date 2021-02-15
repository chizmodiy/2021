#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include"dk_tool.h"

int main(void)
{
	int row, col;
	printf("enter values for the x-axis:");
	scanf("%d", &row);
	printf("enter values for the y-axis:"); // ввід кількість рядків і стовбців
	scanf("%d", &col);
	printf("\n");

	
	int** matrix_01 = create_matrix(row, col); //створюється вказівник на вказівник 
	int** matrix_02 = create_matrix(row, col); // присвоюється вказівнику значення створеної матриці

	random_value(matrix_01, row, col); // кожен з вказівників заповнюється випадковими цифрами
	random_value(matrix_02, row, col);
	int** suma = suma_matrix(matrix_01, matrix_02, row, col); // додаються окремо значення кожної комірки
	print_matrix(matrix_01, row, col);// виводяться 2 заповнені матриці 
	printf("\n");
	print_matrix(matrix_02, row, col);
	printf("\n");
	print_matrix(suma, row, col); // друкується матриця з доданими  значеннями
	delete_matrix(suma, row); // звільняється память
	
	



}
