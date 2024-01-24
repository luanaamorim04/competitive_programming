#include <iostream>
#define MAXN (int) (1e5 + 10)

using namespace std;

int n, f[MAXN];

int32_t main()
{
	cin >> n;
	for (int i = n+1; i < MAXN; i++)
		f[i] = 1;
	for (int i = n; i >= 1; i--)
	{
		f[i] = (!f[2*i] || !f[i+1]);
	}

	for (int i = 1; i <= n; i++)
		cout << f[i] << ' ' << i << endl;
}
