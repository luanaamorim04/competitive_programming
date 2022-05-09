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
#define MAX (int)(26 * (5e5 + 5))
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

int n, t[MAX], trie[MAX][26], qnt, tot, resp, maxn[MAX];
string s;

void add(string s)
{
	int u = 0;
	for (char c : s)
	{
		c -= 'a';
		if (!trie[u][c]) trie[u][c] = ++qnt;
		u = trie[u][c];
	}

	t[u] = 1;
}

int b(int u)
{
	++resp;
	if (t[u])
	{
		++tot;
		++resp;
		return 0;
	} 

	int nivel = 0;
	for (int i = 0; i < 26; i++)
	{
		if (!trie[u][i]) continue;
		int tam = b(trie[u][i]);
		if (nivel < 1 + tam)
		{
			if (nivel)
			{
				b(trie[u][maxn[u]]);
				resp += (tot != n);
			}
			nivel = 1 + tam;
			maxn[u] = i;
		}
		else
		{
			tam;
			resp += (tot != n);
		}
	}

	if (trie[u][maxn[u]])
	{
		b(trie[u][maxn[u]]);
		resp += (tot != n);
	} 

	return nivel;
}

void solve(int u, char c)
{
	if (u) printf("%c\n", c); 
	if (t[u])
	{
		printf("P\n");
		++tot;
	} 
	for (int i = 0; i < 26; i++)
	{
		if (!trie[u][i] || maxn[u] == i) continue;
		solve(trie[u][i], i+'a');
		if (tot != n) printf("-\n");
	}

	if (trie[u][maxn[u]])
	{
		solve(trie[u][maxn[u]], maxn[u]+'a');
		if (tot != n) printf("-\n");
	} 
}

int main()
{_
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		add(s);
	}
	b(0);
	cout << --resp << endl;
	tot = 0;
 	solve(0, ' ');
}










