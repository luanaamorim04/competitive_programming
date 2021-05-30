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

ll n, resp[1<<20];

int main()
{_
	cin >> n;
	resp[1] = 0;
	resp[2] = 1;
	resp[3] = 2;
	for (int i = 4; i <= n; i++)
	{
		resp[i] = (resp[i-1]+resp[i-2])*(i-1) % MOD;
	}

	cout << resp[n] << endl;
}
