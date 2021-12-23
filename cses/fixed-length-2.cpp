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
#define INF (1e9)
#define MAXL 20;
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

int n, l, r, a, b, vis[MAX], sub[MAX];
vector<int> grafo[MAX];
ll f[MAX], ft[MAX];

//ft 
void updatef(int idx, ll val)
{
	while (idx < MAX)
	{
		ft[idx] += val;
		idx += lsb(idx);
	}
}

ll queryf(int idx)
{
	if (idx < 0) return 0;
	int ans = 1;
	while (idx > 0)
	{
		ans += ft[idx];
		idx -= lsb(idx);
	}
	return ans;
}

//problem
void update(int u, int p, int h)
{
	if (h > r || vis[u]) return;
	updatef(h, 1);
	for (int v : grafo[u])
		if (v!=p) update(v, u, h+1);
}

ll query(int u, int p, int h)
{
	if (h > r || vis[u]) return 0;
	ll resp = queryf(r-h) - queryf((l-h)-1);
	for (int v : grafo[u])
		if (v!=p) resp += query(v, u, h+1);
	return resp;
}

void ini(int u, int p, int h)
{
	if (h > r || vis[u]) return;
	updatef(h, -1);
	for (int v : grafo[u])
		if (v!=p) ini(v, u, h+1);
}

//centroid
int tam(int u, int p = 0)
{
	if (vis[u]) return 0;
	sub[u] = 1;
	for (int v : grafo[u])
		if (v!=p) sub[u] += tam(v, u);
	return sub[u];
}

int centroid(int u, int p, int t)
{
	for (int v : grafo[u])
		if (!vis[v] && v!=p && sub[v]>(t>>1)) return centroid(v, u, t);
	return u;
}

ll solve(int u)
{
	tam(u);
	ll resp = 0;
	int c = centroid(u, 0, sub[u]);
	vis[c] = 1;
	for (int v : grafo[c])
	{
		resp += query(v, 0, 1);
		update(v, 0, 1);
	}

	for (int v : grafo[c])
		ini(v, 0, 1);

	for (int v : grafo[c])
		if (!vis[v]) resp += solve(v);

	return resp;
}


int main()
{_
	cin >> n >> l >> r;
	for (int i = 1; i < n; i++)
	{
		cin >> a >> b;
		grafo[a].push_back(b);
		grafo[b].push_back(a);
	}

	cout << solve(1) << endl;
}













