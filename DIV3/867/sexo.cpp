#include <iostream>
#include <vector>
#define MAXN (int) (2e5 + 3)
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define int long long
#define sz(x) (int) x.size()
#define dbug(a) cout << #a << " -> " << a << endl;
#define ii pair<int, int>
#define MOD (int) (1e9 + 7)
#define mp(a, b) make_pair(a, b)

using namespace std;

struct tree 
{
	vector<ii> pref, suff;
	int resp;
};

int n, q, arr[MAXN], l, r;
tree st[MAXN<<2], vazio;

int mdc(int a, int b)
{
	if (b == 0) return a;
	return mdc(b, a % b);
}

tree join(tree esq, tree dir)
{
	if (esq.resp == -1) return dir;
	if (dir.resp == -1) return esq;
	tree r;
	r.resp = esq.resp + dir.resp;
	int t1 = 0, t2 = 0;

	for (int i = 0; i < sz(esq.suff); i++)
	{
		t1 += esq.suff[i].second;
		t2 = 0;
		for (int j = 0; j < sz(dir.pref); j++)
		{
			t2 += dir.pref[j].second;
			if (mdc(esq.suff[i].first, dir.pref[j].first) > 1)
				r.resp += (t1*t2);
		}
	}

	r.pref = esq.pref;
	int last = esq.pref[sz(esq.pref) - 1].first;
	for (int i = 0; i < sz(dir.pref); i++)
	{
		if (mdc(last, dir.pref[i].first) == last)
			r.pref[sz(r.pref) - 1].second += dir.pref[i].second;
		else
		{
			last = mdc(last, dir.pref[i].first);
			r.pref.push_back(mp(last, dir.pref[i].second));
		}
	}

	r.suff = dir.suff;
	last = dir.suff[sz(dir.suff) - 1].first;
	for (int i = 0; i < sz(esq.suff); i++)
	{
		if (mdc(last, esq.suff[i].first) == last)
			r.suff[sz(r.suff) - 1].second += esq.suff[i].second;
		else
		{
			last = mdc(last, esq.suff[i].first);
			r.suff.push_back(mp(last, esq.suff[i].second));
		}
	}

	return r;
}

void build(int i, int j, int idx)
{
	if (i == j)
	{
		st[idx].resp = (arr[i] != 1);
		st[idx].suff.push_back(mp(arr[i], 1));
		st[idx].pref.push_back(mp(arr[i], 1));
		return;
	}
	int mid = (i+j)>>1;
	build(i, mid, esq(idx));
	build(mid+1, j, dir(idx));
	st[idx] = join(st[esq(idx)], st[dir(idx)]);
}

tree query(int i, int j, int idx, int l, int r)
{
	if (i > r || j < l) return vazio;
	if (i >= l && j <= r)
	{
		printf("st[%d, %d] = %d\n", i, j, st[idx].resp);
		return st[idx];
	}
	int mid = (i+j)>>1;
	tree x = query(i, mid, esq(idx), l, r);
	tree y = query(mid+1, j, dir(idx), l, r);
	return join(x, y);
}

int32_t main()
{
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	vazio.resp = -1;
	build(1LL, n, 1LL);
	while (q--)
	{
		cin >> l >> r;
		cout << query(1LL, n, 1LL, l, r).resp << endl;
	}
}