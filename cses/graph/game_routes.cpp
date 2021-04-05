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
#define ll long long
#define INF (1e9)
#define MAX (2e5)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector<int> grafo[1<<20];
int n, m, a, b;
ll memo[1<<20];

ll f(int u)
{
	if (u == n) return 1;
	if (~memo[u]) return memo[u];
	int ans = 0;
	for (int i = 0; i < grafo[u].size(); i++)
	{
		ans = ((ans + f(grafo[u][i])) % MOD); 
	}
	return memo[u] = ans;
}

int main()
{_
	cin >> n >> m;
	while (m--)
	{
		cin >> a >> b;
		grafo[a].push_back(b);
	}

	memset(memo, -1, sizeof(memo));
	cout << f(1) << endl;
}
