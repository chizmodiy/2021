#pragma once
#include<stdio.h>

int** create_matrix(int row, int col);
void print_matrix(int** matrix, int row, int col);
void random_value(int** matrix, int row, int col);
int**  suma_matrix(int** matrix1, int** matrix2, int row, int col);
void delete_matrix(int** matrix, int row);
