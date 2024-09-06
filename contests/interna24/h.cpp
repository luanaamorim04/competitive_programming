#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
//#include <bits/stdc++.h>
#define MAXN (int) (2e5 + 10)
#define int long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define MOD (int) (1e9 + 7)
#define INF (int) (1e9 + 10)
#define all(x) x.begin(), x.end()
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)

using namespace std;

int k, n, m, t, arr[MAXN];

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> n;
		map<int, int> mapa;
		map<ii, ii> pai;
		map<ii, int> vis;
		queue<iii> fila;

		int idx = 0;
		for (int i = 1; i <= n; i++) 
		{
			cin >> arr[i];
			fila.push({arr[i], 0, 0});
			pai[{arr[i], 0}] = {0, -1};
			mapa[arr[i]] = 1;
		}

		while (!fila.empty())
		{
			auto[pos, pot, q] = fila.front(); fila.pop();
			if (pos < -2e18 || pos > 2e18) continue;
			if (mapa.find(pos) != mapa.end()) 
			{
				q++;
				if (q == n)
				{
					ii curr = {pos, pot};
					vector<int> resp;
					while (curr.second != -1)
					{
						resp.push_back(curr.first);
						curr = pai[{curr.first, curr.second}];
					}

					cout << resp.size() << endl;					
					for (int i = resp.size() - 1; i >= 0; i--)
					{
						cout << resp[i];
						if (i != 0) cout << ' ';
					}
					cout << endl;

					break;
				}
			}

			if (!vis[{pos + (1LL<<pot), pot + 1}])
			{
				fila.push({pos + (1LL<<pot), pot + 1, q});
				pai[{pos + (1LL<<pot), pot + 1}] = {pos, pot};
				vis[{pos + (1LL<<pot), pot + 1}] = 1;
			}
			if (!vis[{pos - (1LL<<pot), pot + 1}])
			{
				fila.push({pos - (1LL<<pot), pot + 1, q});
				pai[{pos - (1LL<<pot), pot + 1}] = {pos, pot};
				vis[{pos - (1LL<<pot), pot + 1}] = 1;
			}
		}
	}

}

