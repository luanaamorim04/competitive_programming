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
#define dbug(x) cout << (#x) << " -> " << x << endl
#define ll long long
#define INF (1e9)
#define MAX (int) (3e3) + 5
#define MAXN (int) (1<<15) + 5
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

ll dp[MAX][MAXN], n, arr[MAX], resp, maior;

int main()
{_
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		if (arr[i] >= (1<<15)) maior ^= arr[i], arr[i] = 0;
	}

	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < MAXN; j++)
		{
			dp[i][j] = (dp[i-1][j] | dp[i-1][j^arr[i]]);
		}
	}

	for (ll i = 0; i < (1<<15); i++)
	{
		if (dp[n][i])
		{
			resp = max(resp, maior^i);
		}
	}

	cout << resp << endl;
}	
