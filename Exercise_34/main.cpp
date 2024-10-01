#include <iostream>

using namespace std;

void insertMatrix(int matrixOne[10][10], int n, int m) {
    int number;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> number;
            matrixOne[i][j] = number;
        }
    }
}

void printMatrix(int matrixOne[10][10], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrixOne[i][j] << "\t";
        }
        cout << endl;
    }
}

bool checkRowsAndColumnsAreEqual(int n, int m, int d, int b) {
    if (n != d || m != b) {
        return false;
    }
    return true;
}

bool matrixIsEqualToTheOtherMatrix(int matrixOne[10][10], int matrixTwo[10][10], int n, int m, int d, int b) {
    if (n != d || m != b) {
        return false;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrixOne[i][j] != matrixTwo[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int matrixOne[10][10];
    int matrixTwo[10][10];
    int n, m, d, b;

    cout << "Enter the number of rows and columns for the first matrix:" << endl;
    cin >> n >> m;

    cout << "Enter the number of rows and columns for the second matrix:" << endl;
    cin >> d >> b;

    bool checkRowsAndColumns = checkRowsAndColumnsAreEqual(n, m, d, b);
    if (!checkRowsAndColumns) {
        cout << "The matrices are not equal!" << endl;
    }
    if (checkRowsAndColumns) {
        cout << "Enter elements for the first matrix:" << endl;
        insertMatrix(matrixOne, n, m);

        cout << "The first matrix is:" << endl;
        printMatrix(matrixOne, n, m);

        cout << "Enter elements for the second matrix:" << endl;
        insertMatrix(matrixTwo, d, b);

        cout << "The second matrix is:" << endl;
        printMatrix(matrixTwo, d, b);

        bool isEqual = matrixIsEqualToTheOtherMatrix(matrixOne, matrixTwo, n, m, d, b);

        if (isEqual) {
            cout << "The matrices are equal!" << endl;
        } else {
            cout << "The matrices are not equal!" << endl;
        }
    }
    return 0;
}
