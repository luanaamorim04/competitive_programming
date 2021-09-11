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
#define MAX (int) (2e4 + 5)
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
#define tp tuple<int, int, int>

using namespace std;

int n, m, q, a, b, c, k, d, f, g;
vector<par> grafo[MAX];
priority_queue<tp, vector<tp>, greater<tp> > fila;
int dist[MAX][102], menor;
map<par, int> mapa;
string s;

void dijkstra()
{
	for (int i = 1; i <= n; i++) 
		for (int j = 0; j <= 100; j++)
			dist[i][j] = INF;

	fila.push({0, f, 0});
	dist[f][0] = 0;
	while (!fila.empty())
	{	
		auto[d, u, k] = fila.top(); fila.pop();
		if (dist[u][k] != d) continue;
		for (auto[v, w] : grafo[u])
		{
			int x = min(100, k+(mapa.find({u, v}) == mapa.end()));
			if (dist[v][x] > d + w)
			{
				dist[v][x] = d + w;
				fila.push({dist[v][x], v, x});
			}
		}
	}
}

int main()
{_
	cin >> n >> m >> q;
	cin >> f >> g;
	getline(cin, s);
	getline(cin, s);
	int now = 0, last = 0, b = 1;
	for (int i = sz(s) - 1; i >= -1; i--)
	{
		if (s[i] == ' ' || i == -1)
		{
			mapa[{now, last}] = 0;
			last = now;
			now = 0;
			b = 1;
		}
		else
		{
			now = (now + ((s[i]-'0')*b));
			b *= 10;
		}
	}
	
	while (m--)
	{
		cin >> a >> b >> c;
		if (mapa.find({a, b}) != mapa.end()) mapa[{a, b}] = c;
		grafo[a].push_back({b, c});
	}

	for (auto it : mapa) menor += (it.second);

	dijkstra();
	while (q--)
	{
		cin >> k >> d;
		int ok = 0;
		for (int i = k; i <= 100; i++)
			ok |= ((dist[g][i]-menor) <= d);
		cout << (ok ? "SIM":"NAO") << endl;
	}
}
