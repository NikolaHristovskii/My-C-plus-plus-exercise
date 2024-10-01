#include <iostream>

using namespace std;

void enterTheRightN(int &n)
{
    while (n < 3 || n % 2 != 1)
    {
        cout << "Enter a positive odd number greater than or equal to 3: " << endl;
        cin >> n;
    }
}

void fillQuadraticMatrix(int n, int originalMatrix[100][100])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> originalMatrix[i][j];
        }
    }
}

void printQuadraticMatrix(int n, int matrix[100][100])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

// Overloaded function for printing a 2x2 matrix
void printQuadraticMatrix(int matrix[2][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void findAndPrintMatrixWithSumOfRegions(int n, int originalMatrix[100][100])
{
    int sumRegionOne = 0, sumRegionTwo = 0, sumRegionThree = 0, sumRegionFour = 0;
    int matrixWithSumOfRegions[2][2];

    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            sumRegionOne += originalMatrix[i][j];
        }
    }
    matrixWithSumOfRegions[0][0] = sumRegionOne;

    for (int i = 0; i < n / 2; i++)
    {
        for (int j = n / 2; j < n; j++)
        {
            sumRegionTwo += originalMatrix[i][j];
        }
    }
    matrixWithSumOfRegions[0][1] = sumRegionTwo;

    for (int i = n / 2; i < n; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            sumRegionThree += originalMatrix[i][j];
        }
    }
    matrixWithSumOfRegions[1][0] = sumRegionThree;

    for (int i = n / 2; i < n; i++)
    {
        for (int j = n / 2; j < n; j++)
        {
            sumRegionFour += originalMatrix[i][j];
        }
    }
    matrixWithSumOfRegions[1][1] = sumRegionFour;

    // Use the overloaded print function for the 2x2 matrix
    printQuadraticMatrix(matrixWithSumOfRegions);
}

int main()
{
    int originalMatrix[100][100];
    int n;

    cout << "Enter a positive odd number greater than or equal to 3 for the matrix size:" << endl;
    cin >> n;
    enterTheRightN(n);

    cout << "Enter the elements of the matrix:" << endl;
    fillQuadraticMatrix(n, originalMatrix);

    cout << "The entered matrix is:" << endl;
    printQuadraticMatrix(n, originalMatrix);

    cout << "The matrix with the sum of each region is:" << endl;
    findAndPrintMatrixWithSumOfRegions(n, originalMatrix);

    return 0;
}
