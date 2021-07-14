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

int n, arr[4], x, t;
double memo[301][301][301];

double f(int a0, int a1, int a2)
{
	if (a0 < 0 || a1 < 0 || a2 < 0) return 0;
	if (!a0 && !a1 && !a2) return 0;
	if (memo[a0][a1][a2] != -1) return memo[a0][a1][a2];
	double ans = ((a2*f(a0, a1 + 1, a2 - 1)) + (a1*f(a0 + 1, a1 - 1, a2)) + (a0*f(a0 - 1, a1, a2)));
	ans += n;
	ans /= (a0 + a1 + a2);
	return memo[a0][a1][a2] = ans;
}

int main()
{_	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		arr[x]++;
	}	

	for (int i = 0; i <= 300; i++)
		for (int j = 0; j <= 300; j++)
			for (int k = 0; k <= 300; k++)
				memo[i][j][k] = -1;

	cout << fixed << setprecision(12) << f(arr[1], arr[2], arr[3]) << endl;
}










