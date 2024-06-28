#include <iostream>
//#include <bits/stdc++.h>
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

int query(int idx, int i, int j, int h)
{
	push(idx, i, j);
	cout << i << ' ' << j << endl;
	if (i == j) return i;
	if (st[idx].esq == -1) st[idx].esq = novo();
	if (st[idx].dir == -1) st[idx].dir = novo();

	int mid = (i+j)>>1;
	if (st[st[idx].esq].val >= h) return query(st[idx].esq, i, mid, h);
	return query(st[idx].dir, mid+1, j, h-st[st[idx].esq].val);
}

void update(int idx, int i, int j, int l, int r, int op)
{
	push(idx, i, j);
	if (j < l || i > r) return;
	if (j <= r && i >= l)
	{
		lazy[idx] = {1, op};
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

int h, l, r;
char c;
int32_t main()
{
	cin >> n;
	while (cin >> c && c != 'E')
	{
		if (c == 'Q')
		{
			cin >> h;
			cout << query(0, 0, n, h) << endl; 
		}
		else
		{
			cin >> l >> r >> h;
			update(0, 0, n, l, r, h);
		}
	}
}
