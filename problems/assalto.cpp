#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#define ll long long
#define INF 99999999
#define MAX 300000
#define MOD 1000000007
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int t, n, m, c, x, ok, d;

int main()
{_
    cin >> t;
    while (t--)
    {
        d = INF;
        cin >> n >> m;
        vector<int> p[51];
        for (int i = 0; i < m; i++)
        {
            cin >> c;
            while (c--)
            {
                cin >> x;
                p[i].push_back(x);
            }
        }

        for (int i = 0; i < (1<<m); i++)
        {
            ll resp = 0;
            for (int j = 0; j < m; j++)
            {
                if (i & (1<<j)) 
                {
                    for (int k = 0; k < p[j].size(); k++)
                    {
                        resp |= (1LL<<p[j][k]);
                    }
                }
            }

            if (__builtin_popcount(resp) >= n) 
            {
                ok = 1;
                d = min(d, __builtin_popcount(i));
            }
        }

       cout << (d == INF ? "Desastre!" : to_string(d)) << endl;
    }
}