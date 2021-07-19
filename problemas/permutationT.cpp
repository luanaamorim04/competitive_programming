#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring>
#include <set>
#include <stack>
#include <bitset>
#define ll long long
#define INF (1e9)
#define MAX (int) (2e5 + 5)
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

using namespace std;

int n;
string s;
ll dp[3010][3010], resp, psa[3010][3010];

int main()
{_
	cin >> n >> s;
	for (int i = 1; i <= n; i++) dp[n][i] = 1, psa[n][i] = (psa[n][i-1] + dp[n][i]) % MOD;

	for (int tam = n-1; tam >= 1; tam--)
	{
		for (int val = 1; val <= tam + 1; val++)
		{
			if (s[tam-1] == '<')
				dp[tam][val] = (psa[tam+1][tam+1] - psa[tam+1][val] + MOD) % MOD;
			else
				dp[tam][val] = psa[tam+1][val];

			psa[tam][val] = (psa[tam][val-1] + dp[tam][val]) % MOD;
		}
	}
	cout << dp[1][1] << endl;
}











