#include <iostream>
#include <set>
#include <sstream>

using namespace std;

set<string> cj;
set<string>::iterator it;
string linha, palavra, res;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    while (n--)
    {
        stringstream ss;
        getline(cin, linha);
        ss << linha;
        while (ss >> palavra)
            cj.insert(palavra);

        for (it = cj.begin(); it != cj.end(); it++)
        {
            res += " " + *it;
        }

        cout << res.substr(1) << endl;

        cj.clear(); ss.clear();
        res = "";
    }
}