#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#define MAXN (int)(3e5 + 10)
#define INF 1e17
#define int long long
#define all(x) x.begin(), x.end()

using namespace std;

int t, n, pref[MAXN], suff[MAXN], psa[MAXN];

int pa(int a1, int k)
{
	int an = a1 + ((k-1)*-1);
	return ((a1 + an)*k)>>1;
}

vector<int> solve(vector<int> arr, int n)
{
	vector<int> resp(n+2);
	arr[0] = arr[n+1] = -INF;
	for (int i = 1; i <= n; i++)
	{
		arr[i] += (n-i);
		pref[i] = i-1;
		while (arr[pref[i]] >= arr[i]) pref[i] = pref[pref[i]]; 
	}

	arr[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		arr[i] -= (n-i);
		psa[i] = psa[i-1] + arr[i];
		int p = pref[i];
		resp[i] = (psa[i]-psa[p]) - pa(arr[i], min(arr[i], abs(i-p))) + resp[p];
		// printf("PA(%lld, %lld) = %lld\n", arr[i], (i-p), pa(arr[i], (i-p)));
	}
	return resp;
}

int32_t main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		vector<int> arr(n+2);
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
			suff[i] = pref[i] = psa[i] = 0;
		} 

		vector<int> r1 = solve(arr, n);
		reverse(all(arr));
		vector<int> r2 = solve(arr, n);
	
		int resp = INF;
		for (int i = 1; i <= n; i++)
			resp = min(resp, r1[i]+r2[n-i+1]+arr[n-i+1]);

		cout << resp << endl;
	}
}