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
#define dbug(x) cout << (#x) << " -> " << x << endl
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

int n, m, k, a, b, resp, vis[MAX];
vector<int> grafo[MAX], comps;

int main()
{_
	cin >> n >> m >> k;
	while (m--)
	{
		cin >> a >> b;
		grafo[a].push_back(b);
		grafo[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			int qtd = 0;
			queue<int> fila;
			fila.push(i);
			while (!fila.empty())
			{
				int u = fila.front(); fila.pop();
				if (vis[u]) continue;
				qtd++;
				vis[u] = 1;
				for (int v : grafo[u])
					if (!vis[v]) fila.push(v);
			}
			comps.push_back(qtd);
		}
	}

	sort(all(comps), greater<int>());
	for (int i = 0; i <= min(k, sz(comps)-1); i++)
		resp += comps[i];

	cout << resp << endl;
}














