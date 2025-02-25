#include <iostream>
#include <queue>
#define MAXN (int) (2e5 + 10)
#define int long long
#define ii pair<int, int>

using namespace std;

int n, m, arr[MAXN];
priority_queue<ii> pq_max;
priority_queue<ii, vector<ii>, greater<ii> > pq_min;

int32_t main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	int resp = 0;
	int l = 1;
	for (int r = 1; r <= n; r++)
	{
		pq_max.push({arr[r], r});
		pq_min.push({arr[r], r});
		while (pq_max.top().second < l) pq_max.pop();
		while (pq_min.top().second < l) pq_min.pop();

		while ((pq_max.top().first - pq_min.top().first) > m)
		{
			l++;
			while (pq_max.top().second < l) pq_max.pop();
			while (pq_min.top().second < l) pq_min.pop();
		}

		resp += r-l+1;
	}

	cout << resp << endl;


}
