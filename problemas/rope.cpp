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

double k, n, arr[MAX];

double p(double t)
{
	double resp = 0;
	for (int i = 0; i < n; i++)
		resp += (int)(arr[i]/t);
	return resp >= k;
}

double solve()
{
	double ini = 0, meio, fim = 1e7;
	int cnt = 100;
	while (cnt--)
	{
		meio = ((ini+fim)/2);
		if (p(meio)) ini = meio;
		else fim = meio;
	}

	return meio;
}

int main()
{_
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << fixed << setprecision(8) << solve() << endl;
}












