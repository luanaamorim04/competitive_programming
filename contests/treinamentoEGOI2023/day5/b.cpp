#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>
#define int long long
#define all(x) x.begin(), x.end()
#define MAXN (int) (1e6 + 5)
#define INF 1e9 + 7

using namespace std;

int n, k, arr[MAXN], resp;
vector<tuple<int, int, int> > v;

int32_t main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({a, b, i});
	}

	v.push_back({INF, INF+1, 0});

	sort(all(v));
	int tot = 0;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > sair, entrar;
	pair<int, int> last;
	for (auto[l, r, idx] : v)
	{
		//cout << l << ' ' << r << endl;
		sair.push({r, l});
		while (sair.top().first <= l)
		{
			auto[r1, l1] = sair.top(); sair.pop();
			// printf("delete[%d, %d]\n", l1, r1);
			if (tot >= k && !entrar.empty() && l1 <= entrar.top().first)
			{
				// printf("update resp: [%d, %d]\n", entrar.top().first, r1);
				while (!entrar.empty() && entrar.top().second <= r1) entrar.pop();
				if (tot >= k)
				{
					if (resp < r1-entrar.top().first)
					{
						last = {l1, r1};
						resp = r1-entrar.top().first;
					}
				} 
			} 

			tot--;
		}

		tot++;
		if (tot >= k)
		{
			entrar.push({l, r});
		}
	}

	cout << resp << endl;
	v.pop_back();
	for (auto[l, r, idx] : v)
	{
		if (l <= last.second-resp && r >= last.second)
			cout << idx << ' ';
	}
	cout << endl;

}







