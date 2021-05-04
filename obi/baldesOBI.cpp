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
#define esq(x) (x<<1)
#define dir(x) ((x<<1)+1)
#define MAIOR 0
#define MENOR 1
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int mn[1<<20], mx[1<<20], n, m, op, a, b, st[1<<20][2], maior, menor, maior2, menor2;

void build(int idx, int i, int j)
{
	if (i == j)
	{
		st[idx][MAIOR] = st[idx][MENOR] = i;
		return;
	}

	int mid = ((i+j)>>1);
	build(esq(idx), i, mid);
	build(dir(idx), mid+1, j);
	int a = st[esq(idx)][MAIOR], b = st[dir(idx)][MAIOR];
	st[idx][MAIOR] = (mx[a] > mx[b] ? a : b);
	a = st[esq(idx)][MENOR], b = st[dir(idx)][MENOR];
	st[idx][MENOR] = (mn[a] < mn[b] ? a : b); 
}

int query(int idx, int i, int j, int l, int r, int tipo)
{
	if (i >= l && j <= r) return st[idx][tipo];
	if (i > r || j < l) return 0;

	int mid = ((i+j)>>1);
	int a = query(esq(idx), i, mid, l, r, tipo);
	int b = query(dir(idx), mid+1, j, l, r, tipo);
	if (tipo == MAIOR)
		return (mx[a] > mx[b] ? a : b);
	else 
		return (mn[a] < mn[b] ? a : b);
}

void update(int idx, int i, int j, int pos)
{
	if (i == j) 
	{
		st[idx][MAIOR] = pos;
		st[idx][MENOR] = pos;
		return;
	}

	int mid = ((i+j)>>1);
	if (pos <= mid) update(esq(idx), i, mid, pos);
	else update(dir(idx), mid+1, j, pos);
	int a = st[esq(idx)][MAIOR], b = st[dir(idx)][MAIOR];
	st[idx][MAIOR] = (mx[a] > mx[b] ? a : b);
	a = st[esq(idx)][MENOR], b = st[dir(idx)][MENOR];
	st[idx][MENOR] = (mn[a] < mn[b] ? a : b); 
}

int main()
{_
	cin >> n >> m;
	mn[0] = INF;
	for (int i = 1; i <= n; i++)
	{
		cin >> mn[i];
		mx[i] = mn[i];
	}

	build(1, 1, n);

	while (m--)
	{
		cin >> op >> a >> b;
		if (op == 1)
		{
			mn[b] = min(mn[b], a);
			mx[b] = max(mx[b], a);
			update(1, 1, n, b);
		}
		else
		{
			maior = query(1, 1, n, a, b, MAIOR);
			menor = query(1, 1, n, a, b, MENOR);
			menor2 = min(mn[query(1, 1, n, a, maior-1, MENOR)], mn[query(1, 1, n, maior+1, b, MENOR)]);
			maior2 = max(mx[query(1, 1, n, a, menor-1, MAIOR)], mx[query(1, 1, n, menor+1, b, MAIOR)]);

			if (maior != menor) cout << mx[maior]-mn[menor] << endl;
			else cout << max(mx[maior]-menor2, maior2-mn[menor]) << endl;
		}
	}
}
















