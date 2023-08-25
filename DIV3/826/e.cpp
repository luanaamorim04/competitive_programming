//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define MAXN (int) (3e5 + 10)
#define MAXL 20
#define int long long
#define INF 1e9
#define all(x) x.begin(), x.end()
#define dbug(x) cout << #x << ": " << x << endl;

using namespace std;

int n, arr[MAXN], t, m, k, ini[MAXN][MAXL];

int solve(int idx)
{
	if (idx == n+1) return 1;
	if (idx > n+1) return 0;
	if (~memo[idx]) return memo[idx];

	return (solve(idx + arr[idx] + 1) | solve(pos[idx])); 
}


int32_t main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
		}

		for (int i = n; i >= 1; i--)
		{
			pos[]
		}

		cout << (solve(n) ? "YES" : "NO") << endl;
		
	}
	return 0;
}






