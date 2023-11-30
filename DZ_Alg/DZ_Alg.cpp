#include "Header.h"

using namespace std;

int tryChoose(ifstream& fin, int min = -9999, int max = 9999) {
    int num;
    while ((cin >> num).fail() || (num < min) || (num > max)) {
        fin.clear();
        fin.ignore(10000, '\n');
    }
    return num;
}

int main()
{
    return 0;
}