#include <iostream>
#include <cmath>
using namespace std;

const int num1 = 96, num2 = 1;


int Addition(int addition){
    addition = num1 + num2;
    return addition;
}


int Subtraction(int subtraction){
    subtraction = num1 - num2;
    return subtraction;
}

int Multiplication(int multiplication){
    multiplication = num1 * num2;
    return multiplication;
}


int Division(int division){
    division = num1 / num2;
    return division;
}

int Exponentiation(int exponentiation){
    exponentiation = pow(num1, num2);
    return exponentiation;
}

int main()
{
    char oper;

    float addition, subtraction, multiplication, division, exponentiation;

    cout << "Choose an operation (+, -, *, /, ^)" << endl;
    cin >> oper;
    cout << "My index is 961" << endl;
    cout << "Your numbers are: " << num1 << " and " << num2 << endl;

    switch (oper) {
    case '+':
        cout << "Your result is: " << Addition(addition) << endl;
        break;
    case '-':
        cout << "Your result is: " << Subtraction(subtraction) << endl;
        break;
    case '*':
        cout << "Your result is: " << Multiplication(multiplication) << endl;
        break;
    case '/':
        cout << "Your result is: " << Division(division) << endl;
        break;
    case '^':
        cout << "Your result is: " << Exponentiation(exponentiation) << endl;
        break;
    default:
        cout << "Invalid operator entered" << endl;
        break;
    }
    return 0;
}
