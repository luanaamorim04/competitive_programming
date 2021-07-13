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
#include <bitset>
#define ll long long
#define INF (1e18)
#define MAX (int) (2e5 + 5)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define esq(x) (x<<1)
#define dir(x) ((x<<1)+1)
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll n, w, p[101], v[101], dp[100001];

int main()
{_
	cin >> n >> w;
	for (int i = 1; i <= 100000; i++) dp[i] = INF;

	for (int i = 0; i < n; i++)
		cin >> p[i] >> v[i];

	for (int i = 0; i < n; i++)
		for (int j = 100000; j >= v[i]; j--)
			dp[j] = min(dp[j], dp[j - v[i]] + p[i]);

	for (int i = 100000; i >= 0; i--)
		if (dp[i] <= w) 
		{
			cout << i << endl;
			return 0;
 		}
}




