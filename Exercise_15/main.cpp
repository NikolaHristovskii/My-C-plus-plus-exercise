#include <iostream>
#include <ctype.h>

using namespace std;

int main() {
    int niza[] = { (int)'N', (int)'i', (int)'k', (int)'o', (int)'l',
                   (int)'a', (int)' ', (int)'H', (int)'r', (int)'i', (int)'s',
                   (int)'t', (int)'o', (int)'v', (int)'s', (int)'k', (int)'i',
                   (int)' ', (int)'9', (int)'6', (int)'1'
                 };

    int lengthArray1 = sizeof(niza) / sizeof(niza[0]);
    cout << "Array with ASCII code :" << endl;

    for (int i = 0; i < lengthArray1; i++) {
        cout << niza[i] << ",";
    }
    cout << endl;
    cout << "Array with characters :" << endl;

    for (int i = 0; i < lengthArray1; i++) {
        cout << (char)niza[i];
    }
    cout << endl;

    char c;
    cout << "Enter a character: " << endl;
    cin >> c;
    bool isContained = false;
    int countt = 0;
    int index = 0;

    for (int i = 0; i < lengthArray1; i++) {
        if ((int)c == niza[i]) {
            cout << "This array has a character like " << c << endl;
            break;
        }
    }

    for (int i = 0; i < lengthArray1; i++) {
        if ((int)c == niza[i]) {
            index = i;
            cout << "located at: " << index << endl;
            countt += 1;
            isContained = true;
        }
    }

    if (isContained) {
        cout << "The number of times your character is contained: " << countt << endl;
    } else {
        cout << "This array doesn't have the character " << endl;
    }

    char upper;
    cout << "My upper letters: ";
    for (int i = 0; i < lengthArray1; i++) {
        upper = (char)niza[i];
        if (isupper(upper)) {
            cout << upper << " ";
        }
    }
    cout << endl;

    return 0;
}
