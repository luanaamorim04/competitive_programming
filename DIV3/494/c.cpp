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
#define MAX (2e5)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

double resp;
int n, k, psa[1<<20];

int main()
{_
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> psa[i];
		psa[i] += psa[i - 1];
	}

	for (double j = k; j <= n; j++)
	{
		for (int i = j; i <= n; i++)
		{
			resp = max(resp, (psa[i]-psa[i-(int)j])/j);
		}
	}

	cout << fixed << setprecision(15) << resp << endl;
}












