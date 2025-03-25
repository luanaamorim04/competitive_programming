#include <bits/stdc++.h>
#define int long long
#define MAXN (int) (1e6 + 10)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int) (1e9 + 7)
#define BASE 37
#define MAXL 20
#define INF (int) (1e9)
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

int d, t, n, arr[MAXN];

int32_t main()
{_
	cin >> t;
	while (t--)
	{
		cin >> n >> d;
		for (int i = 0; i < n; i++) cin >> arr[i];
		sort(arr, arr+n, greater<int>());

		int last = 0, menor = INF, r = 0;
		for (int i = 0; i < n; i++)
		{
			menor = min(menor, arr[i]);
			if (menor*(i-last+1) >= d) 
			{
				r++;
				last = i+1;
				menor = INF;
			}
		}
		cout << r << endl;
	}
}
