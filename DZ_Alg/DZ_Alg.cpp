#include "Header.h"

using namespace std;

int tryChoose(ifstream& fin, int min, int max) {
    int num;
    while ((fin >> num).fail() || (num < min) || (num > max)) {
        fin.clear();
        fin.ignore(10000, '\n');
    }
    return num;
}

int main()
{
    ifstream fin("input.txt");
    if (fin.is_open()) {
        Kondarev(fin);
        cout << endl;
        fin.clear();
        fin.seekg(0);
        TimirbaevErik(fin);
        fin.clear();
        fin.seekg(0);
        cout << endl;
        Varligin(fin);
        fin.clear();
        fin.seekg(0);
        cout << endl;
        Zaharov(fin);
        fin.clear();
        fin.seekg(0);
        cout << endl;
    }
    else {
        
        cout << "Not found file!";
    }
    return 0;
}