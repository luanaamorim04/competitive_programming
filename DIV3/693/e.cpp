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

int t, n, ft[1<<20], y[1<<20], id[1<<20];
par v[1<<20];
map<int, int> mapa;

void update(int idx, int val, int x)
{
    while (idx <= n)
    {
        if (ft[idx] < val)
        {
            ft[idx] = val;
            id[idx] = x;
        }
        idx += lsb(idx);
    }
}

int query(int idx)
{
    int ans = INF, resp = -1;
    while (idx > 0)
    {
        if (ans < ft[idx])
        {
            ans = ft[idx];
            resp = id[idx];
        }
        idx -= lsb(idx);
    }
    return resp;
}

int main()
{_
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i].first >> v[i].second;
            y[i] = v[i].second;
            ft[i] = INF;
        }

        sort(v+1, v+1+n);
        sort(y+1, y+1+n);
        for (int i = 1; i <= n; i++)
        {
            mapa[y[i]] = i;
            update(i, mapa[v[i].second], i);
        }

        for (int i = 1; i <= n; i++)
        {
            update(i, ft[query(i - 1)], query(i - 1));
        }

        for (int i = 1; i <= n; i++)
        {
            int ini = 1, meio, fim = n;
            while (ini <= fim)
            {
                meio = ini + (fim-ini)/2;
                if (v[meio].first <= v[i].first) ini = meio + 1;
                else fim = meio - 1;
            }
            int idx = ini - 1;
            if (!idx)
            {
                cout << -1 << ' ';
                continue;
            }

            int idx2 = query(idx);
            if (ft[idx2] > mapa[v[i].second])
            {
                cout << -1 << ' ';
                continue;
            }

            cout << idx2 << ' ';
        }
        cout << endl;
    }
}
