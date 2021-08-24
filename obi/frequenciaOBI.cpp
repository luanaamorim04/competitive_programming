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
#define ll long long
#define INF (1e9)
#define MAX (int) (2e5 + 5)
#define MOD 1000000007
#define par pair<ll, ll>
#define all(v) v.begin(), v.end()
#define sz(x) (int) ((x).size())
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define lsb(x) (x & -x)
#define W(x) cout << #x << ": " << x << endl
#define Wii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll ft[2][55][MAX], n, q, op, x, r, linha[MAX], coluna[MAX], freq[55], resp;
par last[2][MAX];
int tab[1005][1005];

ll query(int lc, int cor, int idx)
{
	ll ans = 0;
	while (idx > 0)
	{
		ans += ft[lc][cor][idx];
		idx -= lsb(idx);
	}
	return ans;
}

void update(int lc, int cor, int idx, ll val)
{
	while (idx < MAX)
	{
		ft[lc][cor][idx] += val;
		idx += lsb(idx);
	}
}

void solve()
{
	for (int i = 1; i <= q; i++)
	{
		memset(freq, 0, sizeof freq);
		cin >> op >> x;
		if (op == 1)
		{
			cin >> r;
			for (int j = 1; j <= n; j++)
			{
				tab[x][j] = r;
			}
		}
		if (op == 2)
		{
			cin >> r;
			for (int j = 1; j <= n; j++)
				tab[j][x] = r;
		}
		if (op == 3)
		{
			for (int j = 1; j <= n; j++)
				freq[tab[x][j]]++;

			for (int j = 0; j <= 50; j++)
				if (freq[j] >= freq[resp]) resp = j;
			cout << resp << endl;
		}
		if (op == 4)
		{
			for (int j = 1; j <= n; j++)
				freq[tab[j][x]]++;

			for (int j = 0; j <= 50; j++)
				if (freq[j] >= freq[resp]) resp = j;
			cout << resp << endl;
		}
	}
}

int main()
{_
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		last[0][i] = last[1][i] = {q+1, 0}; 
		linha[i] = coluna[i] = 51;
	}

	if (n <= 1000) 
	{
		solve();
		return 0;
	}

	for (int i = q; i >= 1; i--)
	{
		resp = 0;
		memset(freq, 0, sizeof freq);
		cin >> op >> x;
		if (op == 1)
		{
			cin >> r;
			update(1, r, i, 1);
			update(1, linha[x], i, -1);
			linha[x] = r;
			last[0][x] = {i, r};
		}
		else if (op == 2)
		{
			cin >> r;
			update(0, r, i, 1);
			update(0, coluna[x], i, -1);
			coluna[x] = r;
			last[1][x] = {i, r};
		}
		else if (op == 3) 
		{
			int t = last[0][x].first, c = last[0][x].second;
			freq[c] = n + query(0, 51, t);
			for (int j = 0; j <= 50; j++)
			{
				freq[j] += query(0, j, t);
				if (freq[j] >= freq[resp]) resp = j;
			}
			
			cout << resp << endl;
		}	
		else
		{
			int t = last[1][x].first, c = last[1][x].second;
			freq[c] = n + query(1, 51, t);
			for (int j = 0; j <= 50; j++)
			{
				freq[j] += query(1, j, t);
				if (freq[j] >= freq[resp]) resp = j;
			}
			cout << resp << endl;
		}
	}
}














