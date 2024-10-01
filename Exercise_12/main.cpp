#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

void checkIfFileExists(string filename)
{
    fstream file;
    file.open(filename.c_str(), ios::in);
    if (file)
    {
        file.close();
        file.open(filename.c_str(), ios::app);
        cout << "The file exists, the sentence you entered will be added." << endl;
        file << filename;
        file.close();
        exit(0);
    }
    else
    {
        file.open(filename.c_str(), ios::out);
        cout << "The file does not exist, a new document will be created." << endl;
        file.close();
        exit(0);
    }
}

int main()
{
    string filename;
    cout << "Enter your sentence which is also the name of the file you are looking for or wish to create: ";
    getline(cin, filename);

    checkIfFileExists(filename);
}
