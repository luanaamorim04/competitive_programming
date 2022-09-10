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
#define INF (1e16)
#define MAX (int) (2e3 + 5)
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

ll dp[MAX][MAX], n, p, q, arr[MAX], nxtP[MAX], nxtQ[MAX];

int check(ll w)
{
	p = min(n, p);
	arr[n+1] = (ll)INF<<2;

	for (int i = 1; i <= n; i++)
	{
		nxtP[i] = nxtQ[i] = i;
		while (arr[i] + w > arr[++nxtP[i]]);

		while (arr[i] + (w<<1) > arr[++nxtQ[i]]);

		for (int j = 0; j <= n; j++) dp[i][j] = INF;
	}

	for (int j = 1; j <= n; j++) dp[n+1][j] = INF;
	
	for (int i = n; i >= 1; i--)
	{
		dp[i][0] = dp[nxtQ[i]][0] + 1;
		for (int j = 1; j <= p; j++) {
			dp[i][j] = min(dp[nxtP[i]][j-1], dp[nxtQ[i]][j] + 1);
		}

	}

	for (int i = 0; i <= p; i++)
		if (dp[1][i] <= q) return 1;
	return 0;
}

int main()
{_
	cin >> n >> p >> q;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	sort(arr, arr+n+1);

	ll ini = 1, meio, fim = (ll)INF, best = -1;
	while (ini <= fim)
	{
		meio = (ini+fim)>>1;
		if (check(meio)) best = meio, fim = meio - 1;
		else ini = meio + 1;
	}

	cout << best << endl;
}











