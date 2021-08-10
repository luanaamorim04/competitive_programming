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

int n, m, a, b, c, s, d;
ll dist[MAX], dist2[MAX], dist3[MAX];
vector<par> grafo[MAX];
vector<int> last[MAX];
priority_queue<par, vector<par>, greater<par> > fila;
map<par, ll> prob;

void f(int u)
{
	if (u == s) return;
	for (int v : last[u]) 
	{
		prob[{v, u}] = 1;
		f(v);
	}
}

int main()
{_
	while (cin >> n >> m && n)
	{
		for (int i = 0; i < n; i++)
		{
			last[i].clear();
			grafo[i].clear();
			dist[i] = dist2[i] = dist3[i] = INF;
		}
		prob.clear();
		
		cin >> s >> d;
		while (m--)
		{
			cin >> a >> b >> c;
			grafo[a].push_back({b, c});
		}

		dist[s] = dist2[s] = dist3[s] = 0;
		fila.push({0, s});
		while (!fila.empty())
		{
			auto[d, u] = fila.top(); fila.pop();
			if (d != dist[u]) continue;
			for (auto[v, w] : grafo[u])
			{
				if (dist[v] > dist[u] + w)
				{
					dist[v] = dist[u] + w;
					fila.push({dist[v], v});
				}
			}
		}

		fila.push({0, s});
		while (!fila.empty())
		{
			auto[d, u] = fila.top(); fila.pop();
			if (d != dist2[u]) continue;
			for (auto[v, w] : grafo[u])
			{
				if (dist2[v] > dist2[u] + w)
				{
					dist2[v] = dist2[u] + w;
					fila.push({dist2[v], v});
				}

				if (dist2[u] + w == dist[v])
					last[v].push_back(u);
			}
		}

		f(d);
		fila.push({0, s});
		while (!fila.empty())
		{
			auto[d, u] = fila.top(); fila.pop();
			if (d != dist3[u]) continue;
			for (auto[v, w] : grafo[u])
			{
				if (prob[{u, v}]) continue;
				if (dist3[v] > dist3[u] + w)
				{
					dist3[v] = dist3[u] + w;
					fila.push({dist3[v], v});
				}
			}
		}

		cout << (dist3[d] != INF ? dist3[d] : -1) << endl;
	}	
}









