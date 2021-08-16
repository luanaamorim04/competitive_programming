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

int n, idx;
string a, b, o, d, c;
priority_queue<tuple<int, int, char> , vector<tuple<int, int, char> >, greater<tuple<int, int, char> > > fila;
int dist[7000][255], resp;

int main()
{_
	while (cin >> n && n)
	{
		idx = 0;
		resp = INF;
		map<string, int> id;
		vector<tuple<int, int, char> > grafo[MAX];

		cin >> o >> d;
		id[o] = ++idx; id[d] = ++idx;
		for (int i = 1; i <= n; i++)
		{
			cin >> a >> b >> c;
			if (id.find(a) == id.end()) id[a] = ++idx;
			if (id.find(b) == id.end()) id[b] = ++idx;
			grafo[id[a]].push_back({id[b], c.size(), c[0]});
			grafo[id[b]].push_back({id[a], c.size(), c[0]});
		}

		for (int i = 1; i <= idx; i++)
			for (int j = 'a'; j <= 'z'; j++)
				dist[i][j] = INF;

		dist[1]['0'] = 0;
		fila.push({0, 1, '0'});
		while (!fila.empty())
		{
			auto[d, u, k] = fila.top(); fila.pop();
			if (d > dist[u][k]) continue;
			for (auto[v, w, c] : grafo[u])
			{
				if (c == k) continue;
				if (dist[v][c] > dist[u][k] + w)
				{
					dist[v][c] = dist[u][k] + w;
					fila.push({dist[v][c], v, c});
				}
			}
		}

		for (int i = 'a'; i <= 'z'; i++)
			resp = min(resp, dist[2][i]);

		cout << (resp==INF? "impossivel" : to_string(resp)) << endl;   
	}
}

















