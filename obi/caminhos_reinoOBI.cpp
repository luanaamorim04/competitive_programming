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

int n, a, b, q, d, tam, pai[MAX], pos[MAX], ini[MAX], dist[MAX], grau[MAX];

void dfs(int u)
{
	grau[pai[u]]--, dist[u] = 1, ini[u] = pai[u];
	if (!grau[pai[u]])
	{
		dfs(pai[u]);
		dist[u] = 1 + dist[pai[u]];
		ini[u] = ini[pai[u]];
	}
	else d = pai[u];
}

void pre()
{
	for (int i = 1; i <= n; i++)
		if (!grau[i]) dfs(i);

	int idx = 1, x = pai[d];
	pos[d] = idx, ini[d] = d;
	while (x != d)
	{
		ini[x] = x;
		pos[x] = ++idx;
		x = pai[x];
	}
	tam=idx;
}

int solve(int a, int b)
{
	if (ini[a]==ini[b]) return abs(dist[a]-dist[b]);
	
	if (dist[a] > dist[b]) swap(a, b);
	int resp = dist[b], tempo = dist[b]-dist[a];
	a = ini[a], b = ini[b];

	if (pos[a] < pos[b])
		resp += min(tam-(pos[b]-pos[a]), max((pos[b]-pos[a])-tempo, 0));
	else
		resp += min(pos[a]-pos[b], max(tam-(pos[a]-pos[b])-tempo, 0));

	return resp;
}

int main()
{_
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> pai[i];
		grau[pai[i]]++;
	}

	pre();
	cin >> q;
	while (q--)
	{
		cin >> a >> b;
		cout << solve(a, b) << endl;
	}
}








