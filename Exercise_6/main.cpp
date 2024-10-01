#include <iostream>

using namespace std;

int main()
{
    char answer;
    int points = 0;

    cout << "Answer the following questions by entering the corresponding letter for the answer!\n";

    // Question 1
    cout << "1. What is the variable for declaring an integer:\n a. Integer b. Double c. Bool\n";
    cin >> answer;
    switch(answer)
    {
        case 'a': cout << "\nCorrect answer, so far you have: " << ++points << " point\n"; break;
        case 'b': cout << "\nWrong\n"; break;
        case 'c': cout << "\nWrong\n"; break;
        default: cout << "\nYou entered an invalid letter, skipping question\n";
    };

    // Question 2
    cout << "2. Who is Nikola Tesla:\n a. Programmer, b. Musician, c. Electrical Engineer\n";
    cin >> answer;
    switch(answer)
    {
        case 'c': cout << "\nCorrect answer, so far you have: " << ++points << " points\n"; break;
        case 'b': cout << "\nWrong\n"; break;
        case 'a': cout << "\nWrong\n"; break;
        default: cout << "\nYou entered an invalid letter, skipping question\n";
    };

    // Question 3
    cout << "3. How many continents are there on Earth:\n a. 5, b. 7, c. 3\n";
    cin >> answer;
    switch(answer)
    {
        case 'b': cout << "\nCorrect answer, so far you have: " << ++points << " points\n"; break;
        case 'a': cout << "\nWrong\n"; break;
        case 'c': cout << "\nWrong\n"; break;
        default: cout << "\nYou entered an invalid letter, skipping question\n";
    };

    // Question 4
    cout << "4. What does USB stand for: \n a. Universal Serial Bus, b. Universal Serial Bit, c. Universal Service Byte\n";
    cin >> answer;
    switch(answer)
    {
        case 'a': cout << "\nCorrect answer, so far you have: " << ++points << " points\n"; break;
        case 'b': cout << "\nWrong\n"; break;
        case 'c': cout << "\nWrong\n"; break;
        default: cout << "\nYou entered an invalid letter, skipping question\n";
    };

    // Question 5
    cout << "5. What is FOR used for in C++: \n a. Loops b. Conditions c. Variables\n";
    cin >> answer;
    switch(answer)
    {
        case 'a': cout << "\nCorrect answer, so far you have: " << ++points << " points\n"; break;
        case 'b': cout << "\nWrong\n"; break;
        case 'c': cout << "\nWrong\n"; break;
        default: cout << "\nYou entered an invalid letter, skipping question\n";
    };

    // Question 6
    cout << "6. Which logical operation gives a high signal when all inputs are 1:\n a. AND, b. OR c. NOT\n";
    cin >> answer;
    switch(answer)
    {
        case 'a': cout << "\nCorrect answer, so far you have: " << ++points << " points\n"; break;
        case 'b': cout << "\nWrong\n"; break;
        case 'c': cout << "\nWrong\n"; break;
        default: cout << "\nYou entered an invalid letter, skipping question\n";
    };

    // Question 7
    cout << "7. Which number system is base 10:\n a. Decimal, b. Binary, c. Hexadecimal\n";
    cin >> answer;
    switch(answer)
    {
        case 'a': cout << "\nCorrect answer, so far you have: " << ++points << " points\n"; break;
        case 'b': cout << "\nWrong\n"; break;
        case 'c': cout << "\nWrong\n"; break;
        default: cout << "\nYou entered an invalid letter, skipping question\n";
    };

    // Question 8
    cout << "8. What is cout:\n a. Input, b. Output, c. Output/Input\n";
    cin >> answer;
    switch(answer)
    {
        case 'b': cout << "\nCorrect answer, so far you have: " << ++points << " points\n"; break;
        case 'a': cout << "\nWrong\n"; break;
        case 'c': cout << "\nWrong\n"; break;
        default: cout << "\nYou entered an invalid letter, skipping question\n";
    };

    // Final grading based on points
    cout << "Your grade is:\t";
    switch(points)
    {
        case 0: case 1: cout << "Very poor = 5"; break;
        case 2: case 3: cout << "Satisfactory = 6 "; break;
        case 4: cout << "Fair = 7"; break;
        case 5: case 6: cout << "Good = 8 "; break;
        case 7: cout << "Very good = 9"; break;
        case 8: cout << "Excellent = 10"; break;
    };

    return 0;
}
