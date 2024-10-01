#include <iostream>

using namespace std;

int insertBingoNumbers(int arrayOfBingoNumbers[100], int counter)
{
    int i = 0;
    int number;

    while (true)
    {
        cout << "Enter a number (1-90): ";
        cin >> number;

        if (number < 1 || number > 90)
        {
            break;
        }

        arrayOfBingoNumbers[i] = number;
        counter++;
        i++;
    }

    if (counter < 8)
    {
        cout << "You entered fewer than 8 numbers! Please enter at least 8 numbers:" << endl;
        return insertBingoNumbers(arrayOfBingoNumbers, 0);
    }
    return counter;
}

void printBingoNumbers(int arrayOfBingoNumbers[100], int countt)
{
    for (int i = 0; i < countt; i++)
    {
        cout << arrayOfBingoNumbers[i] << " ";
    }
    cout << endl;
}

void formAndPrintJokerNumber(int arrayOfNumbers[100], int countt, int arrayWithJokerNumber[100])
{
    for (int i = 0; i < countt; i++)
    {
        if (i < 7)
        {
            arrayWithJokerNumber[i] = arrayOfNumbers[i] % 10;
        }
        else
        {
            arrayWithJokerNumber[i] = arrayOfNumbers[i];
        }
    }
    cout << "Your Joker Number is: ";
    for (int i = 0; i < countt; i++)
    {
        cout << arrayWithJokerNumber[i];
    }
    cout << endl;
}

int main()
{
    int arrayOfBingoNumbers[100];
    int arrayWithJokerNumber[100];
    int counter = 0;
    int countt = 0;

    cout << "Enter 8 numbers between 1 and 90!" << endl;
    countt = insertBingoNumbers(arrayOfBingoNumbers, counter);

    cout << endl;

    cout << "Your numbers are: " << endl;
    printBingoNumbers(arrayOfBingoNumbers, countt);

    cout << endl;

    formAndPrintJokerNumber(arrayOfBingoNumbers, countt, arrayWithJokerNumber);

    return 0;
}
