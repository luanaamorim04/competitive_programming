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
#define MAX (int) (2e6 + 5)
#define MOD 1000000007
#define MAXL 20
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

ll n, arr[MAX], trie[MAX][2], t, m, qnt, sub[MAX], resp;

void add(int k)
{
	int u = 0;
	string s = bitset<MAXL>(k).to_string();
	for (char c : s)
	{
		c -= '0';
		if (!trie[u][c]) trie[u][c] = ++qnt;
		u = trie[u][c];
		sub[u]++;
	}
}

void solve(int k)
{
	int u = 0, n = MAXL-1;
	ll tmp = 0;
	string s = bitset<MAXL>(k).to_string();
	for (char c : s)
	{
		c -= '0';
		if ((1LL<<n)+tmp >= m)
		{
			u = trie[u][c];
		}
		else
		{
			resp += sub[trie[u][c]];
			u = trie[u][c^1];
			tmp += (1LL<<n);
		}
		if (!u) break;
 		--n;
	}
}

int main()
{_
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		add(0);
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
			arr[i] ^= arr[i-1];
			add(arr[i]);
		}

		for (int i = 1; i <= n; i++)
		{
			solve(arr[i]);
			arr[i] = 0;
		}

		for (int i = 0; i <= qnt; i++)
			trie[i][0] = trie[i][1] = sub[i] = 0;
		
		cout << (resp>>1) << endl;
		qnt = resp = 0;
	}
}










