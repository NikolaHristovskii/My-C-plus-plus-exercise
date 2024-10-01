#include <iostream>

using namespace std;

void insertMatrix(int matrix[10][10], int n, int m)
{
    int number;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> number;
            matrix[i][j] = number;
        }
    }
}

void printMatrixWithoutNegatives(int matrix[10][10], int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(matrix[i][j] != -1)
            {
                cout << matrix[i][j] << "\t";
            }
        }
        cout << endl;
    }
}

bool numberIsContainedInMatrix(int matrix[10][10], int n, int m, int number)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(matrix[i][j] == number)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int matrix[10][10];
    int matrixWithoutDuplicates[10][10];
    int n, m;

    cout << "Enter the number of rows and columns of the matrix:" << endl;
    cin >> n >> m;

    cout << "Enter the elements of the matrix:" << endl;
    insertMatrix(matrix, n, m);

    cout << "The entered matrix is:" << endl;
    printMatrixWithoutNegatives(matrix, n, m);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            matrixWithoutDuplicates[i][j] = -1;
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            bool numberExists = numberIsContainedInMatrix(matrixWithoutDuplicates, n, m, matrix[i][j]);
            if(!numberExists)
            {
                matrixWithoutDuplicates[i][j] = matrix[i][j];
            }
        }
    }

    cout << "The matrix without duplicates is:" << endl;
    printMatrixWithoutNegatives(matrixWithoutDuplicates, n, m);

    return 0;
}
