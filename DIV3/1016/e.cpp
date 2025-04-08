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

int t, n, arr[MAXN], k;

int pode(int m, vector<vector<int> > &pos)
{
	int q = 0, mex = -1, last = 0, prox = 1;
	if (m == 0) return pos[0].size() >= k;
	for (int i = 1; i <= n; i = prox)
	{
		//cout << i << ' ' << mex << endl;
		if (mex >= m)
		{
			prox = i+1;
			last = i+1;
			mex = -1;
			q++;
		}
		else
		{
			if (lower_bound(all(pos[mex+1]), last) == pos[mex+1].end())
			{
				break;
			}
			prox = max(prox, pos[mex+1][lower_bound(all(pos[mex+1]), last) - pos[mex+1].begin()]);
			mex++;
		}
	}

	return q >= k;
}

int32_t main()
{_
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		vector<vector<int> >pos(2*n);
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
			if (arr[i] > n+1) continue;
			pos[arr[i]].push_back(i);
		}

		int ini = 0, meio, fim = n;
		while (ini <= fim)
		{
			meio = (ini+fim)/2;
			if (pode(meio, pos)) ini = meio + 1;
			else fim = meio - 1;
		}

		cout << ini << endl;
	}
}
