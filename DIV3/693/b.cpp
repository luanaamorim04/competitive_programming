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
#define all(v) (v.begin(), v.end())
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int t, n, x, dois, um, tot, qnt;

int main()
{_
    cin >> t;
    while (t--)
    {
        cin >> n;
        tot = um = dois = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            tot += x;
            (x == 1 ? um : dois)++;
        }   
        if (tot & 1) 
        {
            cout << "NO" << endl;
            continue;
        }
        qnt = tot>>1;
        while (dois)
        {
            if (qnt < 2) break;
            dois--, qnt -= 2;
        }
        while (um && qnt)
        {
            qnt--, um--;
        }

        cout << (qnt ? "NO" : "YES") << endl;
    }
}
