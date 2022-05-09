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
#define MAX (int) (2e6 + 5)
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

int n, dp[MAX];

int main()
{_
	cin >> n;
	for (int i = 1; i <= n; i++) dp[i] = INF;

	for (int i = 1; i <= n; i++)
	{
		for (int k = 1; k <= i; k*=6)
			dp[i] = min(dp[i], dp[i-k] + 1);

		for (int k = 1; k <= i; k*=9)
			dp[i] = min(dp[i], dp[i-k] + 1);
	}

	cout << dp[n] << endl;
}











