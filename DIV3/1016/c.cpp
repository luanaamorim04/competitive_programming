#include <bits/stdc++.h>
#define int long long
#define MAXN (int)(1e6 + 10)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int)(1e9 + 7)
#define BASE 37
#define MAXL 20
#define INF (int)(1LL<<30)
#define PI 3.14159265359
#define EPS (1e-9)
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

int t, n, k;

int32_t main()
{_
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		if (n == 1 && k == 2)
		{
			n += 10*n;
			k = 1;
		}
		int ok = 1;
		for (int i = 2; i*i <= n; i++)
		{
			if (n%i == 0) 
			{
				ok = 0;
				break;
			}
		}

		cout << ((ok && n != 1) && k==1 ? "YES" : "NO") << endl;
		
	}
}
