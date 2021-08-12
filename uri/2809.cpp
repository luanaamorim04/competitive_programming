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
#include <sstream>
#include <bitset>
#define ll long long
#define INF (ll) (1e9)
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

struct vertice
{
	ll u, p, x;
	int operator>(vertice q) const{
		return p > q.p;
	}
};

priority_queue<vertice, vector<vertice>, greater<vertice> > fila;
vector<par> grafo[MAX];
ll dist[MAX][111];
int n, m, q, a, b, ini, fim, c, k, d;
string s;
map<par, int> mapa;

void f()
{
	cin >> n >> m >> q >> ini >> fim;
	getline(cin, s);
	getline(cin, s);
	stringstream ss(s);
	b = ini;
	while (ss>>a)
	{	
		mapa[{b, a}] = 1;
		b = a;
	}
	
	while (m--)
	{
		cin >> a >> b >> c;
		grafo[a].push_back({b, c});
	}
}

int main()
{_
	f();
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= 100; j++)
			dist[i][j] = INF;

	dist[ini][0] = 0;
	fila.push({ini, 0, 0});
	while (!fila.empty())
	{
		auto[u, p, x] = fila.top(); fila.pop();
		if (p != dist[u][x]) continue;
		for (auto[v, w] : grafo[u])
		{
			ll h = min(100LL, x + (mapa[{u, v}]^1));
			if (dist[v][h] > dist[u][x] + w)
			{
				dist[v][h] = dist[u][x] + w;
				fila.push({v, dist[v][h], h});
			}
		}
	}

	while (q--)
	{
		cin >> k >> d;
		ll resp = INF;
		for (int i = k; i <= 100; i++)
			resp = min(resp, dist[fim][i]);
		cout << (abs(resp-dist[fim][0]) <= d ? "SIM" : "NAO") << endl;
	}
}	











