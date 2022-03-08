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

struct Mouse
{
	int x, y, s;
};

int n;
Mouse mice[20];
double v, k, mult[20], dp[1<<15][15];

double tempo(int ax, int ay, int bx, int by, double v, int qnt)
{
	v *= mult[qnt];
	return hypot(ax-bx, ay-by)/v;
}

int pode(double v)
{
	for (int i = 0; i < (1<<n); i++)
		for (int j = 0; j < n; j++)
			dp[i][j] = 1e5;

	for (int i = 0; i < n; i++)
	{
		double tmp = tempo(0, 0, mice[i].x, mice[i].y, v, 0);
		if (mice[i].s < tmp) continue;
		dp[1<<i][i] = tmp;
	}

	for (int mask = 1; mask < (1<<n); mask++)
	{
		for (int last = 0; last < n; last++)
		{
			if (!(mask&(1<<last))) continue;
			for (int nxt = 0; nxt < n; nxt++)
			{
				if (mask&(1<<nxt)) continue;	
				double tmp = dp[mask][last] + tempo(mice[last].x, mice[last].y, mice[nxt].x, mice[nxt].y, v, __builtin_popcount(mask));
				if (tmp > mice[nxt].s) break;
				dp[mask|(1<<nxt)][nxt] = min(dp[mask|(1<<nxt)][nxt], tmp);
			}
		}
	}

	for (int i = 0; i < n; i++)
		if (dp[(1<<n)-1][i] != 1e5) return 1;
	return 0;
}

int main()
{_
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> mice[i].x >> mice[i].y >> mice[i].s;	
	cin >> k;
	mult[0] = 1;
	for (int i = 1; i < n; i++)
		mult[i] = mult[i-1]*k;

	double ini = 0, meio, fim = (1LL<<60);
	int qnt = 100;
	while (qnt--)
	{
		meio = (fim+ini)/2;
		if (pode(meio)) fim = meio;
		else ini = meio;
	}

	cout << fixed << setprecision(6) << meio << endl;
}









