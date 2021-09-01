#include <iostream>
#include <queue>
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
#define INF (1e10)
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

ll n, l, r, arr[MAX], resp, a, b;

int main()
{_
	cin >> n >> l >> r;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	a = -1, b = -1;
	if (arr[1] >= l) a = 1;
	sort(arr+1, arr+1+n);
	arr[n+1] = INF, arr[0] = -INF;
	for (int i = 2; i <= n; i++)
	{
		ll pos = (arr[i-1]+arr[i])/2;
		pos = min(pos, r);
		pos = max(pos, l);
		if (arr[i-1] <= pos && pos <= arr[i])
			resp = max(resp, min(abs(arr[i]-pos), abs(pos-arr[i-1])));
		if (arr[i] >= l && a < 0) a = i;
		if (arr[i] <= r) b = i;
	}

	if (~b) resp = max(resp, min(r-arr[b], arr[b+1]-r));
	if (~a) resp = max(resp, min(arr[a]-l, l-arr[a-1]));
	cout << resp << endl;
}










