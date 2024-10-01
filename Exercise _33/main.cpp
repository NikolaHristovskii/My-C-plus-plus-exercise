#include <iostream>

using namespace std;

void insertMatrix(int matrix[10][10], int n, int m) {
    int number;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> number;
            matrix[i][j] = number;
        }
    }
}

void printMatrix(int matrix[10][10], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int matrix[10][10];
    int n, m;

    cout << "Enter the number of rows and columns of the matrix:" << endl;
    cin >> n >> m;

    cout << "Enter elements in the matrix:" << endl;
    insertMatrix(matrix, n, m);

    cout << "The entered matrix is:" << endl;
    printMatrix(matrix, n, m);

    for (int i = 0; i < n; i++) {
        bool isIncreasingRow = true;
        bool isDecreasingRow = true;

        for (int j = 0; j < m - 1; j++) {
            if (matrix[i][j] <= matrix[i][j + 1]) {
                isDecreasingRow = false;
            }
            if (matrix[i][j] >= matrix[i][j + 1]) {
                isIncreasingRow = false;
            }
        }
        if (isIncreasingRow == true) {
            cout << "Row " << i << " is increasing!" << endl;
        } else if (isDecreasingRow == true) {
            cout << "Row " << i << " is decreasing!" << endl;
        } else {
            cout << "Row " << i << " is neither increasing nor decreasing" << endl;
        }
    }

    for (int i = 0; i < n; i++) {
        bool isIncreasingColumn = true;
        bool isDecreasingColumn = true;

        for (int j = 0; j < m - 1; j++) {
            if (matrix[j][i] <= matrix[j + 1][i]) {
                isDecreasingColumn = false;
            }
            if (matrix[j][i] >= matrix[j + 1][i]) {
                isIncreasingColumn = false;
            }
        }
        if (isIncreasingColumn == true) {
            cout << "Column " << i << " is increasing!" << endl;
        } else if (isDecreasingColumn == true) {
            cout << "Column " << i << " is decreasing!" << endl;
        } else {
            cout << "Column " << i << " is neither increasing nor decreasing" << endl;
        }
    }

    return 0;
}
