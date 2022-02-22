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
#define MAX (int) (26*(1e5 + 5))
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

int n, t[MAX], qnt, resp;
string s;
vector<pair<int, char> > trie[MAX];

void add(string s)
{
	int u = 0, tmp = qnt;
	for (char c : s)
	{
		int idx = -1;
		for (int i = 0; i < sz(trie[u]); i++)
			if (c==trie[u][i].second) idx = i;

		if (idx==-1) idx = sz(trie[u]), trie[u].push_back({++qnt, c});
		u = trie[u][idx].first;
		if (t[u]) resp = 1;
	}

	resp |= (tmp==qnt);
	t[u]++;
}

void erase(vector<pair<int, char> > &v)
{
	vector<pair<int, char> > lixo;
	swap(v, lixo);
}

int main()
{_
	while (cin >> n && n)
	{
		resp = qnt = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> s;
			if (!resp) add(s);
		}

		for (int i = 0; i <= qnt; i++)
		{
			t[i] = 0;
			erase(trie[i]);
		}

		cout << (resp ? "Conjunto Ruim" : "Conjunto Bom") << endl;
	}
}	

















