#include <iostream>
#define MAXN (int) (2e5 + 10)
#define int long long

using namespace std;

int n, m, a[MAXN], b[MAXN];

int32_t main()
{
	cin >> n >> m;
	a[n+1] = 1e9 + 10;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	int l = 1, r = 0, resp = 0; 
	for (int i = 1; i <= m; i++)
	{
		cin >> b[i];
		while (a[r+1] <= b[i]) r++;
		while (a[l] < b[i]) l++;
		resp += max(0, r-l+1);
	}

	cout << resp << endl;
}
