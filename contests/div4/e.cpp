#include <iostream>
#include <vector>
#include <math.h>
#include <set>
#include <map>
//#include <bits/stdc++.h>
#define MAXN (int) (2e5 + 10)
#define int long long
#define all(x) x.begin(), x.end()
#define ii pair<int, int> 
#define INF (int) (1e9)
#define MOD (int) (1e9 + 7)
#define iii tuple<int, int, int> 
#define BASE 37

using namespace std;

int t, n, e[MAXN], h[MAXN];
string s;

int solve(int tam)
{
	int cur;
	int hash = h[tam-1];
	int q = n-1-(tam-1);
	int hash1 = ((h[second] - h[second-tam] + mod)*e[q-(n-second-1)]) % mod;
	int cnt = 0, cnt1 = 0;
	for (int i = 2*tam-1; i < n; i += tam)
	{
		cur = ((h[i] - h[i-tam] + mod)*e[q-(n-i-1)]) % mod; 
		if (cur != hash && cnt && cur != hash1 && cnt1) return 0;
		if (cur != hash && !cnt)
		{
			int i2 = 0;
			for (int idx = i-tam+1; idx <= i; idx++)
				cnt += (s[idx] != s[i2++]);
		}
		if (cur != hash1 && !cnt1)
		{
			int i2 = 0;
			for (int idx = i-tam+1; idx <= i; idx++)
				cnt += (s[idx] != s[(i2++) + tam]);
		}
	}

	return 1;
}



int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(null);
	cin >> t;
	while (t--)
	{
		cin >> n >> s;
		e[0] = 1;
		for (int i = 1; i < maxn; i++)
			e[i] = (e[i-1]*base) % mod;
		h[0] = (s[0]-'a'+1)*e[n-1];
		for (int i = 1; i < n; i++)
			h[i] = (h[i-1] + (s[i]-'a'+1)*e[n-1-i]) % mod;


		int resp = n;
		for (int i = 1; i*i <= n; i++)
		{
			if (n%i == 0)
			{
				if (solve(i)) resp = min(resp, i);
				if (solve(n/i)) resp = min(resp, n/i);
			}
		}

		cout << resp << endl;
	}
}	
