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

ll n, m, arr[MAX], idx, resp, a, b, vis[MAX];
vector<ll> grafo[MAX], comp[MAX];
queue<int> fila;

int main()
{_	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	while (m--)
	{
		cin >> a >> b;
		grafo[a].push_back(b);
		grafo[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		if (vis[i]) continue;
		idx++;
		vis[i] = 1;
		fila.push(i);
		while (!fila.empty())
		{
			int u = fila.front(); fila.pop();
			comp[idx].push_back(arr[u]);
			for (int v : grafo[u])
			{
				if (vis[v]) continue;
				fila.push(v);
				vis[v] = 1;
			}
		}

		sort(all(comp[idx]));
		resp += comp[idx][0];
	}

	cout << resp << endl;
}













