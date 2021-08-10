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
#define INF (ll) (1e15)
#define MAX (int) (2e5 + 5)
#define MOD 1000000007
#define par pair<ll, ll>
#define all(v) v.begin(), v.end()
#define sz(x) (int) ((x).size())
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define lsb(x) (x & -x)
#define W(x) cout << #x << ": " << x << endl
#define Wii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, a, b, c, k;
multiset<ll> dist[MAX];
priority_queue<par, vector<par>, greater<par> > fila;
vector<par> grafo[MAX]; 

int main()
{_
	cin >> n >> m >> k;
	while (m--)
	{
		cin >> a >> b >> c;
		grafo[a].push_back({b, c});
	}

	for (int i = 1; i <= n; i++) dist[i].insert(INF);
	dist[1].insert(0);
	fila.push({0, 1});
	while (!fila.empty())
	{
		auto[d, u] = fila.top(); fila.pop();
		if (d > *dist[u].rbegin()) continue;
		for (auto[v, w] : grafo[u])
		{
			if (*dist[v].rbegin() >= d + w)
			{
				if (dist[v].size() >= k) 
					dist[v].erase(prev(dist[v].end()));
				
				dist[v].insert(d + w);
				fila.push({d + w, v});
			}
		}
	}

	for (auto it : dist[n])
		cout << it << ' ';
	cout << endl;
}	












