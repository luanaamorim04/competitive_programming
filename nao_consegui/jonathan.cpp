#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <random>

using namespace std;

string s;
long long x, y;

int main()
{
    ifstream fin ("words.in");
    default_random_engine generator;
    uniform_int_distribution<int> distribution(1,10000);
    x = distribution(generator);
    y = distribution(generator);

    for (int i = 0; i < 10000; i++)
    {
        fin >> s;
        if (i == y) cout << s << ' ';
        if (i == x) cout << s << ' ';
    }

    y = distribution(generator);

    cout << endl;
}