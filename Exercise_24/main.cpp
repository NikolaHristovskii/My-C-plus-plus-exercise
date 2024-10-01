#include <iostream>

using namespace std;

int main()
{
    int duplicates = 0;
    int index = 0;
    cout << "Enter your index:" << endl;
    cin >> index;
    int e;
    int d;
    int s;
    int i;

    int largestNumber;

    if (index >= 1000)
    {
        i = index / 1000;
        s = (index / 100) % 10;
        d = (index / 10) % 10;
        e = index % 10;
        cout << i << " " << s << " " << d << " " << e << endl;

        if (i > s)
        {
            largestNumber = i;
        }
        else
        {
            largestNumber = s;
        }
        if (largestNumber > d)
        {
            largestNumber = largestNumber;
        }
        else
        {
            largestNumber = d;
        }
        if (largestNumber > e)
        {
            largestNumber = largestNumber;
        }
        else
        {
            largestNumber = e;
        }
        cout << "The largest number is: " << largestNumber << endl;
        if (largestNumber == i)
        {
            duplicates++;
        }
        if (largestNumber == s)
        {
            duplicates++;
        }
        if (largestNumber == d)
        {
            duplicates++;
        }
        if (largestNumber == e)
        {
            duplicates++;
        }
        if (duplicates >= 1)
        {
            cout << "This number has: " << duplicates << " duplicates" << endl;
        }
    }
    else
    {
        s = (index / 100) % 10;
        d = (index / 10) % 10;
        e = index % 10;
        cout << s << " " << d << " " << e << endl;
        if (s > d)
        {
            largestNumber = s;
        }
        else
        {
            largestNumber = d;
        }
        if (largestNumber > e)
        {
            largestNumber = largestNumber;
        }
        else
        {
            largestNumber = e;
        }
        cout << "The largest number is: " << largestNumber << endl;
        if (largestNumber == s)
        {
            duplicates++;
        }
        if (largestNumber == d)
        {
            duplicates++;
        }
        if (largestNumber == e)
        {
            duplicates++;
        }
        if (duplicates >= 1) cout << "This number has: " << duplicates << " duplicates" << endl;
    }
    return 0;
}
