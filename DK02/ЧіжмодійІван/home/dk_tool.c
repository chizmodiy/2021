#include"Header.h"

int** create_matrix(int row, int col)
{
    int** matrix = (int**)malloc(sizeof(int*) * row);
    for (int i = 0; i < row; i++)
    {
        *(matrix + i) = (int*)malloc(sizeof(int) * col);
    }
    return matrix;
}


void print_matrix(int** matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
         printf(" %d ", matrix[i][j]);
        }
  
      printf("\n");
    }
}


void random_value(int** matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = rand() % 9;
        }
    }
}

int**  suma_matrix(int** matrix1, int** matrix2, int row, int col)
{
    int** suma = create_matrix(row, col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            suma[i][j] = matrix1[i][j] + matrix2[i][j];
        }
        printf("\n");
    }
    return suma;
}
void delete_matrix(int** matrix, int row)
{
    if (matrix == NULL)
    {
        return;
    }
    for (int i = 0; i < row; i++)
    {
        free(*(matrix + i));
    }
    free(matrix);
}
