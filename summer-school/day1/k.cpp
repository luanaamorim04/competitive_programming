#include <iostream>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MAXN (int) (2e5 + 10)

using namespace std;

int n, k, dp[MAXN][51], st[MAXN<<2], arr[MAXN], last[MAXN], tmp[MAXN];

void update(int idx, int i, int j, int pos, int val)
{
	if (i == j)
	{
		st[idx] += val;
		return;
	}
	int mid = (i+j)>>1;
	if (pos <= mid) update(esq(idx), i, mid, pos, val);
	else update(dir(idx), mid+1, j, pos, val);
	st[idx] = st[esq(idx)] + st[dir(idx)];
}

int query(int idx, int i, int j, int l, int r)
{
	if (i > r || j < l) return 0;
	if (i >= l && j <= r) return st[idx];
	int mid = (i+j)>>1;
	int x = query(esq(idx), i, mid, l, r);
	int y = query(dir(idx), mid+1, j, l, r);
	return x+y;
}


int32_t main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		last[i] = tmp[arr[i]];
		printf("last[%d] == %d\n", i, last[i]);
		update(1, 0, n-1, last[i], 1);
		tmp[arr[i]] = i;
	}
	
	dp[0][1] = query(1, 0, n, 0, 0);
	cout << dp[0][1] << endl;
	for (int i = 1; i <= n; i++)
	{
		update(1, 1, n, last[i], -1); //tiro o last i
		int add = query(1, 0, n-1, 0, i-1); //quantos sao menores que i
		for (int j = 1; j <= k; j++)
		{
			dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + add);
			printf("dp[%d][%d] == %d\n", i, j, dp[i][j]);
		}
	}

	cout << dp[n][k] << endl;
}
