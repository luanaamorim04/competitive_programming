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
#define INF (1LL<<62)
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

ll n, m, q, a, b, c, dist[1010][1010], t;

int main()
{_
	while (cin >> n >> m && n)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = (i==j?0:INF);

		while (m--)
		{
			cin >> a >> b >> c;
			if (dist[a][b] == INF) dist[a][b] = c;
			if (dist[b][a] == INF) dist[b][a] = c;
			dist[a][b] = max(dist[a][b], c);
			dist[b][a] = max(dist[b][a], c);
		}

		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
				{
					if (i==j || i==k || j==k) continue;
					dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]));
				}

		cout << "Instancia " << ++t << endl;
		cin >> q;
		while (q--)
		{
			cin >> a >> b;
			if (a!=b) cout << dist[a][b] << endl;
			else cout << 0 << endl;
		}
		cout << endl;
	}
}	







