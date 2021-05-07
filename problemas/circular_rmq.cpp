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
#define INF (1e13)
#define MAX (int) (2e5 + 5)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define esq(x) (x<<1)
#define dir(x) ((x<<1)+1)
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

string s;
ll num[3], lazy[1<<20], st[1<<20], n, m, arr[1<<20];

void push(int idx, int i, int j)
{
	st[idx]+=lazy[idx];
	if (i != j)
	{
		lazy[esq(idx)] += lazy[idx];
		lazy[dir(idx)] += lazy[idx];
	}
	lazy[idx] = 0;
}

void build(int idx, int i, int j)
{
	if (i == j)
	{
		st[idx] = arr[i];
		return;
	}

	int mid = ((i+j)>>1);
	build(esq(idx), i, mid);
	build(dir(idx), mid+1, j);
	st[idx] = min(st[esq(idx)], st[dir(idx)]);
}

ll query(int idx, int i, int j, int l, int r)
{	
	push(idx, i, j);
	if (i > r || j < l) return INF;
	if (i >= l && j <= r) return st[idx];

	int mid = ((i+j)>>1);
	ll x = query(esq(idx), i, mid, l, r);
	ll y = query(dir(idx), mid+1, j, l, r);
	return min(x, y);
}

void update(int idx, int i, int j, int l, int r, ll val)
{
	push(idx, i, j);
	if (i > r || j < l) return;

	if (i >= l && j <= r)
	{
		lazy[idx] += val;
		push(idx, i, j);
		return;
	}

	int mid = ((i+j)>>1);
	update(esq(idx), i, mid, l, r, val);
	update(dir(idx), mid+1, j, l, r, val);
	st[idx] = min(st[esq(idx)], st[dir(idx)]);
}

int main()
{_
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	build(1, 0, n-1);
	cin >> m;
	getline(cin, s);
	while (m--)
	{
		getline(cin, s);
		ll pot = 1, idx = 0, resp = 0;
		for (int i = s.size() - 1; i >= -1; i--)
		{
			if (s[i] == ' ' || i == -1)
			{
				pot = 1;
				num[idx++] = resp;
				resp = 0;
				continue;
			}

			if (s[i] == '-')
			{
				resp *= -1;
				continue;
			}

			resp += pot*(s[i]-'0');
			pot *= 10;
		}

		if (idx == 3)
		{
			if (num[1] >= num[2])
			{
				update(1, 1, n, num[2]+1, num[1]+1, num[0]);
			}
			else
			{
				update(1, 1, n, num[2]+1, n, num[0]);
				update(1, 1, n, 1, num[1]+1, num[0]);
			}
		}
		else
		{
			if (num[0] >= num[1])
			{
				cout << query(1, 1, n, num[1]+1, num[0]+1) << endl;
			}
			else
			{
				cout << min(query(1, 1, n, num[1]+1, n), query(1, 1, n, 1, num[0]+1)) << endl;
			}
		}
	}
}
























