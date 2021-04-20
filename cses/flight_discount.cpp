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
#define INF (ll) (1e14)
#define MAX (2e5)
#define MOD 1000000007
#define par pair<ll, pair<int, int> >
#define all(v) v.begin(), v.end()
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, a, b, c, v, i;
ll dist[1<<20][2], w;
vector<pair<int, ll> > grafo[1<<20];
priority_queue<par, vector<par>, greater<par> > pq;

int main()
{_
	cin >> n >> m;
	while (m--)
	{
		cin >> a >> b >> c;
		grafo[a].push_back({b, c});
	}

	for (i = 2; i <= n; ++i)
		dist[i][0] = dist[i][1] = INF;

	pq.push({0, {1, 0}});
	while (!pq.empty())
	{
		ll d = pq.top().first, u = pq.top().second.first, 
		k = pq.top().second.second; pq.pop();
		if (dist[u][k] != d) continue;

		for (i = 0; i < grafo[u].size(); ++i)
		{
			v = grafo[u][i].first; w = grafo[u][i].second;
			if (!k && dist[v][1] > d + (w>>1LL))
			{
				dist[v][1] = d + (w>>1LL);
				pq.push({dist[v][1], {v, 1}});
			}
			if (dist[v][k] > d + w)
			{
				dist[v][k] = d + w;
				pq.push({dist[v][k], {v, k}});
			}
		}
	}

	cout << min(dist[n][0], dist[n][1]) << endl;
}























