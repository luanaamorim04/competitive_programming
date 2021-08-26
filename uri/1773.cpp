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
#define MAX (int) (2e3 + 5)
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

int n, m, a, b, arr[MAX], vis[MAX], resp, arr2[MAX], vis2[MAX];
queue<int> fila;

int main()
{_
	while (cin >> n >> m)
	{
		memset(vis, 0, sizeof vis);
		memset(vis2, 0, sizeof vis2);
		vector<int> grafo[MAX], arr2[MAX];
		resp = 0;

		while (m--)
		{
			cin >> a >> b;
			grafo[a].push_back(b);
			grafo[b].push_back(a);
		}

		for (int i = 2; i <= n; i++)
		{
			cin >> arr[i];
			arr2[arr[i]].push_back(i);
		}

		fila.push(1);
		vis[1] = 1;
		while (!fila.empty())
		{
			int u = fila.front(); fila.pop();
			resp++;
			for (int v : arr2[u]) 
			{
				if (!vis2[v] || vis[v]) continue;
				vis[v] = 1;
				fila.push(v);
			}

			for (int v : grafo[u])
			{
				if (vis[v]) continue;
				if (vis[arr[v]])
				{
					vis[v] = 1;
					fila.push(v);
				}
				else
				{
					vis2[v] = 1;
				}
			}
		}

		cout << (resp==n?"sim":"nao") << endl;
	}
}













