#include <iostream>

using namespace std;

void insertMatrix(int matrix[10][10], int n, int m)
{
    int number;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> number;
            matrix[i][j] = number;
        }
    }
}

void printMatrix(int matrix[10][10], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void transformTheNumberIntoItsOwnTens(int matrix[10][10], int n, int m, int matrixTwo[10][10])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrixTwo[i][j] = (matrix[i][j] / 10) % 10;
        }
    }
}

int main()
{
    int matrix[10][10];
    int matrixTwo[10][10];
    int n, m;

    cout << "Enter the number of rows and columns of the matrix:" << endl;
    cin >> n >> m;

    cout << "Enter elements of the matrix:" << endl;
    insertMatrix(matrix, n, m);

    cout << "Entered matrix:" << endl;
    printMatrix(matrix, n, m);

    cout << "Matrix with the tens digits of the numbers:" << endl;
    transformTheNumberIntoItsOwnTens(matrix, n, m, matrixTwo);
    printMatrix(matrixTwo, n, m);

    return 0;
}
