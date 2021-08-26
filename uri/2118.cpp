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

int n, k, m, q, vis[MAX], a, b, c;
tuple<int, int, int> arr[MAX];
queue<int> fila;
vector<int> grafo[MAX];

int main()
{_
	cin >> n >> k >> q >> m;
	for (int i = 1; i <= k; i++)
	{
		cin >> a >> b >> c;
		arr[a] = max(arr[a], make_tuple(b, c, i));
		fila.push(a);
		vis[a] = 1;
	}

	while (m--)
	{
		cin >> a >> b;
		grafo[a].push_back(b);
		grafo[b].push_back(a);
	}

	while (!fila.empty())
	{
		int u = fila.front(); fila.pop();
		for (int v : grafo[u])
		{
			if (!vis[v])
			{
				fila.push(v);
				vis[v] = vis[u]+1;
				arr[v] = arr[u];
			}
			else if (vis[v] == vis[u]+1)
			{
				arr[v] = max(arr[v], arr[u]);
			}
		}
	}

	while (q--)
	{
		cin >> a;
		if (!vis[a]) cout << "Noic" << endl;
		else cout << get<2>(arr[a]) << endl;
	}
}



















