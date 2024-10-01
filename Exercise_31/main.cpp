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

int sumOfEvenNumbersInMatrix(int matrix[10][10], int n, int m)
{
    int sumOfEven = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] % 2 == 0)
            {
                sumOfEven += matrix[i][j];
            }
        }
    }
    return sumOfEven;
}

int sumOfOddNumbersInMatrix(int matrix[10][10], int n, int m)
{
    int sumOfOdd = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] % 2 != 0)
            {
                sumOfOdd += matrix[i][j];
            }
        }
    }
    return sumOfOdd;
}

int main()
{
    int matrix[10][10];
    int n, m;

    cout << "Enter the number of rows and columns of the matrix:" << endl;
    cin >> n >> m;

    cout << "Enter the elements of the matrix:" << endl;
    insertMatrix(matrix, n, m);

    cout << "The entered matrix is:" << endl;
    printMatrix(matrix, n, m);

    cout << "Results\nSum of even numbers: " << sumOfEvenNumbersInMatrix(matrix, n, m) << " \nSum of odd numbers: " << sumOfOddNumbersInMatrix(matrix, n, m) << endl;

    return 0;
}
