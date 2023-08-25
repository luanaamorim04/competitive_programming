//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define MAXN (int) (2e5 + 10)
#define int long long
#define INF 1e9
#define all(x) x.begin(), x.end()
#define dbug(x) cout << #x << ": " << x << endl;

using namespace std;

int n, arr[MAXN], t, m, k;

int maior(int soma)
{
	int r = 0, last = 0, now = 0;
	for (int i = 1; i <= n; i++)
	{
		now += arr[i];
		if (now == soma)
		{
			r = max(r, i-last);
			now = 0;
			last = i;
		}
		if (now > soma) return INF;
	}
	return r;
}

int32_t main()
{
	cin >> t;
	while (t--)
	{
		int soma = 0, resp = INF;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
			soma += arr[i];
		}

		for (int i = 1; i*i <= soma; i++) // 2000 * 50000 = 10**8
		{
			if (soma%i == 0)
			{
				resp = min(resp, maior(i));
				resp = min(resp, maior(soma/i));
			}
		}

		
		cout << resp << endl;
		
	}
	return 0;
}






