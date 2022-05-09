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
#define MAX (int) (2e5 + 5)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

priority_queue<par, vector<par>, greater<par> > pq;
int t, n, m, k, h[1<<20], resp[1<<20], idx, menor, maior;

int main()
{_
	cin >> t;
	while (t--)
	{
		cin >> n >> m >> k;
		idx = 0;
		vector<par> v;
		for (int i = 0; i < n; i++)
		{
			cin >> h[i];
			v.push_back({h[i], i});
		}

		while (m--)
			pq.push({0, ++idx});

		sort(all(v));

		for (int i = n-1; i >= 0; i--)
		{
			par k = pq.top(); pq.pop();
			pq.push({k.first + v[i].first, k.second});
			resp[v[i].second] = k.second;
		}

		menor = pq.top().first;

		while (!pq.empty())
		{
			maior = pq.top().first; pq.pop();
		}

		if (maior > menor + k) 
		{
			cout << "NO" << endl;
			continue;
		}

		cout << "YES" << endl;
		for (int i = 0; i < n; i++)
		{
			cout << resp[i] << ' ';
		}
		cout << endl;
	}
}














