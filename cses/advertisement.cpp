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

ll n, esq[1<<20], dir[1<<20], arr[1<<20], resp;

int main()
{_	
	cin >> n;
	arr[0] = arr[n + 1] = -1;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		esq[i] = i - 1;
		while (arr[i] <= arr[esq[i]]) esq[i] = esq[esq[i]];
	}

	for (int i = n; i >= 1; i--)
	{
		dir[i] = i + 1;
		while (arr[i] <= arr[dir[i]]) dir[i] = dir[dir[i]];
		resp = max(resp, arr[i]*(dir[i]-esq[i]-1));
	}

	cout << resp << endl;
}
