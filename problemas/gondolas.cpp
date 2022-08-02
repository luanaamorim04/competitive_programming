#include <bits/stdc++.h>
#define dbug(x) cout << (#x) << " -> " << x << endl
#define ll long long
#define INF (1e9)
#define MAX (int) (4e3 + 5)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define sz(x) (int) ((x).size())
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define lsb(x) (x & -x)
#define W(x) cout << #x << ": " << x << endl
#define Wii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define _CRT_SECURE_NO_WARNINGS

#define gc getchar

using namespace std;

void scanint(int &x){
    register int ccc = gc(); x = 0;
    for(;((ccc<48 || ccc>57));ccc = gc());
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
}

int n, k, m[MAX][MAX], custo[MAX][MAX], dp[MAX][MAX];

int solve(int l, int r, int i, int t)
{
	// if (l == r == i) return 0; 
	int resp = 0;
	dp[t][i] = INF;
	for (int j = l; j <= min(r, i); j++)
		if (dp[t][i] > dp[t-1][j-1] + m[j][i]) dp[t][i] = dp[t-1][j-1] + m[j][i], resp = j;

	return resp;
}

void divide(int i, int j, int opt1, int opt2, int t)
{
	if (i>j) return;
	int mid = (i+j)>>1;
	int optmid = solve(opt1, opt2, mid, t);      
	divide(i, mid-1, opt1, optmid, t);
	divide(mid+1, j, optmid, opt2, t);                                                                                                                                            
}

int main()
{
	scanint(n);
	scanint(k);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanint(m[i][j]);
			// m[i][j] = !(i==j);
			custo[i][j] = custo[i-1][j] + custo[i][j-1] + m[i][j] - custo[i-1][j-1];
		}
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			m[i][j] = (custo[j][j] + custo[i-1][i-1] - custo[j][i-1] - custo[i-1][j])>>1;

	for (int i = 1; i <= n; i++) dp[0][i] = INF;
	for (int t = 1; t <= k; t++)
		divide(1, n, 1, n, t);

	cout << dp[k][n] << endl;
}	











