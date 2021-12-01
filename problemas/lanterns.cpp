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

int n, k, arr[MAX], t;

double p(double t)
{
	double last = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] - t > last) return 0;
		last = arr[i] + t;
	}
	return last>=k;
}

double solve()
{
	double ini = 0, meio, fim = 1e9;
	int cnt = 100;
	while (cnt--)
	{
		meio = ((ini+fim)/2);
		if (p(meio)) fim = meio;
		else ini = meio;
	}

	return meio;
}

int main()
{_
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr+n);

	cout << fixed << setprecision(10) << solve() << endl;
}














