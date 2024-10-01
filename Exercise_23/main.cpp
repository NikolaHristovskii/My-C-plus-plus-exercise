#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Profile
{
    int IDnumber;
    string Nickname;
    float Level;
    bool operator<(const Profile& other) const
    {
        return Nickname < other.Nickname;
    }
};

int main()
{
    vector<Profile> profiles;

    for (int i = 0; i < 5; i++)
    {
        Profile p;
        cout << "Enter ID number for profile " << i + 1 << ": ";
        cin >> p.IDnumber;

        while (cin.fail())
        {
            cout << "Enter ID number for profile " << i + 1 << " (must be a number!): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> p.IDnumber;
        }

        cout << "Enter Nickname for profile " << i + 1 << ": ";
        cin >> p.Nickname;
        cout << "Enter Level for profile " << i + 1 << ": ";
        cin >> p.Level;

        while (cin.fail())
        {
            cout << "Enter Level for profile " << i + 1 << " (must be a number!): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> p.Level;
        }
        profiles.push_back(p);
        cout << "-*-*-*-*-*-*-*-*-*-*-*-*-\n";
    }
    cout << endl;

    cout << "Profiles in the vector:" << endl;

    for (vector<Profile>::iterator it = profiles.begin(); it != profiles.end(); ++it)
    {
        cout << "ID number: " << it->IDnumber << ", Nickname: " << it->Nickname << ", Level: " << it->Level << endl;
    }

    sort(profiles.begin(), profiles.end());
    cout << endl;

    cout << "Sorted profiles:" << endl;

    for (vector<Profile>::iterator it = profiles.begin(); it != profiles.end(); ++it)
    {
        cout << "ID number: " << it->IDnumber << ", Nickname: " << it->Nickname << ", Level: " << it->Level << endl;
    }

    cout << endl;

    string indexNameSurname;
    cout << "Enter index name surname" << endl;
    cin.ignore();
    getline(cin, indexNameSurname);

    cout << endl;

    ofstream outFile(indexNameSurname);

    if (outFile.is_open())
    {
        for (vector<Profile>::iterator it = profiles.begin(); it != profiles.end(); ++it)
        {
            outFile << it->IDnumber << " " << it->Nickname << " " << it->Level << endl;
        }

        outFile.close();
        cout << "Profiles have been saved! " << endl;
    }
    else
    {
        cout << "Profiles have not been saved! " << endl;
    }

    return 0;
}
