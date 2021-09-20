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
#define MAX (int) (3e5 + 5)
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

ll n, a, b, dp[MAX];
vector<int> grafo[MAX];

ll f(int u, int p, int k)
{
	dp[u] = 0;
	for (int v : grafo[u])
	{
		if (v==p) continue;
		dp[u] += (1+f(v, u, k));
	}

	return max(0LL, dp[u]-k);
}

int main()
{_
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		cin >> a >> b;
		grafo[a].push_back(b);
		grafo[b].push_back(a);
	}

	int ini = 0, meio, fim = n;
	while (ini <= fim)
	{
		meio = ini + ((fim-ini)>>1);
		if (f(1, 0, meio)) ini = meio + 1;
		else fim = meio - 1;
	}

	cout << fim + 1 << endl;
}












