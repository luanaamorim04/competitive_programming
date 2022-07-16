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

int n, m, t, a, b, op, inv[3], pai[MAX], tam[MAX], r[MAX], resp;

int find(int x)
{
	if (x == pai[x]) return x;
	return find(pai[x]);
}

int join(int a, int b, int op)
{
	int A = find(a), B = find(b), sum = 0;
	if (tam[A] > tam[B]) swap(a, b), swap(A, B), op = inv[op];

	while (a != A)
	{	
		sum += r[a];
		a = pai[a];
	}

	while (b != B)
	{
		sum += inv[r[b]];
		b = pai[b];
	}

	sum%=3;

	if (A==B) return (sum != op);

	tam[B] += tam[A];
	pai[A] = B;
	r[A] = (op-sum+3)%3;
	return 0;
}

int main()
{_
	cin >> t;
	inv[1] = 2; inv[2] = 1;
	while (t--)
	{
		cin >> n >> m;
		resp = 0;
		for (int i = 1; i <= n; i++)
			pai[i] = i, tam[i] = 1, r[i] = 0;

		while (m--)
		{
			cin >> op >> a >> b;
			if (a > n || b > n) 
			{
				resp++;
				continue;
			}
			resp += join(a, b, --op);
		}

		cout << resp << endl;
	}
}











