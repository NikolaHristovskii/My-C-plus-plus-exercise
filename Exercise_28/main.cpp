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

void findAndPrintMaxValueAndPosition(int matrix[10][10], int n, int m)
{
    int maxValue = matrix[0][0];
    int maxPositionI;
    int maxPositionJ;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (maxValue < matrix[i][j])
            {
                maxValue = matrix[i][j];
                maxPositionI = i;
                maxPositionJ = j;
            }
        }
    }
    cout << "The maximum value is: " << maxValue << "\non row: " << maxPositionI + 1 << "\non column: " << maxPositionJ + 1 << endl;
}

void findAndPrintMinValueAndPosition(int matrix[10][10], int n, int m)
{
    int minValue = matrix[0][0];
    int minPositionI;
    int minPositionJ;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (minValue > matrix[i][j])
            {
                minValue = matrix[i][j];
                minPositionI = i;
                minPositionJ = j;
            }
        }
    }
    cout << "The minimum value is: " << minValue << "\non row: " << minPositionI + 1 << "\non column: " << minPositionJ + 1 << endl;
}

int sumOfNumbersInMatrix(int matrix[10][10], int n, int m)
{
    int sumOfNumbers = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            sumOfNumbers += matrix[i][j];
        }
    }

    return sumOfNumbers;
}

int averageOfNumbersInMatrix(int matrix[10][10], int n, int m)
{
    int averageOfNumbers;

    averageOfNumbers = sumOfNumbersInMatrix(matrix, n, m) / (n * m);

    return averageOfNumbers;
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

    findAndPrintMaxValueAndPosition(matrix, n, m);
    findAndPrintMinValueAndPosition(matrix, n, m);

    cout << "The sum of the numbers in the matrix is: " << sumOfNumbersInMatrix(matrix, n, m) << endl;
    cout << "The average value in the matrix is: " << averageOfNumbersInMatrix(matrix, n, m) << endl;

    return 0;
}
