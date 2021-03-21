#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

string natal, lingua, nome;

int main()
{
    int n, m;
    cin >> n;
    map<string, string> k;
    getline(cin, lingua);
    for (int i = 1; i <= (n * 2); i++)
    {
        if (i % 2 != 0)
            getline(cin, lingua);
        else 
        {

            getline(cin, natal);
            k[lingua] = natal;
        }
    }

    cin >> m;
    getline(cin, lingua);
    for (int i = 1; i <= m * 2; i++)
    {
        if (i % 2 != 0)
            getline(cin, nome);
        else
        {
            getline(cin, lingua);
            cout << nome << endl << k[lingua] << endl << endl;
            continue;
        }
    }
}
