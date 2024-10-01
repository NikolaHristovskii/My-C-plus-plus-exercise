#include <iostream>
#include <cstring>
#include <cctype>
#include <string>

using namespace std;

void CheckLettersNumbersCharacters(int numberOfCharacters, string sentence)
{
    int lowercaseLetters = 0, uppercaseLetters = 0, digits = 0, specialCharacters = 0;
    for (int i = 0; i < numberOfCharacters; i++)
    {
        if (islower(sentence[i]))
        {
            lowercaseLetters++;
        }
        else if (isupper(sentence[i]))
        {
            uppercaseLetters++;
        }
        else if (isdigit(sentence[i]))
        {
            digits++;
        }
        else
        {
            specialCharacters++;
        }
    }

    cout << "Number of lowercase letters: " << lowercaseLetters << endl;
    cout << "Number of uppercase letters: " << uppercaseLetters << endl;
    cout << "Total digits: " << digits << endl;
    cout << "Number of special characters: " << specialCharacters << endl;
    cout << "Total characters: " << numberOfCharacters << endl;
}

int main()
{
    int numberOfCharacters;
    string sentence;

    cout << "Enter a sentence: ";
    getline(cin, sentence);

    numberOfCharacters = sentence.length();
    CheckLettersNumbersCharacters(numberOfCharacters, sentence);

    return 0;
}
