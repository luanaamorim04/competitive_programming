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
#define INF (ll) (1e15)
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

ll t, n, a, b, w, resp;
vector<pair<int, ll> > grafo[MAX];

ll dfs(int u, int p = 0)
{
	ll resp = 0;
	for (auto[v, w] : grafo[u])
	{
		if (v==p) continue;
		resp += dfs(v, u) + 2*w;
	}

	return resp;
}	

ll prof(int u, int p = 0)
{
	ll resp = 0;
	for (auto[v, w] : grafo[u])
	{
		if (v==p) continue;
		resp = max(resp, prof(v, u) + w);
	}

	return resp;
}

int main()
{_
	cin >> t;
	for (int k = 1; k <= t; k++)
	{
		resp = INF;
		cin >> n;
		for (int i = 1; i < n; i++)
		{
			cin >> a >> b >> w;
			grafo[a].push_back({b, w});
			grafo[b].push_back({a, w});
		}

		for (int i = 1; i <= n; i++)
			resp = min(resp, dfs(i) - prof(i));

		for (int i = 1; i <= n; i++)
			grafo[i].clear();
		cout << "Case #" << k << ": " << resp << endl;
	}
}









