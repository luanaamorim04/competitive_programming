#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#define MAXN (int)(1e3 + 4)
#define all(x) x.begin(), x.end()
#define MAXK 204
#define sz(x) (int)x.first.size()

using namespace std;

int n, k, t;
pair<string, int> s[MAXN];
string code, dp[2][MAXK][2], inf;

int main()
{
	cin >> n >> k;
	for (t = 0; t < n; t++)
	{
		cin >> s[t].first;
		s[t].second = t;
		inf += '}';
		code += '0';
	}

	sort(s, s+n);
	vector<string> resp(n);
	char last = '}';
	for (t = 0; t < n; t++)
	{
		if (t && s[t].first == s[t-1].first) 
		{
			resp[s[t].second] = resp[s[t-1].second];
			continue;
		}	

		for (int i = 0; i < 2; i++)
			for (int j = 0; j < k; j++)
			{
				dp[i][j][0] = dp[i][j][1] = inf;
				dp[i][0][0] = "";
			} 				

		if (s[t].first[0] > code[0]) dp[0][0][1] = "";
		for (int idx = 1; idx < sz(s[t]); idx++)
		{
			int i = (idx&1);
			for (int tam = 1; tam < k; tam++)
			{
				dp[i][tam][0] = dp[i^1][tam][0];
				if (s[t].first[idx] == code[tam]) 
					dp[i][tam][0] = min(dp[i^1][tam][0], dp[i^1][tam-1][0] + s[t].first[idx]);

				dp[i][tam][1] = min(dp[i^1][tam][1], dp[i^1][tam-1][1] + s[t].first[idx]);
				if (s[t].first[idx] > code[tam]) 
					dp[i][tam][1] = min(dp[i][tam][1], dp[i^1][tam-1][0] + s[t].first[idx]);

				// dp[idx][tam][0] = min(dp[idx][tam][0], dp[idx][tam][1]);

				// printf("dp[%d][%d][0]: ", idx, tam);
				// cout << dp[i][tam][0] << endl;
				// printf("dp[%d][%d][1]: ", idx, tam);
				// cout << dp[i][tam][1] << endl;

			}

			// cout << endl;
		}

		string curr = dp[(sz(s[t])-1)&1][k-1][1];
		code = s[t].first[0] + curr;

		if (curr == inf)
		{
			cout << "NO" << endl;
			return 0;
		}

		resp[s[t].second] = code;
	}

	cout << "YES" << endl;
	for (string c : resp) cout << c << endl;
}