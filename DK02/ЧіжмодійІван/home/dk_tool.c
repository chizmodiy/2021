#include"dk_tool.h"

int** create_matrix(int row, int col)
{
    int** matrix = (int**)malloc(sizeof(int*) * row);
    for (int i = 0; i < row; i++)
    {
        *(matrix + i) = (int*)malloc(sizeof(int) * col); //виділяється память для матриці і записуються туди значення
    }
    return matrix;
}


void print_matrix(int** matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
         printf(" %d ", matrix[i][j]);    //після заповнення матриці виводить її на екран
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
            matrix[i][j] = rand() % 9; // запонює матрицю випадковими числами від 0 до 9
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
            suma[i][j] = matrix1[i][j] + matrix2[i][j]; // за допомогою циклу додаються  значення [i][j] кожної матриці
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
    for (int i = 0; i < row; i++) //звільняє пам'ятья , яка була виділена для матриці
    {
        free(*(matrix + i));
    }
    free(matrix);
}
