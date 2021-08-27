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

int n, k, arr[205], x, y, rev, dp[2][1100][1100];

int main()
{_
	cin >> n >> k;
	rev = (1<<k) - 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		while (x--)
		{
			cin >> y;
			arr[i] |= (1<<(y-1));
		}
	}

	for (int sim = 0; sim < (1<<k); sim++)
		for (int nao = 0; nao < (1<<k); nao++)
			dp[(n+1)&1][sim][nao] = INF;

	dp[(n+1)&1][rev][rev] = 0;
	for (int i = n; i >= 1; i--)
		for (int sim = 0; sim < (1<<k); sim++)
			for (int nao = 0; nao < (1<<k); nao++)
				dp[i&1][sim][nao] = min(dp[(i+1)&1][sim][nao], dp[(i+1)&1][sim|arr[i]][nao|(arr[i]^rev)] + 1);

	cout << (dp[1][0][0]==INF?-1:dp[1][0][0]) << endl;
}













