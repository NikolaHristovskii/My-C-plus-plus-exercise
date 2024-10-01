#include <iostream>

using namespace std;

void fillArrayWithElements(int n, int arr[100]) {
    int element;

    for (int i = 0; i < n; i++) {
        cin >> element;
        arr[i] = element;
    }
}

void printArray(int n, int arr[100]) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\t";
    }
}

void swapElements(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void sectionSort(int n, int arr[100]) {
    for (int i = 0; i < n - 1; i++) {
        int miN = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[miN] > arr[j]) {
                miN = j;
            }
        }
        if (miN != i) {
            swapElements(&arr[miN], &arr[i]);
        }
    }
}

int main() {
    int arr[100];
    int n;

    cout << "Enter the number of elements in the array:" << endl;
    cin >> n;

    cout << "Enter the elements of the array:" << endl;
    fillArrayWithElements(n, arr);
    cout << "Your array is:" << endl;
    printArray(n, arr);
    cout << endl;
    sectionSort(n, arr);
    cout << "The sorted array is:" << endl;
    printArray(n, arr);

    return 0;
}
