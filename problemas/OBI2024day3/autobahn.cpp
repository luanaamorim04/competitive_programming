#include <iostream>
#include <bits/stdc++.h>
#include <vector> 
#include <queue>
#define all(x) x.begin(), x.end()
#define MAXN (int) (2e5 + 10)
#define INF (int) (2e9 + 10)
#define int long long
#define ii pair<int, int> 

using namespace std;

struct tree
{
	int esq, dir, val;
};

int n, k, x;
vector<ii> paga, tot, lazy, inter;
vector<tree> st;
priority_queue<int, vector<int>, greater<int> > pq;

int novo()
{
	st.push_back({-1, -1, 0});
	lazy.push_back({1, 0});
	return st.size() - 1;
}

void push(int idx, int i, int j)
{
	if (lazy[idx].first == 1 && lazy[idx].second == 0) return;
	auto[a, b] = lazy[idx];
	st[idx].val = a*st[idx].val + b*(j-i+1);
	if (i != j)
	{
		if (st[idx].esq == -1) st[idx].esq = novo();
		if (st[idx].dir == -1) st[idx].dir = novo();

		lazy[st[idx].esq] = {a*lazy[st[idx].esq].first, a*lazy[st[idx].esq].second + b};
		lazy[st[idx].dir] = {a*lazy[st[idx].dir].first, a*lazy[st[idx].dir].second + b};
	}

	lazy[idx] = {1, 0};
}

int query(int idx, int i, int j, int l, int r)
{
	push(idx, i, j);
	if (j < l || i > r) return 0;
	if (j <= r && i >= l) 
	{
		return st[idx].val;
	}
	if (st[idx].esq == -1) st[idx].esq = novo();
	if (st[idx].dir == -1) st[idx].dir = novo();

	int mid = (i+j)>>1;
	int x = query(st[idx].esq, i, mid, l, r);
	int y = query(st[idx].dir, mid+1, j, l, r);
	return x+y;
}

void update(int idx, int i, int j, int l, int r, int op)
{
	push(idx, i, j);
	if (j < l || i > r) return;
	if (j <= r && i >= l)
	{
		if (op) lazy[idx] = {1, 1};
		else lazy[idx] = {0, 0};
		push(idx, i, j);
		return;
	}
	if (st[idx].esq == -1) st[idx].esq = novo();
	if (st[idx].dir == -1) st[idx].dir = novo();

	int mid = (i+j)>>1;
	update(st[idx].esq, i, mid, l, r, op);
	update(st[idx].dir, mid+1, j, l, r, op);
	st[idx].val = st[st[idx].esq].val + st[st[idx].dir].val;
}

int32_t main()
{
	cin >> n >> k >> x;
	novo();
	for (int i = 0; i < n; i++)
	{
		int x, y, z;
		cin >> x >> z >> y;
		tot.push_back({x, y});
		int l = (x + z);
		int r = y;

		if (l > r) continue;
		paga.push_back({l, r});
		update(0, -INF, INF, l, r, 1);
	}

	sort(all(tot));
	int pessoas = 0, last = 0;
	for (auto[ini, fim] : tot)
	{
		++pessoas;
		pq.push(fim);
		while (!pq.empty() && pq.top() < ini) 
		{
			int curr = pq.top(); pq.pop();
		    --pessoas;
			if (pessoas == k) 
			{
				inter.push_back({last, curr});
			}
		}

		if (pessoas == k) last = ini;
	}

	while (!pq.empty())
	{
		int curr = pq.top(); pq.pop();
		--pessoas;
		if (pessoas == k-1) 
		{
			inter.push_back({last, curr});
		}
	}

	sort(all(inter));
	int idx = 0;
	for (auto[l, r] : inter)
	{
		update(0, -INF, INF, idx, l-1, 0);
		idx = r+1;
	}
	update(0, -INF, INF, idx, INF, 0);

	int resp = 0;

	for (auto[ini, fim] : paga)
	{
		resp = max({resp, query(0, -INF, INF, ini, ini+x-1), query(0, -INF, INF, fim-x+1, fim)});
	}

	cout << resp << endl;
}
