#include <bits/stdc++.h>
//#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define MAXN (int) (2e5 + 10)
#define all(x) x.begin(), x.end()
#define int long long
#define iii tuple<int, int, int>
#define iiiii tuple<int, int, int, int, int>
#define dbug(x) cout << #x << ": " << x << endl

using namespace std;

int t, n, m, pai[MAXN], a, b, e, q, h[MAXN], resp[MAXN];

int find(int x)
{
	if (x == pai[x]) return x;
	return pai[x] = find(pai[x]);
}

void join(int a, int b)
{
	pai[find(a)] = find(b);
}

void solve(int n, int m)
{
	priority_queue<iii, vector<iii>, greater<iii> > arr;
	vector<iiiii> qry;
	for (int i = 1; i <= n; i++)
	{
		cin >> h[i];
		pai[i] = i;
	}

	while (m--)
	{
		cin >> a >> b;
		arr.push({max(h[a], h[b]), a, b});
	}

	cin >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> a >> b >> e;
		qry.push_back({h[a]+e, a, b, e, i});
	}

	sort(all(qry));

	for (auto[soma, a, b, e, idx] : qry)
	{
		while (!arr.empty())
		{
			auto[maior, u, v] = arr.top(); 
			if (maior > soma) break;
			arr.pop();
			if (find(u) != find(v)) join(u, v);
		}	

		resp[idx] = (find(a) == find(b));
	}
	
	for (int i = 0; i < q; i++)
		cout << (resp[i] ? "YES" : "NO") << endl;
}

int32_t main()
{
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		solve(n, m);
	}
}