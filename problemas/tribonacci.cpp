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
#define MAX 3
#define MOD 1000000009
#define par pair<int, int>
#define all(v) (v.begin(), v.end())
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll n;

struct matrix
{
    ll m[MAX][MAX];
};

matrix t, p, resp;

matrix mult(matrix a, matrix b)
{
    matrix r;
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
        {
            r.m[i][j] = 0;
            for (int k = 0; k < MAX; k++)
                r.m[i][j] += (a.m[i][k]*b.m[k][j]);
            r.m[i][j] %= MOD;
        }
    
    return r;
}

matrix fexpo(matrix b, ll e)
{
    matrix r;
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            r.m[i][j] = (i==j);

    while (e)
    {
        if (e&1) r = mult(r, b);
        b = mult(b, b);
        e>>=1;
    }
    return r;
}

int main()
{
    while (cin >> n && n)
    {
        t = {{{1, 1, 1}, {1, 0, 0}, {0, 1, 0}}};
        p = {{{1, 0, 0}, {0, 0, 0}, {MOD-1, 0, 0}}};
        resp = fexpo(t, n);
        resp = mult(resp, p);
        cout << resp.m[0][0] << endl;
    }
}
