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
#define MAX (int) (2e3 + 5)
#define MOD 1000000007
#define par pair<double, int>
#define all(v) v.begin(), v.end()
#define sz(x) (int) ((x).size())
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define lsb(x) (x & -x)
#define W(x) cout << #x << ": " << x << endl
#define Wii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int a, k, n;
double a1[MAX], a2[MAX];
par dp[MAX][MAX];

par bottom_up(double c)
{
	par p1, p2, p3, p4;
	for (int i = 0; i <= a; i++) dp[n+1][i] = {0, 0};
	for (int i = n; i >= 1; i--)
	{
		p1 = dp[i+1][0];
		p3 = {p1.first + a2[i] - c, p1.second - 1};
		dp[i][0] = max(p1, p3);

		for (int j = 1; j <= a; j++)
		{
			p1 = dp[i+1][j];
			p2 = dp[i+1][j-1];
			p4 = {p2.first + 1 - ((1-a1[i])*(1-a2[i])) - c, p2.second - 1};
			p3 = {p1.first + a2[i] - c, p1.second - 1};
			p2 = {p2.first + a1[i], p2.second};
			dp[i][j] = max(max(p1, p2), max(p3, p4));
		}
	}

	return dp[1][a];
}

int main()
{_
	cin >> n >> a >> k;
	for (int i = 1; i <= n; i++) cin >> a1[i];
	for (int i = 1; i <= n; i++) cin >> a2[i];

	double ini = 0, meio, fim = MAX;
	int qnt = 60;
	while (qnt--)
	{
		meio = (fim+ini)/2;
		if (-bottom_up(meio).second <= k) fim = meio;
		else ini = meio;
	}


	cout << fixed << setprecision(6) << bottom_up(meio).first + (k*meio) << endl;
}











