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
#define MAXL 20

using namespace std;

int n, m, q, a, op, t, b, c, arr[MAX], resp[MAX], tin[MAX], tout[MAX], up[MAX][MAXL];
vector<int> grafo[MAX];
set<int> freq[MAX], alone[MAX];

void dfs(int u, int p)
{
	tin[u] = ++t;
	up[u][0] = p;
	for (int i = 1; i < MAXL; i++)
		up[u][i] = up[up[u][i-1]][i-1];
	for (int v : grafo[u])
		if (v != p) dfs(v, u);
	tout[u] = ++t;
}

int is_anc(int u, int v)
{
	return (tin[u] <= tin[v] && tout[v] <= tout[u]);
}

int LCA(int u, int v)
{
	if (is_anc(u, v)) return u;
	if (is_anc(v, u)) return v;
	for (int i = MAXL-1; i >= 0; i--)
		if (!is_anc(up[u][i], v)) u = up[u][i];
	
	return up[u][0];
}

int main()
{_
	cin >> n >> m >> q;
	for (int i = 1; i < n; i++)
	{
		cin >> a >> b;
		grafo[a].push_back(b);
		grafo[b].push_back(a);
	}

	dfs(1, 1);
	for (int i = 1; i <= m; i++)
	{
		cin >> arr[i];
		alone[arr[i]].insert(i);
		resp[i] = LCA(arr[i], arr[i-1]);
		if (i>1) freq[resp[i]].insert(i);
	}

	while (q--)
	{
		cin >> op >> a >> b;
		if (op&1) 
		{
			int idx = a;
			alone[arr[idx]].erase(idx);
			freq[resp[idx]].erase(idx);
			freq[resp[idx+1]].erase(idx+1);
			arr[idx] = b;
			arr[0] = arr[1];
			alone[arr[idx]].insert(idx);
			resp[idx] = LCA(arr[idx], arr[idx-1]);
			resp[idx+1] = LCA(arr[idx+1], arr[idx]);
			freq[resp[idx]].insert(idx);
			freq[resp[idx+1]].insert(idx+1);

		}
		else 
		{
			cin >> c;
			auto idx = alone[c].lower_bound(a);
			if (idx != alone[c].end() && *idx <= b) 
			{
				cout << (*idx) << ' ' << (*idx) << endl;
				continue;
			}

			idx = freq[c].upper_bound(a);
			if (idx == freq[c].end() || *idx > b) 
			{
				cout << -1 << ' ' << -1 << endl;
				continue;
			}

			cout << (*idx)-1 << ' ' << (*idx) << endl;
		}
	}
}



















