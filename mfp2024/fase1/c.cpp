#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define MAXN (int) (1e6 + 10)
#define ii pair<int, int> 

using namespace std;

int n, arr[MAXN], memo[MAXN];

int f(int idx)
{
	if (idx >= (1<<n)) return 0;
	if (~memo[idx]) return memo[idx];
	return memo[idx] = max(f(2*idx), f(2*idx + 1)) + arr[idx];
}

int32_t main()
{
	cin >> n;
	for (int i = 1; i < (1<<n); i++) cin >> arr[i];

	memset(memo, -1, sizeof memo);
	cout << f(1) << endl;
}

