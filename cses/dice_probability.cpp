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
#define INF (1e9)
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

double memo[601][101], a, b, n;

double f(ll sum, int idx)
{
	if (memo[sum][idx] != -1) return memo[sum][idx];
	if (idx == n) return sum >= a && sum <= b;
	double ans = 0;
	for (int i = 1; i <= 6; i++)
		ans += f(sum + i, idx+1);

	return memo[sum][idx] = (ans/6);
}

int main()
{_
	cin >> n >> a >> b;
	for (int i = 0; i < 601; i++) for (int j = 0; j < 101; j++) memo[i][j] = -1;
	cout << fixed << setprecision(6) << f(0, 0) << endl;
}










