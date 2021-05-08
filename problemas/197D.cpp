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
#define esq(x) (x<<1)
#define dir(x) ((x<<1) + 1)
#define MAX (int) (2e5 + 5)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll arr[1<<20], st[1<<20], n, q, a, b;

void build(int idx, int i, int j, int nivel)
{
	if (i == j) 
	{
		st[idx] = arr[i];
		return;
	}

	int mid = ((i+j)>>1);
	build(esq(idx), i, mid, nivel-1);
	build(dir(idx), mid+1, j, nivel-1);
	st[idx] = ((nivel&1) ? (st[esq(idx)]|st[dir(idx)]) : (st[esq(idx)]^st[dir(idx)]));
}

void update(int idx, int i, int j, int pos, ll val, int nivel)
{
	if (i == j) 
	{
		st[idx] = val;
		return;
	}

	int mid = ((i+j)>>1);
	if (pos <= mid) update(esq(idx), i, mid, pos, val, nivel-1);
	else update(dir(idx), mid+1, j, pos, val, nivel-1);
	st[idx] = ((nivel&1) ? (st[esq(idx)]|st[dir(idx)]) : (st[esq(idx)]^st[dir(idx)]));
}

int main()
{_
	cin >> n >> q;
	for (int i = 1; i <= (1<<n); i++)
		cin >> arr[i];

	build(1, 1, (1<<n), n);

	while (q--)
	{
		cin >> a >> b;
		update(1, 1, (1<<n), a, b, n);
		cout << st[1] << endl;
	}
}









