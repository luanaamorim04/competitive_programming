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

ll arr[MAX], trie[MAX][2], n, resp, tmp, qnt;

void add(ll k)
{
	int bit = 0, u = 0;
	for (int i = 4; i >= 0; i--)
	{
		bit = ((1LL<<i) <= k);
		if (bit) k -= (1LL<<i);
		if (!trie[u][bit]) trie[u][bit] = ++qnt;
		u = trie[u][bit];
	}
}

ll query(ll k)
{
	ll resp = 0;
	int bit = 0, u = 0;
	for (int i = 4; i >= 0; i--)
	{
		bit = !((1LL<<i) <= k);
		if (!bit) k -= (1LL<<i);

		if (!trie[u][bit]) bit^=1;
		else resp |= (1LL<<i);
	
		u = trie[u][bit];
	}

	return resp;
}

int main()
{_
	cin >> n;
	for (int i = 0; i < n; i++) 
	{
		cin >> arr[i];
		add(arr[i]);
	}

	for (int i = 0; i < n; i++)
		resp = max(resp, query(arr[i]));
	
	cout << resp << endl;
}











