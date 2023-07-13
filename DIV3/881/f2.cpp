#include <iostream>
#include <vector>
//#include <bits/stdc++.h>
#define MAXN (int) (2e5 + 10)
#define int long long

using namespace std;

int t, n, h[MAXN], pai[MAXN], prof[MAXN], trecho[MAXN];
vector<int> grafo[MAXN];
char op;

int dfs(int u, int p)
{	
	pai[u] = p, h[u] = h[p];
	for (int &v : grafo[u])
	{
		if (v == p) continue;
		dfs(v, u);
		if (prof[])
	}
}

int query_seg(int t, int idx, int i, int j, int l, int r)
{

}

int query(int a, int b)
{

}













int32_t main()
{
	cin >> t;
	while (t--)
	{
		cin >> k;
		n = 1;
		maior[1][0] = maior[1][1] = menor[1][1] = 1, menor[1][0] = 0;
		while (k--)
		{
			cin >> op >> a >> b;
			if (op == '+')
			{
				n++;
				maior[n][1] = max(0LL, maior[a][1]) + b;
				maior[n][0] = max(maior[a][0], maior[n][1]);
				menor[n][1] = min(0LL, menor[a][1]) + b;
				menor[n][0] = min(menor[a][0], menor[n][1]);
			}

			else
			{
				cin >> a;
				cout << ((a >= menor[b][0] && a <= maior[b][0]) ? "YES" : "NO") << endl;
			}
		}


	}
}