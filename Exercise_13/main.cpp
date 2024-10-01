#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    int br;
    char eden;
    string str = "Nikola Hristovski INKI961";

    eden = str.back();

    if (isdigit(eden)) {
        br = eden - '0';

        cout << "Last character as digit: " << br << endl;


        if (br % 2 == 0) {
            for (int i = 0; i < str.length(); i++) {
                char chhar = str[i];
                int value = chhar + br;
                cout << "[" << str[i] << "]\t" << "[" << value << "]\t" << "[" << (char)value << "]" << endl;
            }
        } else {
            for (int i = 0; i < str.length(); i++) {
                char chhar = str[i];
                int value = chhar - br;
                cout << "[" << str[i] << "]\t" << "[" << value << "]\t" << "[" << (char)value << "]" << endl;
            }
        }
    } else {
        cout << "The last character is not a digit." << endl;
    }

    return 0;
}
