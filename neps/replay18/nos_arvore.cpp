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

int n, a, b, arr[MAX], m, memo[MAX][101];
vector<int> grafo[MAX];

int f(int u, int p, int qnt)
{
	if (~memo[u][qnt]) return memo[u][qnt];
	if (qnt==m) return 0;

	cout << u << ' ' << qnt << endl;
	int resp = 0;
	for (int v : grafo[u])
	{
		if (v==p) continue;
		resp = max(resp, resp + f(v, u, qnt+1));
	}

	resp = max(resp, arr[u]);
	return (memo[u][qnt] = resp);
}

int main()
{_
	cin >> n >> m;
	memset(memo, -1, sizeof memo);

	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	for (int i = 1; i < n; i++)
	{
		cin >> a >> b;
		grafo[a].push_back(b);
		grafo[b].push_back(a);
	}

	cout << f(1, 0, 0) << endl;
}














