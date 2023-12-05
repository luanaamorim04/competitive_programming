#include <iostream>
#include <set>
#define MAXN (int)(1e5 + 10)
#define INF (int) (1e9 + 20)
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define ii pair<int, int>

using namespace std;

int n, m, op, i, h, l, r, p;
ii st[MAXN<<2];

void update(int idx, int i, int j, int pos, int val)
{
	if (i == j)
	{
		st[idx] = {val, pos};
		return;
	}
	int mid = (i+j)>>1;
	if (pos <= mid) update(esq(idx), i, mid, pos, val);
	else update(dir(idx), mid+1, j, pos, val);
	st[idx] = min(st[esq(idx)], st[dir(idx)]);
}

ii query(int idx, int i, int j, int l, int r)
{
	if (i > r || j < l) return {INF, INF};
	if (i >= l && j <= r) return st[idx];
	int mid = (i+j)>>1;
	ii x = query(esq(idx), i, mid, l, r);
	ii y = query(dir(idx), mid+1, j, l, r);
	return min(x, y);
}

int main()
{
	cin >> n >> m;
	++n;
	for (int i = 0; i < MAXN*4; i++)
		st[i] = {INF, INF};
	while (m--)
	{
		cin >> op;
		if (op&1)
		{
			cin >> i >> h;
			update(1, 1, n, i+1, h);
		}
		else
		{
			cin >> l >> r >> p;
			++l, r;	
			ii resp = query(1, 1, n, l, r);
			int ans = 0;
			while (resp.first <= p)
			{
				++ans;
				update(1, 1, n, resp.second, INF);
				resp = query(1, 1, n, l, r);
			}

			cout << ans << endl;
		}

	}
}
