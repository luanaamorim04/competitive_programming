#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define INF (int) (1e18)
#define MAXN (1<<12)
#define par pair<int, int>
#define max(a, b) (a>b?a:b)

using namespace std;

int dp[MAXN][12], n, rx[12], ry[12], tam[12];
string s[12];

par pos[12]; 

int pode(int cur, int ax, int ay, int r, int tempo)
{
	int ciclo = (tempo+cur)/tam[r];
	int x = rx[r] + ciclo*(pos[r].first - rx[r]);
	int y = ry[r] + ciclo*(pos[r].second - ry[r]);
	int resp = INF;
	for (int i = 0; i < (cur+tempo)%tam[r]; i++)
	{
		x += (s[r][i] == 'R') - (s[r][i] == 'L');
		y += (s[r][i] == 'U') - (s[r][i] == 'D');
	}	

	return (max(abs(ax-x), abs(ay-y)) <= tempo);
}

int tempo(int cur, int a, int r)
{
	int x1, y1;
	if (!cur)
	{
		x1 = y1 = 0;
	}
	else
	{
		x1 = rx[a] + (cur/tam[a])*(pos[a].first - rx[a]);
		y1 = ry[a] + (cur/tam[a])*(pos[a].second - ry[a]);
		for (int i = 0; i < cur%tam[a]; i++)
		{
			x1 += (s[a][i] == 'R') - (s[a][i] == 'L');
			y1 += (s[a][i] == 'U') - (s[a][i] == 'D');
		}
	}
	
	int ini = 0, meio, fim = INF;
	while (ini <= fim)
	{
		meio = (ini+fim)>>1;
		if (pode(cur, x1, y1, r, meio)) fim = meio - 1;
		else ini = meio + 1;
	}
	
	return fim+1; 
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> rx[i];
	for (int i = 0; i < n; i++) cin >> ry[i];
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];	
		tam[i] = s[i].size();
		pos[i] = {rx[i], ry[i]};
		for (int j = 0; j < s[i].size(); j++)
			pos[i] = {pos[i].first + (s[i][j] == 'R') - (s[i][j] == 'L'), 
						   pos[i].second + (s[i][j] == 'U') - (s[i][j] == 'D')};
	}

	memset(dp, 63, sizeof dp);

	for (int i = 0; i < n; i++)
		dp[0][i] = tempo(0, 0, i);

	for (int mask = 0; mask < (1<<n); mask++) //dp[mask][i] menor caminho tendo visitado geral indo pro i
	{
		for (int i = 0; i < n; i++) //visitando
		{
			if (mask&(1<<i)) continue;
			for (int j = 0; j < n; j++) // ultimo
				if (mask&(1<<j)) dp[mask][i] = min(dp[mask][i], dp[mask^(1<<j)][j] + tempo(dp[mask^(1<<j)][j], j, i));
		}
	}

	int ans = INF;
	for (int i = 0; i < n; i++)
		ans = min(ans, dp[((1<<n)-1)^(1<<i)][i]);

	cout << (ans == INF || ans > (1e15) ? -1 : ans) << endl;
}
