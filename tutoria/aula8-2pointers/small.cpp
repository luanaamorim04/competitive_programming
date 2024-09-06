#include <iostream>
#define MAXN (int) (2e5 + 10)
#define int long long

using namespace std;

int s, resp, n, m, a[MAXN], freq[MAXN];

void add(int x)
{
	s += !freq[x];
	freq[x]++;
}

void del(int x)
{
	s -= (freq[x] == 1);
	freq[x]--;
}

int32_t main()
{
	cin >> n >> m;
	a[n+1] = 1e9 + 10;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	int l = 1;
	for (int r = 1; r <= n; r++)
	{	
		add(a[r]);
		while (s > m) del(a[l]), l++;

		cout << l << ' ' << r << endl;
		resp += (r-l+1);
	}
	cout << resp << endl;
}

