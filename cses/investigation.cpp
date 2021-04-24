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
#include <bitset>
#define ll long long
#define INF (ll) (1LL<<60)
#define MAX (int) (3e5)
#define MOD 1000000007
#define par pair<ll, ll>
#define all(v) v.begin(), v.end()
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll dist[MAX], qnt[MAX], menor[MAX], maior[MAX], n, m, a, b, c;
vector<par> grafo[MAX];
priority_queue<par, vector<par>, greater<par> > pq;

void dijkstra()
{
	for (int i = 2; i <= n; i++)
		dist[i] = INF;

	pq.push({0, 1});
	qnt[1] = 1;
	while (!pq.empty())
	{
		ll u = pq.top().second, d = pq.top().first; pq.pop();
		if (d > dist[u]) continue;

		for (auto [v, w] : grafo[u])
		{
			if (dist[v] == dist[u] + w)
			{
				menor[v] = min(menor[v], menor[u] + 1);
				maior[v] = max(maior[v], maior[u] + 1);
				qnt[v] = (qnt[v] + qnt[u]) % MOD;
			}
			else if (dist[v] > dist[u] + w)
			{
				menor[v] = menor[u] + 1;
				maior[v] = maior[u] + 1;
				dist[v] = dist[u] + w;
				qnt[v] = qnt[u];
				pq.push({dist[v], v});
			}
		}
	}
}

int main()
{_	
	cin >> n >> m;
	while (m--)
	{
		cin >> a >> b >> c;
		grafo[a].push_back({b, c});
	}

	dijkstra();

	cout << dist[n] << ' ' << qnt[n] << ' ' << menor[n] << ' ' << maior[n] << endl;
}	













