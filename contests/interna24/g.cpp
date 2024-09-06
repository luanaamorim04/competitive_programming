#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <queue>
#include <map>
//#include <bits/stdc++.h>
#define MAXN (int) (2e5 + 10)
#define int long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define MOD (int) (1e9 + 7)
#define INF (int) (1e18 + 10)
#define all(x) x.begin(), x.end()
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)

using namespace std;

int t, n, k, arr[MAXN];

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> n;
		map<int, int> mapa;
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
			mapa[arr[i]] = 1;
		}

		for (int i = 1; i <= 1; i++)
		{
			int q = 1, pot = 0, pos = arr[i], last = -1;
			vector<int> resp;
			resp.push_back(arr[i]);
			while (q < n)
			{
				cout << pos << ' ' << last << endl;
				mapa[pos] = 0;
				if (mapa[pos + (1LL<<pot)])
				{
					while (last != -1 && last < pot)
					{
						resp.push_back(pos + (1LL<<last));
						last++;
					}
					last = -1, q++, pos = pos + (1LL<<pot);
					resp.push_back(pos);

				}
				else if (mapa[pos - (1LL<<pot)])
				{
					while (last != -1 && last < pot)
					{
						resp.push_back(pos - (1LL<<last));
						last++;
					}
					last = -1, q++, pos = pos - (1LL<<pot);
					resp.push_back(pos);

				}
				else
				{
					if (last == -1) last = pot + 1;
				}
				pot++;
			}

			cout << resp.size() << endl;
			for (int x : resp) cout << x << ' ';
			cout << endl;
		}

		
	}

}





