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
    ifstream fin("input5.txt");
    if (fin.is_open()) {
        int c = 0;
        vector <int> hz;
        /*while (c < 30)
        {
            int start = 0;
            int end = 29;
            int y = rand() % (end - start + 1) + start;
            bool t = false;
            for (int i = 0; i < hz.size(); i++)
                t = y == hz[i];
            if (!t)
            {
                hz.push_back(y);
                cout << c << ' ' << y << ' ' << rand() % (end - start + 1) + start + 1 << endl;
                if (hz.size() == 8)
                {
                    c += 1;
                    hz.clear();
                }
            }
        }*/
        cout << "Kondarev\n";
        Kondarev(fin);
        cout << endl;
        fin.clear();
        fin.seekg(0);
        cout << "T. Erik\n";
        TimirbaevErik(fin);
        fin.clear();
        fin.seekg(0);
        cout << endl;
        cout << "T. Ernest\n";
        TimirbaevErnest(fin);
        fin.clear();
        fin.seekg(0);
        cout << endl;
        cout << "Varligin\n";
        Varligin(fin);
        fin.clear();
        fin.seekg(0);
        cout << endl;
        cout << "Dubenko\n";
        Dubenko(fin);
        fin.clear();
        fin.seekg(0);
        cout << endl;
        cout << "Zaharov\n";
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