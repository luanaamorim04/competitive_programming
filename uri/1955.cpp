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

int n, x, ok, cor[MAX], vis[MAX];
vector<int> grafo[MAX];
queue<int> fila;

int main()
{_
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> x;
			if (x) continue;
			grafo[i].push_back(j);
			grafo[j].push_back(i);
		}

	ok = 1;
	for (int i = 1; i <= n; i++)
	{
		if (vis[i]) continue;
		fila.push(i);
		vis[i] = 1;
		while (!fila.empty())
		{
			int u = fila.front(); fila.pop();
			for (int v : grafo[u])
			{
				if (vis[v]) ok &= (cor[u] != cor[v]);
				else
				{
					vis[v] = 1;
					fila.push(v);
					cor[v] = cor[u]^1;
				}
			}
		}
	}

	cout << (ok?"Bazinga!":"Fail!") << endl;
}











