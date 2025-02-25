#include <iostream>
#include <vector>
//#include <bits/stdc++.h>
#define MAXN (int) (2e3 + 10)

using namespace std;

int t, n, arr[MAXN], freq[MAXN], pai[MAXN], vis[MAXN];

int find(int x)
{
	if (x == pai[x]) return x;
	return pai[x] = find(pai[x]);
}

void join(int a, int b)
{
	pai[find(a)] = pai[find(b)];
}

int32_t main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		vector<pair<int, int> > resp;
		for (int i = 1; i <= n; i++)
		{	
			cin >> arr[i];
			pai[i] = i;
		}

		cout << "YES" << endl;
		for (int op = n-1; op >= 1; op--)
		{
			int r = -2;
			for (int i = 1; i <= n; i++)
			{
				int curr = find(i);
				if (vis[curr]) continue;
				vis[curr] = 1;
				freq[arr[curr]%op]++;
				if (freq[arr[curr]%op] >= 2) r = arr[curr]%op;
			}
			vector<int> par;
			for (int i = 1; i <= n; i++)
			{
				int curr = find(i);
				if (!vis[curr]) continue;
				vis[curr] = 0;
				freq[arr[curr]%op] = 0;
				if (arr[curr]%op == r) par.push_back(curr);
			}

			resp.push_back({par[0], par[1]});
			join(par[0], par[1]);
		}

		reverse(resp.begin(), resp.end());
		for (auto[a, b] : resp)
			cout << a << ' ' << b << endl;
	}
}
