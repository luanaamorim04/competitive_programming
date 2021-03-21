#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <stack>
#include <map>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define MAXN (int) 1e5 + 9
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

long long n, ans, ft[MAXN], k, arr[MAXN];
map<long long, long long> mapa, mapa2;

struct pessoa
{
    long long d, b, v;
};

int cmp(pessoa a, pessoa c)
{
    return a.b < c.b;
}

int cmp2(pessoa a, pessoa c)
{
    return a.d < c.d;
}

long long query(int idx)
{
    long long ans = 0;
    while (idx > 0)
    {
        ans = max(ans, ft[idx]);
        idx -= lsb(idx);
    }

    return ans;
}

void update(int idx, long long val)
{
    while (idx < n)
    {
        ft[idx] = max(ft[idx], val);
        idx += lsb(idx);
    }
}

pessoa p[MAXN], tmp[MAXN];

int main()
{_  
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].b >> p[i].d >> p[i].v;
        tmp[i] = p[i];
    }

    sort(tmp, tmp+n, cmp2);
    sort(p, p+n, cmp);

    for (int i = 0; i < n; i++)
    {
        int ans = 0;
        while (tmp[i].d == tmp[i + 1].d && tmp[i].b == tmp[i + 1].b)
        {
            ans += tmp[i].d;
            mapa2[tmp[i].b] = max(mapa2[tmp[i].b], tmp[i].d);
            mapa[tmp[i].d] = i + 1;
            i++;
        }
        mapa2[tmp[i].b] = max(mapa2[tmp[i].b], tmp[i].d);
        mapa[tmp[i].d] = i + 1;
    }

    for (int i = 0; i < n; i++)
    {
        update(mapa[p[i].d], query(mapa[p[i].d]) + p[i].v);
        ans = max(ans, query(mapa[p[i].d] - 1));
    }

    cout << ans << endl;
}