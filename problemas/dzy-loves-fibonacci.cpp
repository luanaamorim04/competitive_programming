#include <iostream>
#define MOD (int)(1e9 + 9)
#define MAX (int)(3e5 + 10)
#define int long long
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define ST 0
#define ND 1
#define dbug(x) cout << #x << ": " << x << endl

using namespace std;

int n, q, arr[MAX], op, a, b, lazy[MAX<<2][2], psa[MAX][2], f[MAX][2], st[MAX<<2], fib[MAX];

void push(int idx, int i, int j)
{
	if (!lazy[idx][ST] && !lazy[idx][ND]) return;

	int a = (lazy[idx][ST]*psa[j-i+1][ST]) % MOD;
	int b = (lazy[idx][ND]*psa[j-i+1][ND]) % MOD;
	st[idx] = (st[idx] + a + b) % MOD;
	// printf("\033[35mi = %lld | j = %lld | first = %lld | second = %lld\033\n", i, j, lazy[idx][ST], lazy[idx][ND]);
	if (i != j)
	{
		int mid = ((j+i)>>1) - i + 1;
		a = (((lazy[idx][ST]*f[mid+1][ST]) % MOD) + ((lazy[idx][ND]*f[mid+1][ND]) % MOD)) % MOD;
		b = (((lazy[idx][ST]*f[mid+2][ST]) % MOD) + ((lazy[idx][ND]*f[mid+2][ND]) % MOD)) % MOD;
		// printf("\033[36mesq = %lld | dir = %lld | mid = %lld\033\n", a, b, mid);

		lazy[esq(idx)][ST] = (lazy[esq(idx)][ST] + lazy[idx][ST]) % MOD;
		lazy[esq(idx)][ND] = (lazy[esq(idx)][ND] + lazy[idx][ND]) % MOD;
		lazy[dir(idx)][ST] = (lazy[dir(idx)][ST] + a) % MOD;
		lazy[dir(idx)][ND] = (lazy[dir(idx)][ND] + b) % MOD;
	}

	lazy[idx][ST] = lazy[idx][ND] = 0;
}

void build(int idx, int i, int j)
{
	if (i == j)
	{
		st[idx] = arr[i];
		return;
	}
	int mid = (i+j)>>1;
	build(esq(idx), i, mid);
	build(dir(idx), mid+1, j);
	st[idx] = (st[esq(idx)] + st[dir(idx)]) % MOD;
}

void update(int idx, int i, int j, int l, int r)
{
	push(idx, i, j);
	if (i > r || j < l) return;
	if (i >= l && j <= r)
	{
		lazy[idx][ST] = fib[i-l+1];
		lazy[idx][ND] = fib[i-l+2];
		push(idx, i, j);
		return;
	}
	int mid = (i+j)>>1;
	update(esq(idx), i, mid, l, r);
	update(dir(idx), mid+1, j, l, r);
	st[idx] = (st[esq(idx)] + st[dir(idx)]) % MOD;
}

int query(int idx, int i, int j, int l, int r)
{
	push(idx, i, j);
	if (i > r || j < l) return 0;
	if (i >= l && j <= r) return st[idx];
	int mid = (i+j)>>1;
	int x = query(esq(idx), i, mid, l, r);
	int y = query(dir(idx), mid+1, j, l, r);
	return (x+y) % MOD;
}

int32_t main()
{
	fib[1] = fib[2] = 1;
	f[1][ST] = 1, f[2][ST] = 0;
	f[1][ND] = 0, f[2][ND] = 1;
	for (int i = 3; i < MAX; i++)
	{
		fib[i] = (fib[i-1] + fib[i-2]) % MOD;
		f[i][ST] = (f[i-1][ST] + f[i-2][ST]) % MOD;
		f[i][ND] = (f[i-1][ND] + f[i-2][ND]) % MOD;
	}

	for (int i = 1; i < MAX; i++)
	{
		psa[i][ST] = (psa[i-1][ST] + f[i][ST]) % MOD;
		psa[i][ND] = (psa[i-1][ND] + f[i][ND]) % MOD;
	}

	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	build(1, 1, n);
	while (q--)
	{
		cin >> op >> a >> b;
		if (op&1) update(1, 1, n, a, b);
		else cout << query(1, 1, n, a, b) << endl;
	}

	return 0;
}







