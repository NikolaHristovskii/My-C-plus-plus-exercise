#include <iostream>
#include <string>

using namespace std;

// Checking if the number has five digits
int getNumberWithFiveDigits(int number)
{
    int newNumber=number;

    while (newNumber>99999||newNumber<10000)
    {
        cout<<"You entered a number that may be negative or it has more or less digits than five!\n";
        cout<<"Enter a number that is positive and has five digits:"<<endl;
        cin>>newNumber;
    }

    return newNumber;
}

// Finding the max digit
int findTheMaxDigit(int number)
{
    int fifthDigit=0,fourthDigit=0,thirdDigit=0,secondDigit=0,firstDigit=0;

    firstDigit=number/10000;
    secondDigit=(number/1000)%10;
    thirdDigit=(number/100)%10;
    fourthDigit=(number/10)%10;
    fifthDigit=number%10;

    int arrayOfNumbers[5]= {firstDigit, secondDigit, thirdDigit, fourthDigit, fifthDigit};
    int maxDigit=arrayOfNumbers[0];

    for(int i=0; i<5; i++)
    {
        if(maxDigit<arrayOfNumbers[i])
        {
            maxDigit=arrayOfNumbers[i];
        }
    }

    return maxDigit;
}

// Encoding the string by adding the max digit
void encoding(string inputString,int maxDigit)
{
    int length=inputString.length();

    for(int i=0; i<length; i++)
    {
        inputString[i]=inputString[i]+maxDigit;
    }

    cout<<inputString<<endl;
}

// Decoding the string by subtracting the max digit
void decoding(string inputString,int maxDigit)
{
    int length=inputString.length();

    for(int i=0; i<length; i++)
    {
        inputString[i]=inputString[i]-maxDigit;
    }

    cout<<inputString<<endl;
}

int main()
{
    string inputString;
    int number;
    int maxDigit;
    int isEncodingFunction;

    cout << "Enter a string:" << endl;
    getline(cin,inputString);

    cout<<"Enter a five digit positive number:"<<endl;
    cin>>number;
    number=getNumberWithFiveDigits(number);

    maxDigit=findTheMaxDigit(number);
    cout<<"Max value: "<<maxDigit<<endl;

    cout<<"If you want to see the decoded version of the string enter 0, or enter 1 for encoded version:";
    cin>>isEncodingFunction;

    while(isEncodingFunction!=0 && isEncodingFunction!=1)
    {
        cout<<"You have entered number that is not 1 or 0. Try entering 0 or 1:";
        cin>>isEncodingFunction;
    }

    if(isEncodingFunction==1)
    {
        encoding(inputString, maxDigit);
    }

    if(isEncodingFunction==0)
    {
        decoding(inputString,maxDigit);
    }

    return 0;
}
