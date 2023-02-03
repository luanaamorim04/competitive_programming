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
#define MAXN (int)(1e5 + 10)
#define MOD (int)(1e9 + 7)
#define esq(x) (x<<1)
#define int long long
#define dir(x) ((x<<1)|1)

using namespace std;

typedef pair<int, int> ii;

struct tree
{
	int a, b, c;
};

tree lazy[MAXN<<2];
int st[MAXN<<2];
int n, q;
int sqr[MAXN], psa[MAXN];
int a, b, op;

void refresh(int idx, int i, int j)
{
	if (lazy[idx].a == 0 && lazy[idx].b == 0 && lazy[idx].c == 0) return;
	int soma = (psa[j]-psa[i-1]+MOD)%MOD;
	int quad = (sqr[j]-sqr[i-1]+MOD)%MOD;
	st[idx] += ((((soma*lazy[idx].a)%MOD) - ((lazy[idx].c*quad)%MOD) + MOD + (((j-i+1)*lazy[idx].b)%MOD))) % MOD;
	st[idx] %= MOD;
	if (i != j)
	{
		lazy[esq(idx)].a = (lazy[esq(idx)].a + lazy[idx].a) % MOD;
		lazy[esq(idx)].b = (lazy[esq(idx)].b + lazy[idx].b) % MOD;
		lazy[esq(idx)].c = (lazy[esq(idx)].c + lazy[idx].c) % MOD;
		lazy[dir(idx)].c = (lazy[dir(idx)].c + lazy[idx].c) % MOD;
		lazy[dir(idx)].a = (lazy[dir(idx)].a + lazy[idx].a) % MOD;
		lazy[dir(idx)].b = (lazy[dir(idx)].b + lazy[idx].b) % MOD;
	}

	lazy[idx] = {0, 0, 0};
}

void update(int idx, int i, int j, int l, int r)
{
	refresh(idx, i, j);
	if (i > r || j < l) return;
	if (i >= l && j <= r)
	{
		lazy[idx].c = 1;
		lazy[idx].a = r+l;
		lazy[idx].b = (-(l*r % MOD) + r - l + 1 + 2*MOD) % MOD;
		refresh(idx, i, j);
		return;
	}
	int mid = (i+j)>>1;
	update(esq(idx), i, mid, l, r);
	update(dir(idx), mid+1, j, l, r);
	st[idx] = (st[esq(idx)] + st[dir(idx)]) % MOD;
}

int query(int idx, int i, int j, int l, int r)
{
	refresh(idx, i, j);
	if (i > r || j < l) return 0;
	if (i >= l && j <= r) return st[idx];
	int mid = (i+j)>>1;
	int x = query(esq(idx), i, mid, l, r);
	int y = query(dir(idx), mid+1, j, l, r);
	return (x+y) % MOD;
}

int32_t main()
{
	cin >> n >> q;
	for (long long i = 1; i <= n; i++)
	{	
		sqr[i] = (sqr[i-1] + (i*i)) % MOD;
    	psa[i] = (psa[i-1] + i) % MOD;
	}

	while (q--)
	{
		cin >> op >> a >> b;
		if (op&1)
		{
			update(1, 1, n, a, b);
		}
		else
		{
			cout << query(1, 1, n, a, b) << endl;
		}
	}
}
