#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring>
#include <set>
#include <stack>
#include <bitset>
#define dbug(x) cout << (#x) << " -> " << x << endl
#define int long long
#define INF (1e9)
#define MAX (int) (2e5 + 5)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define sz(x) (int) ((x).size())
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define lsb(x) (x & -x)
#define W(x) cout << #x << ": " << x << endl
#define Wii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

struct tree
{
	int ini, fim, resp, qa, qb;
};

tree st[MAX<<2], vazio;
int n, arr[MAX], q, op, a, b, freq[MAX];
char c;

tree join(tree esq, tree dir)
{
	if (esq.resp == -1) return dir;
	if (dir.resp == -1) return esq;
	tree r;
	r.resp = (esq.resp&dir.resp);
	if (esq.fim > dir.ini) r.resp = 0;
	r.ini = esq.ini;
	r.fim = dir.fim;
	r.qa = esq.qa;
	r.qb = dir.qb;
	if (esq.ini == dir.ini) r.qa += dir.qa;
	if (dir.fim == esq.fim) r.qb += esq.qb;
	return r;
}

void build(int idx, int i, int j)
{
	if (i == j)
	{
		st[idx].ini = st[idx].fim = arr[i];
		st[idx].resp = st[idx].qa = st[idx].qb = 1;
		return;
	}

	int mid = (i+j)>>1;
	build(esq(idx), i, mid);
	build(dir(idx), mid+1, j);
	st[idx] = join(st[esq(idx)], st[dir(idx)]);
}

void update(int idx, int i, int j, int pos, int val)
{
	// cout << i << ' ' << j << endl;
	if (i == j)
	{
		st[idx].ini = st[idx].fim = val;
		st[idx].resp = st[idx].qa = st[idx].qb = 1;
		return;
	}
	int mid = (i+j)>>1;
	if (pos <= mid) update(esq(idx), i, mid, pos, val);
	else update(dir(idx), mid+1, j, pos, val);
	st[idx] = join(st[esq(idx)], st[dir(idx)]);
}

tree query(int idx, int i, int j, int l, int r)
{
	if (i > r || j < l) return vazio;
	if (i >= l && j <= r) return st[idx];
	int mid = (i+j)>>1;
	tree x = query(esq(idx), i, mid, l, r);
	tree y = query(dir(idx), mid+1, j, l, r);
	return join(x, y);
}

int32_t main()
{_
	vazio = {-1, -1, -1, -1, -1};
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		char c;
		cin >> c;
		arr[i] = c-'a'+1;
		freq[arr[i]]++;
	}
	
	build(1, 1, n);

	cin >> q;
	while (q--)
	{
		cin >> op;
		if (op&1)
		{
			cin >> a >> c;
			freq[arr[a]]--;
			c -= 'a';
			c++;
			freq[c]++;
			arr[a] = c;
			update(1, 1, n, a, c);
		}
		else
		{
			cin >> a >> b;
			tree pode = query(1, 1, n, a, b);
			if (!pode.resp)
			{
				cout << "No" << endl;
				continue;
			}
			int qtd = 0;
			for (int i = arr[a]+1; i < arr[b]; i++)
				qtd += freq[i];

			if (arr[a] == arr[b] || qtd == (b-a+1) - (pode.qa+pode.qb))
			{
				// dbug(pode.qa);
				// dbug(pode.qb);
				// cout << arr[b]-1 << ' ' << freq[arr[b]-1] << endl;
				// cout << arr[a] << ' ' << freq[arr[a]] << endl;
				// cout << endl;
				cout << "Yes" << endl;
			}
			else
			{
				cout << "No" << endl;
			}
		}
	}

}







