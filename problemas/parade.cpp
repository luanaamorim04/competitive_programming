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

int h[MAX], d[MAX], g[MAX], a, b, n;
vector<int> grafo[MAX];

int f(int u, int p = 0)
{
	int a = 0, b = 0;
	for (int v : grafo[u])
	{
		if (v==p) continue;
		f(v, u);
		h[u] = max(h[u], h[v] + g[u] - 2);
		d[u] = max(d[u], d[v]);
		if (a > b) swap(a, b);
		a = max(a, h[v]);
	}

	d[u] = max(d[u], h[u]);
	d[u] = max(d[u], a+b+g[u]-4);
	h[u] = max(h[u], g[u]);

	return d[u];
}

int main()
{_
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		cin >> a >> b;
		grafo[a].push_back(b);
		grafo[b].push_back(a);
		g[a]++, g[b]++;
	}

	cout << f(1) << endl;	
}	




















