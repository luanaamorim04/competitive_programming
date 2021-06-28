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
#define INF (1e9)
#define MAX (int) (200)
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

int n, m, k, op, x, pos[MAX], teste, dead[MAX], psa[MAX], pai[MAX];

int main()
{_
	while (cin >> n >> m && (n || m))
	{
		for (int i = 1; i <= n; i++) 
		{
			cin >> x;
			pos[x] = i;
			pai[i] = i;
		}

		while (m--)
		{
			cin >> k >> op;
			int idx = 0;
			for (int i = 1; i <= k; i++)
			{
				cin >> x;
				if (x != op) dead[pai[i]] = 1;
			}

			for (int i = 1; i <= n; i++)
				if (!dead[i]) pai[++idx] = i;
		}

		cout << "Teste " << ++teste << endl;
		for (int i = 1; i <= n; i++)
		{
			if (!dead[pos[i]])
			{
				cout << i << endl;
				break;
			} 
		}
		cout << endl;
		memset(dead, 0, sizeof dead);
	}
}	













