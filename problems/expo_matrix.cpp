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
#define MAX 2
#define MOD 1000000007
#define par pair<int, int>
#define all(v) (v.begin(), v.end())
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll a, b, n;

struct matrix
{
    ll m[MAX][MAX];
};

matrix resp, p;

matrix mult(matrix a, matrix b)
{
    matrix ans;
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
        {
            ans.m[i][j] = 0;
            for (int k = 0; k < MAX; k++)   
                ans.m[i][j] += (a.m[i][k]*b.m[k][j]);
            ans.m[i][j] %= MOD;
        }
    
    return ans;
}

matrix fexpo(matrix a, ll n)
{
    matrix ans;
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            ans.m[i][j] = (i==j);

    while (n)
    {
        if (n&1) ans = mult(ans, a);
        a = mult(a, a);
        n>>=1LL;
    }
    return ans;
}

int main()
{_
    cin >> a >> b >> n;
    a = (a + (2*MOD)) % MOD;
    b = (b + (2*MOD)) % MOD;
    if (n == 1)
    {
        cout << a << endl;
        return 0;
    }
    p.m[0][0] = 1, p.m[0][1] = MOD - 1, p.m[1][0] = 1, p.m[1][1] = 0;
    p = fexpo(p, n - 2);
    resp.m[0][0] = b, resp.m[1][0] = a, resp.m[0][1] = resp.m[1][1] = 0; 
    cout << ((b*p.m[0][0] + a*p.m[0][1]) % MOD) << endl;
}