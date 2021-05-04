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
#define esq(x) (x<<1)
#define dir(x) ((x<<1)+1)
#define ANS 0
#define SUF 2
#define PREF 1
#define SUM 3
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll arr[1<<20], st[1<<20][4], n, q, a, b;

void join(int idx)
{
	st[idx][SUM] = st[esq(idx)][SUM] + st[dir(idx)][SUM];
	st[idx][SUF] = max(st[dir(idx)][SUF], st[dir(idx)][SUM] + st[esq(idx)][SUF]);
	st[idx][PREF] = max(st[esq(idx)][PREF], st[esq(idx)][SUM] + st[dir(idx)][PREF]); 
	st[idx][ANS] = max(st[esq(idx)][ANS], max(st[dir(idx)][ANS], st[dir(idx)][PREF]+st[esq(idx)][SUF])); 
}

void build(int idx, int i, int j)
{
	if (i == j)
	{
		st[idx][PREF] = st[idx][SUF] = st[idx][ANS] = max(0LL, arr[i]);
		st[idx][SUM] = arr[i];
		return;
	}

	int mid = ((i+j)>>1);
	build(esq(idx), i, mid);
	build(dir(idx), mid+1, j);
	join(idx);
}

void update(int idx, int i, int j, int pos, ll val)
{
	if (i == j)
	{
		st[idx][PREF] = st[idx][SUF] = st[idx][ANS] = max(0LL, val);
		st[idx][SUM] = val;
		return;
	}

	int mid = ((i+j)>>1);
	if (pos <= mid) update(esq(idx), i, mid, pos, val);
	else update(dir(idx), mid+1, j, pos, val);	
	join(idx);
}

int main()
{_
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	build(1, 1, n);

	while (q--)
	{
		cin >> a >> b;
		update(1, 1, n, a, b);
		cout << st[1][ANS] << endl;
	}
}
	