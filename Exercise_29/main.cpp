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

void swapMinAndMax(int matrix[10][10], int n, int m)
{
    int maxValue = matrix[0][0], minValue = matrix[0][0], maxI, maxJ, minI, minJ;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (maxValue < matrix[i][j])
            {
                maxI = i;
                maxJ = j;
                maxValue = matrix[i][j];
            }
            if (minValue > matrix[i][j])
            {
                minI = i;
                minJ = j;
                minValue = matrix[i][j];
            }
        }
    }

    int temp = matrix[minI][minJ];
    matrix[minI][minJ] = matrix[maxI][maxJ];
    matrix[maxI][maxJ] = temp;
}

int main()
{
    int matrix[10][10];
    int n, m;

    cout << "Enter the number of rows and columns of the matrix:" << endl;
    cin >> n >> m;

    cout << "Enter elements of the matrix:" << endl;
    insertMatrix(matrix, n, m);

    cout << "The entered matrix is:" << endl;
    printMatrix(matrix, n, m);

    swapMinAndMax(matrix, n, m);

    cout << "Matrix with swapped positions of max and min values!" << endl;
    printMatrix(matrix, n, m);

    return 0;
}
