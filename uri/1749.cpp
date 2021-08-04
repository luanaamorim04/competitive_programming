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

ll n, a[MAX], b[MAX];
int cor[MAX], vis[MAX], c[2];
map<par, int> mapa;
vector<int> grafo[MAX];
queue<int> fila;

int bfs(int i)
{	
	fila.push(i);
	cor[i] = vis[i] = 1;
	c[0] = 0, c[1] = 1;
	while (!fila.empty())
	{
		int u = fila.front(); fila.pop();
		for (int v : grafo[u])
		{
			//if (cor[u] == cor[v]) return -1;
			if (vis[v]) continue;
			cor[v] = cor[u]^1;
			c[cor[v]]++;
			vis[v] = 1;
			fila.push(v);
		}
	}

	return min(c[0], c[1]);
}

int main()
{_
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i] >> b[i];
		mapa[{a[i], b[i]}] = i;
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = -5; j <= 5; j++)
		{
			for (int k = -5; k <= 5; k++)
			{
				if (!j && !k) continue;
				if (mapa.find({a[i] + j, b[i] + k}) == mapa.end()) continue;
				if ((k*k) + (j*j) > 25) continue;	
				grafo[i].push_back(mapa[{a[i] + j, b[i] + k}]);
			}
		}
	}

	// for (int i = 1; i <= n; i++)
	// {
	// 	cout << i << ": ";
	// 	for (int x : grafo[i])
	// 		cout << x << ' ';
	// 	cout << endl;
	// }

	int resp = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			resp += bfs(i);
			//if (bfs(i) < 0) return 1;
		} 
	}
	
	cout << resp << endl;
}














