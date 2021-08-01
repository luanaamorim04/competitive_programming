#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring>
#include <set>
#include <stack>
#include <bitset>
#define ll long long
#define INF (1e17)
#define MAX (int) (2e5 + 5)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define sz(x) (int) ((x).size())
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define lsb(x) (x & -x)
#define W(x) cout << #x << ": " << x << endl
#define Wii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll n, memo[1009][20009];

struct caixa
{
    int p, r;
    ll v;
};
caixa arr[1009];

int cmp(caixa a, caixa b)
{
    return a.r > b.r;
}

ll f(int i, int res)
{
    if (res < 0) return -INF;
    if (i == n) return 0;
    if (~memo[i][res]) return memo[i][res];
    return memo[i][res] = max(f(i+1, res), f(i+1, min(res, arr[i].r) - arr[i].p) + arr[i].v);
}

int main()
{_
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].p >> arr[i].r >> arr[i].v;
        arr[i].r += arr[i].p;
    }

    sort(arr, arr+n, cmp);
    memset(memo, -1, sizeof memo);
    cout << f(0, 20000) << endl;
}















