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
#define dbug(x) cout << (#x) << " -> " << x << endl
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

int l[MAX], c[MAX], n, m, q, a1, b1, a2, b2;
char op;

int queryl(int idx)
{
	int resp = 0;
	while (idx > 0)
	{
		resp += l[idx];
		idx -= lsb(idx);
	}

	return resp;
}

void updatel(int idx, int val)
{
	while (idx <= n)
	{
		l[idx] += val;
		idx += lsb(idx);
	}
}

int queryc(int idx)
{
	int resp = 0;
	while (idx > 0)
	{
		resp += c[idx];
		idx -= lsb(idx);
	}

	return resp;
}

void updatec(int idx, int val)
{
	while (idx <= m)
	{
		c[idx] += val;
		idx += lsb(idx);
	}
}

int main()
{_
	cin >> n >> m >> q;
	while (q--)
	{
		cin >> op >> a1 >> b1;
		if (op == 'A')
			updatel(a1, 1), updatec(b1, 1);
		else if (op == 'R')
			updatel(a1, -1), updatec(b1, -1);
		else
		{
			cin >> a2 >> b2;
			int linhas = queryl(a2) - queryl(a1-1);
			int colunas = queryc(b2) - queryc(b1-1);
			cout << ((linhas==(a2-a1+1)||(colunas==(b2-b1+1)) ? "S" : "N")) << endl;
		}
	}
}










