#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <set>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

set<string> lista;
string s, p;
int n;

int main()
{_
    cin >> n;
    getline(cin, s);
    while (n--)
    {
        getline(cin, s);
        s += ' ';
        p = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                lista.insert(p);
                p = "";
                continue;
            }
            p += s[i];
        }

        int ok = 0;

        while (lista.size())
        {
            if (ok) cout << ' ';
            cout << *(lista.begin());
            ok = 1;
            lista.erase(*(lista.begin()));
        }

        cout << endl;
    }
}