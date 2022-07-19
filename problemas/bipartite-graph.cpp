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

int n, m, pai[MAX], peso[MAX], tam[MAX], shift, a, b, op;

int find(int x)
{
	if (x==pai[x]) return x;
	return find(pai[x]);
}

void join(int a, int b)
{
	int A = find(a), B = find(b), resp = 0;
	if (A==b) return;
	if (tam[A]>tam[B]) swap(a, b), swap(A, B);
	tam[B] += tam[A];
	pai[A] = B;
	while (a != A)
	{
		resp ^= peso[a];
		a = pai[a];
	}

	while (b != B)
	{
		resp ^= peso[b];
		b = pai[b];
	}
	peso[A] = resp^1;
}

int query(int a, int b)
{
	int A = find(a), B = find(b), resp = 0;
	while (a != A)
	{
		resp ^= peso[a];
		a = pai[a];
	}

	while (b != B)
	{
		resp ^= peso[b];
		b = pai[b];
	}

	shift += (!resp);
	return !resp;
}

int main()
{_
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) pai[i] = i, tam[i] = 1;
	while (m--)
	{
		scanf("%d%d%d", &op, &a, &b);
		a += shift, b += shift;
		a %= n, b %= n;
		if (op)
		{
			printf(query(a, b) ? "YES\n" : "NO\n");
			continue;
		}
		
		join(a, b);
	}
}











