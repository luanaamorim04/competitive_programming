#include <iostream>
#include <vector> 
#include <queue> 
#define MAXN (int) (2e3 + 10)
#define int long long
#define MOD (int) (1e9 + 7)
#define INF (int) (1e9)
#define ii pair<int, int> 

using namespace std;

int n, m, k, l, arr[MAXN], freq[MAXN];
ii dp[MAXN], resp[MAXN], last[MAXN];

//dp[i][x] = prob de ir pro i+x

ii soma(ii a, ii b)
{
	if (a.second == 0 || a.first == 0) return b;
	if (b.second == 0 || b.first == 0) return a;
	return {(a.first*b.second + b.first*a.second) % MOD, (a.second*b.second) % MOD};
}

ii mult(ii a, ii b)
{
	return {(a.first*b.first)%MOD, (a.second*b.second)%MOD};
}

int fexpo(int b, int e = MOD-2)
{
	int r = 1;
	while (e)
	{
		if (e&1) r = (r*b) % MOD;
		b = (b*b) % MOD;
		e>>=1;
	}

	return r;
}

int32_t main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> k >> l;
	for (int i = 0; i < k; i++)
	{
		cin >> arr[i];
		resp[arr[i]] = dp[arr[i]] = {1, 2*k};
		resp[(n-arr[i])%n] = dp[(-arr[i]+n)%n] = {1, 2*k};
	}

	--m;

	while (m)
	{
		if (m&1)
		{
			for (int i =0; i < n; i++)
				last[i] = resp[i], resp[i] = {0, 0};
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					resp[(i+j)%n] = soma(resp[(i+j)%n], mult(last[i],dp[j]));
		}

		for (int i = 0; i < n; i++)
			last[i] = dp[i], dp[i] = {0, 0};

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				dp[(i+j)%n] = soma(dp[(i+j)%n], mult(last[i],last[j]));
			}
		m>>=1;
	}

	ii ans = {0, 0};
	for (int i = 0; i < l; i++)
	{
		cin >> arr[i];
		ans = soma(ans, resp[arr[i]]);
	}

	cout << (ans.first*fexpo(ans.second)) % MOD << endl;
}
