
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream fout;
    string record;

    // Open file in append mode
    fout.open("records.txt", ios::app);

    if (!fout) {
        cout << "File cannot be opened!";
        return 1;
    }

    cout << "Enter records (-1 to stop):" << endl;

    while (true) {
        getline(cin, record);

        if (record == "-1")
            break;

        fout << record << endl;
    }

    fout.close();

    // Open file for reading
    ifstream fin("records.txt");

    if (!fin) {
        cout << "File cannot be opened!";
        return 1;
    }

    cout << "\nAll Records:\n";

    while (getline(fin, record)) {
        cout << record << endl;
    }

    fin.close();

    return 0;
}