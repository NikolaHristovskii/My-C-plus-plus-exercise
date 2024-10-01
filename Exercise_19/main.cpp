#include <iostream>

using namespace std;

void print(const char* p, int d)
{
    for(int i = 0; i < d; i++)
    {
        cout << *(p + i);
    }
    cout << endl;
}

int main()
{
    const char pesna[] = "Line in the sand - Hot Chip";
    int d = sizeof(pesna) / sizeof(pesna[0]);
    const char* p = &pesna[0];
    print(pesna, d);
    cout << "First character: " << *p << endl;
    cout << "Address of first character: " << reinterpret_cast<intptr_t>(p) << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    p += 18;
    cout << "Moving pointer to the artist's name by: 18 places" << endl;
    cout << "Content after moving the pointer: " << p << endl;
    cout << "Address from where the moved pointer starts: " << reinterpret_cast<intptr_t>(p) << endl;

    return 0;
}
