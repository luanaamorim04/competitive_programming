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
#include <numeric>
#define ll long long
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

int t, n, arr[MAX], st[MAX<<2];

void build(int i, int j, int idx)
{
	if (i == j)
	{
		st[idx] = arr[i];
		return;
	}
	int mid = ((i+j)>>1);
	build(i, mid, esq(idx));
	build(mid+1, j, dir(idx));
	st[idx] = gcd(st[esq(idx)], st[dir(idx)]);
}

int query(int i, int j, int idx, int l, int r)
{
	if (i > r || j < l) return 0;
	if (i >= l && j <= r) return st[idx];
	int mid = ((i+j)>>1);
	int x = query(i, mid, esq(idx), l, r);
	int y = query(mid+1, j, dir(idx), l, r);
	return gcd(x, y);
}

int f(int x)
{
	int resp = query(1, n, 1, 1, x);
	for (int i = 2; i <= n; i++)
	{
		int tmp;
		if (i + x - 1 > n)
		{
			tmp = query(1, n, 1, i, n);
			int tmp2 = query(1, n, 1, 1, x-(n-i+1));
			tmp = gcd(tmp, tmp2);
		}
		else
		{
			tmp = query(1, n, 1, i, i+x-1);
		}

		if (tmp != resp) return 0;
	}
	return 1;
}

int main()
{_
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> arr[i];

		build(1, n, 1);
		int ini = 1, meio, fim = n;
		while (ini <= fim)
		{
			meio = ((ini+fim)>>1);
			if (f(meio)) fim = meio - 1;
			else ini = meio + 1;
		}

		cout << fim << endl;
	}
}








