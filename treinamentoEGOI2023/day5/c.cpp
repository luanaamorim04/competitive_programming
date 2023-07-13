#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#define int long long
#define all(x) x.begin(), x.end()
#define MAXN (int) (1e6 + 5)
#define INF 1e9 + 7
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define _ cin.tie(0)->sync_with_stdio(false);

using namespace std;

int n, k, arr[MAXN], resp, ini, st[MAXN<<2];
vector<tuple<int, int, int> > v;
map<int, int> mapa;
vector<int> ord;
priority_queue<int, vector<int>, greater<int> > pq;

int32_t main()
{_
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({a, b, i});
	}

	sort(all(v));
	for (auto[l, r, i] : v)
	{
		pq.push(r);
		while (pq.size() > k) pq.pop();
		// cout << pq.top() << endl;

		if (pq.size() == k && resp < pq.top() - l)
		{
			resp = pq.top() - l;
			ini = l;
		}
	}

	cout << resp << '\n';
	vector<int> vv;
	for (auto[l, r, idx] : v)
	{
		if (l <= ini && r >= ini+resp)
			if (vv.size() < k) vv.push_back(idx);
	}

	sort(all(vv));
	for (int x : vv)
		cout << x << ' ';

	cout << '\n';
}






