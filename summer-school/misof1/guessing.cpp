#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
#define MAXN (int) (1e6 + 10)
#define MAXK (int) (5e3 + 10)
#define int long long
#define MOD (int) (1e9 + 7)
#define max(a, b) (a>b?a:b)
#define SOMA (int) (5e3 + 10)

using namespace std;

int k, n;
double arr[MAXN], dp[MAXK][MAXK + SOMA]; 

double solve(int n)
{
	double resp = 0;
	dp[0][SOMA] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int pts = -n; pts <= n; pts++)
		{
			double cur = 0;
			cur = dp[i-1][pts-1 + SOMA]*arr[i]; //acerto
			cur = (cur + dp[i-1][pts+1 + SOMA]*(1-arr[i])); //erro
			dp[i][pts + SOMA] = cur;
		}

		double tmp = 0;
		for (int j = k; j <= n; j++)
			tmp += dp[i][j + SOMA];
		resp = max(resp, tmp);
	}
	
	return resp;
}
int32_t main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	sort(arr+1, arr+1+n, greater<double>());
	double r = solve(n);
	cout << fixed << setprecision(10) << r << endl;
}
