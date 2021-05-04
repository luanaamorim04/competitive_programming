#include <iostream>
#define ll long long
#define INF (int) (1e9 + 10)
#define esq(x) (x<<1)
#define dir(x) ((x<<1)+1)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll arr[1<<20], n, q, a, b, t;

struct tree
{
	ll sum, sum_qnt, ans, ans_qnt, pref, pref_qnt, suf, suf_qnt;
};

tree st[1<<20];

tree combine(tree esq, tree dir)
{
	tree resp = {-INF, 1, -INF, 1, -INF, 1, -INF, 1};
	// ANS
	ll val1 = esq.ans, val2 = dir.ans, val3 = esq.suf + dir.pref;
	ll qnt1 = esq.ans_qnt, qnt2 = dir.ans_qnt, qnt3 = esq.suf_qnt + dir.pref_qnt;
	ll maxn = max(val1, max(val2, val3));
	resp.ans = maxn;
	
	if (val1 == maxn) resp.ans_qnt = qnt1;
	if (val2 == maxn) resp.ans_qnt = max(resp.ans_qnt, qnt2);
	if (val3 == maxn) resp.ans_qnt = max(resp.ans_qnt, qnt3);

	// SUM
	resp.sum = esq.sum + dir.sum;
	resp.sum_qnt = esq.sum_qnt + dir.sum_qnt;

	// PREF
	if (esq.pref <= esq.sum + dir.pref)
	{
		resp.pref = esq.sum + dir.pref;
		resp.pref_qnt = esq.sum_qnt + dir.pref_qnt;
	}
	if (esq.pref >= esq.sum + dir.pref)
	{
		resp.pref = esq.pref;
		resp.pref_qnt = max(esq.pref_qnt, resp.pref_qnt);
	}
	
	// SUF
	if (dir.suf <= dir.sum + esq.suf)
	{
		resp.suf = dir.sum + esq.suf;
		resp.suf_qnt = dir.sum_qnt + esq.suf_qnt;
	}
	if (dir.suf >= dir.sum + esq.suf)
	{
		resp.suf = dir.suf;
		resp.suf_qnt = max(dir.suf_qnt, resp.suf_qnt);
	}

	return resp;
}

void build(int idx, int i, int j)
{
	if (i == j)
	{
		st[idx].sum_qnt = st[idx].pref_qnt = st[idx].ans_qnt = st[idx].suf_qnt = 1;
		st[idx].sum = st[idx].pref = st[idx].ans = st[idx].suf = arr[i];
		return;
	}

	int mid = ((i+j)>>1);
	build(esq(idx), i, mid);
	build(dir(idx), mid+1, j);
	st[idx] = combine(st[esq(idx)], st[dir(idx)]);
}

tree query(int idx, int i, int j, int l, int r)
{
	if (i >= l && j <= r) return st[idx];
	if (i > r || j < l) return {-INF, 0, -INF, 0, -INF, 0, -INF, 0};

	int mid = ((i+j)>>1);
	tree x = query(esq(idx), i, mid, l, r);
	tree y = query(dir(idx), mid+1, j, l, r);
	return combine(x, y);
}

int main()
{_
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> arr[i];

		build(1, 1, n);
		cin >> q;
		while (q--)
		{
			cin >> a >> b;
			tree resp = query(1, 1, n, a, b);
			cout << resp.ans << ' ' << resp.ans_qnt << endl;
		}
	}
}
