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
#define MAX (int) (2e6 + 5)
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

int pai[MAX], tam[MAX], n, q, l, r;
ll soma[MAX], x;
char op;

int find(int x)
{
	if (pai[x] == x) return x;
	int k = find(pai[x]);
	soma[x] += soma[pai[x]];
	return pai[x] = k;
}	

void join(int a, int b, ll c)
{
	int A = find(a), B = find(b);
	if (A == B) return;	
	if (tam[A] > tam[B]) c *= -1, swap(A, B), swap(a, b);
	pai[A] = B;
	tam[B] += tam[A];
	while (a != A)
	{	
		c -= soma[a];
		a = pai[a];
	}
	while (b != B)
	{
		c += soma[b];
		b = pai[b];
	}
	soma[A] = c;
}

ll query(int a, int b)
{
	ll s1 = 0, s2 = 0;
	int B = find(b), A = find(a);
	while (a != A)
	{	
		s1 += soma[a];
		a = pai[a];
	}
	while (b != B)
	{
		s2 += soma[b];
		b = pai[b];
	}
	return s1-s2;
}

int main()
{_
	cin >> n >> q;
	for (int i = 0; i <= n; i++)
	{
		tam[i] = 1;
		pai[i] = i;
	}

	while (q--)
	{
		cin >> op >> l >> r;
		if (op == 'C')
		{
			if (find(l-1) != find(r))
				cout << "Esquecido" << endl;
			else 
				cout << query(l-1, r) << endl;
		}
		else
		{
			cin >> x;
			join(l-1, r, x);
		}
	}
}















