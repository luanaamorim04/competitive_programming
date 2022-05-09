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
#define MAX (int) (1e5 + 5)
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

int n, m, dp[MAX], a, b, psa[MAX];

int main()
{_	
	cin >> n >> m;
	for (int i = 0; i <= m; i++) dp[i] = 1;

	for (int idx = 1; idx <= n; idx++) 
	{
		cin >> a >> b;
		for (int soma = 1; soma <= m; soma++)
			psa[soma] = (psa[soma-1] + dp[soma]) % MOD, dp[soma] = 0;

		dp[0] = 0;
		for (int soma = 0; soma+a <= m; soma++)
			dp[soma] = (psa[min(m, soma+b)] - psa[(soma+a)-1] + MOD) % MOD;
	}

	cout << dp[0] << endl;
}












