#include <iostream>
#include <vector>
#include <math.h>
#include <set>
#include <map>
//#include <bits/stdc++.h>
#define MAXN (int) (2e5 + 10)
#define int long long
#define all(x) x.begin(), x.end()
#define ii pair<int, int> 
#define INF (int) (1e9)
#define MOD (int) (1e9 + 7)
#define iii tuple<int, int, int> 
#define BASE 37

using namespace std;

int t, n;
string s[MAXN], g[MAXN];
map<string, int> mapa;
vector<string> v;

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> g[i] >> s[i];
			v.push_back(g[i]);
			v.push_back(s[i]);
		}

		sort(all(v));
		for (int i = 0; i < v.size(); i++)
			mapa[v[i]] = i;

		int ok, resp = 0;
		for (int i = 0; i < (1<<n); i++)
		{
			ok = 0;
			for (int j = 0; j < n; j++)
			{
				if (!(i&(1<<j))) continue;
				for (int k = 0; k < n; k++)
				{
					if (!(i&(1<<k))) continue;
					ok += (mapa[g[j]] != mapa[g[k]] && mapa[s[j]] != mapa[s[k]]);
					if (ok)
					{
						cout << j << ' ' << k << endl;
						cout << mapa[s[j]] << ' ' << mapa[s[k]] << endl;
						return 0;
					}
				}
			}

			if (ok) continue;
			resp = max(resp, (int) __builtin_popcount(i));
		}

		cout << n-resp << endl;
	}
}	

