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
#include <bitset>
#define ll long long
#define INF (1e9)
#define MAX (int) (2e5 + 5)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define esq(x) (x<<1)
#define dir(x) ((x<<1) + 1)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, arr[1<<20], st[1<<20][2], a, b, m;
char op;

void build(int idx, int i, int j)
{
	if (i == j) 
	{
		st[idx][0] = (!arr[i]);
		st[idx][1] = (arr[i] < 0);
		return;
	}

	int mid = ((i+j)>>1);
	build(esq(idx), i, mid);
	build(dir(idx), mid+1, j);
	st[idx][0] = (st[esq(idx)][0] | st[dir(idx)][0]);
	st[idx][1] = (st[esq(idx)][1] ^ st[dir(idx)][1]);
}

int query(int idx, int i, int j, int l, int r, int tipo)
{
	if (i >= l && j <= r) return st[idx][tipo];
	if (j < l || i > r) return 0;

	int mid = ((i+j)>>1);
	int x = query(esq(idx), i, mid, l, r, tipo);
	int y = query(dir(idx), mid+1, j, l, r, tipo);
	return (tipo ? (x^y) : (x|y));
}

void update(int idx, int i, int j, int pos, int val)
{
	if (i == j)
	{
		if (val)
		{
			st[idx][1] = (val < 0);
			st[idx][0] = 0;
		} 
		else 
		{
			st[idx][1] = 0;
			st[idx][0] = 1;
		}
		return; 
	}

	int mid = ((i+j)>>1);
	if (pos <= mid) update(esq(idx), i, mid, pos, val);
	else update(dir(idx), mid+1, j, pos, val);
	st[idx][0] = (st[esq(idx)][0] | st[dir(idx)][0]);
	st[idx][1] = (st[esq(idx)][1] ^ st[dir(idx)][1]);
}

int main()
{_
	while (cin >> n >> m)
	{
		for (int i = 1; i <= n; i++)
			cin >> arr[i];

		build(1, 1, n);

		while (m--)
		{
			cin >> op >> a >> b;
			if (op == 'C')
			{
				update(1, 1, n, a, b);
			}
			else
			{
				int resp = query(1, 1, n, a, b, 0);
				if (resp)
				{
					cout << '0';
					continue;
				} 
				resp = query(1, 1, n, a, b, 1);
				cout << (resp ? '-' : '+');
			}
		}

		cout << endl;
	}
}











