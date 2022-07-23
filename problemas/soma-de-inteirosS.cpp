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
#define dbug(x) cout << (#x) << " -> " << x << endl
#define ll long long
#define INF (1LL<<40)
#define MAX (int) (5e5 + 5)
#define MOD 1000000007
#define par pair<ll, ll>
#define all(v) v.begin(), v.end()
#define sz(x) (int) ((x).size())
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define lsb(x) (x & -x)
#define W(x) cout << #x << ": " << x << endl
#define Wii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


using namespace std;

ll n, k, arr[MAX], vis[MAX][2];
par dp[MAX][2];

// par opt(int idx, int flag, ll c)
// {
//     if (idx > n) return {0, 0};
//     if (vis[idx][flag]) return dp[idx][flag];
//     vis[idx][flag] = 1;
//     par a = opt(idx+1, 1, c);
//     par b = opt(idx+1, 0, c);
//     if (!flag) return dp[idx][flag] = max(b, {a.first + arr[idx] - c, a.second - 1});
//     return dp[idx][flag] = max(b, {a.first + arr[idx], a.second});
// }

par bottom_up(ll c)
{
	dp[n+1][0] = dp[n+1][1] = {0, 0};
	for (int idx = n; idx >= 0; idx--)
	{
		par a = dp[idx+1][1];
	    par b = dp[idx+1][0];
	    dp[idx][0] = max(b, {a.first + arr[idx] - c, a.second - 1});
	    dp[idx][1] = max(b, {a.first + arr[idx], a.second});
	}

	return dp[0][0];
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    
    ll ini = 0, meio, fim = INF;
    while (ini <= fim)
    {
        meio = (ini+fim)>>1;
        // for (int i = 0; i <= n+1; i++) 
        //     vis[i][0] = vis[i][1] = 0;
        if (-bottom_up(meio).second <= k) fim = meio - 1;
        else ini = meio + 1;
    }

    // for (int i = 0; i <= n+1; i++) 
    //     vis[i][0] = vis[i][1] = 0;
    par resp = bottom_up(fim+1);
    cout << resp.first + (k*(fim+1)) << endl;
}



