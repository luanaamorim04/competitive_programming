#include <iostream>
#include <set>
#include <vector>
#define MAXN (int) (2e5 + 10)
#define INF 1e9

using namespace std;

int t, n, m, arr[MAXN], freq[MAXN], l;
multiset<int> cj;
vector<int> d[MAXN];

int pode(int maior)
{
	multiset<int> cj;
	int l = 1, dif = 0;
	for (int r = 1; r <= n; r++)
	{	
		cj.insert(arr[r]);
		while (cj.rbegin() - cj.begin() > maior)
		{
			cj.erase(arr[l]);
			l++;
		}
	}
}

int32_t main()
{
	for (int i = 2; i < MAXN; i++)
	{
		for (int j = i; j < MAXN; j += i)
		{
			d[j].push_back(i);
		}
	}


	// for (int i = 2; i < MAXN; i++)
	// {
	// 	cout << i << ": ";
	// 	for (int j : d[i])
	// 		cout << j << ' ';
	// 	cout << endl;
	// }


	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
			freq[arr[i]] = 0;
		}

		int resp = INF, count = 0;
		l = 1;
		for (int r = 1; r <= n; r++)
		{
			for (auto div : d[arr[r]])
			{
				if (freq[div] == 0) count++;
				freq[div]++;
			}
			cj.insert(arr[r]);

			while (count == m)
			{
				for (auto div : d[arr[l]])
					freq[div]--;
				
				cj.erase(arr[l]);
				l++;
			}

			resp = min(resp, *cj.rbegin() - *cj.begin());
		}

		cout << resp << endl;
	}
}




