#include "Header.h"
#include <stdlib.h>

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
    ifstream fin("input3.txt");
    if (fin.is_open()) {
        /*int c = 0;
        vector <int> hz;
        while (c < 50)
        {
            int start = 0;
            int end = 49;
            int y = rand() % (end - start + 1) + start;
            bool t = false;
            for (int i = 0; i < hz.size(); i++)
                t = y == hz[i];
            if (!t)
            {
                hz.push_back(y);
                cout << c << ' ' << y << ' ' << rand() % (end - start + 1) + start << endl;
                if (hz.size() == 10)
                {
                    c += 1;
                    hz.clear();
                }
            }
        }*/
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
        Dubenko(fin);
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