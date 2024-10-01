#include <iostream>

using namespace std;

void fillArray(int arrayOne[100], int k) {
    int number;
    for (int i = 0; i < k; i++) {
        cin >> number;
        arrayOne[i] = number;
    }
}

void printArray(int arrayOne[100], int k) {
    for (int i = 0; i < k; i++) {
        cout << arrayOne[i] << " , ";
    }
    cout << endl;
}

void initializeMatrix(int matrixOne[10][10], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrixOne[i][j] = -1;
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

void transformArrayIntoMatrix(int matrixOne[10][10], int arrayOne[100], int k, int n, int m) {
    for (int i = 0, j = 0, q = 0; i < k; i++) {
        matrixOne[q][j] = arrayOne[i];
        j++;
        if ((i + 1) % m == 0) {
            q++;
            j = 0;
        }
    }
}

int main() {
    int arrayOne[100];
    int matrixOne[10][10];
    int k, n, m;

    cout << "Enter the number of elements in the array:" << endl;
    cin >> k;

    cout << "Enter elements of the array:" << endl;
    fillArray(arrayOne, k);
    printArray(arrayOne, k);

    cout << "Enter the number of rows and columns:" << endl;
    cin >> n >> m;

    initializeMatrix(matrixOne, n, m);

    cout << "The array transformed into a matrix:" << endl;
    transformArrayIntoMatrix(matrixOne, arrayOne, k, n, m);
    printMatrix(matrixOne, n, m);

    return 0;
}
