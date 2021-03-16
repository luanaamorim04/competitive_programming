#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring>
#define ll long long
#define INF 99999999
#define MAX 300000
#define MOD 1000000007
#define par pair<int, int>
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

string a, b, c, tmp;

int main()
{_
    getline(cin, a);
    getline(cin, b);
    cin >> c;
    int ok = 0;
    a += ' ';
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == ' ') 
        {
            if (tmp == c) 
            {
                cout << b << ' ' << tmp;
                ok = 1;
            }
            else cout << tmp;
            tmp = "";
            if (i != a.size() - 1 || !ok) cout << ' ';
        }
        else tmp += a[i];
    }

    if (!ok) cout << b;
    cout << endl;
}