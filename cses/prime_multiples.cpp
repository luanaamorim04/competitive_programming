#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring>
#define ll long long
#define INF 99999999
#define MAX 300000
#define MOD 1000000007
#define par pair<int, int>
#define all(v) (v.begin(), v.end())
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int k;
ll n, arr[22], ans;

void f(int idx, ll m, int x)
{
	if (m != 1) ans += (x ? -(n/m) : (n/m));
	for (int i = idx; i < k; i++) 
	{
		if (arr[i] <= ((double) n)/m) f(i + 1, m*arr[i], x^1);
		else if (arr[i] == ((double)n)/m) ans++;
	}
}

int main()
{_
	cin >> n >> k;
	for (int i = 0; i < k; i++) cin >> arr[i];
	f(0, 1LL, 1);
	cout << ans  << endl;
}











