#include <iostream>
#define int long long
#define MOD (int) (1e9 +7)
#define MAXN 400

using namespace std;

int fat[MAXN], n, x, t;

int fexpo(int b, int e)
{
	int r = 1;
	while (e)
	{
		if (e&1) r = (r*b) % MOD;
		b = (b*b) % MOD;
		e>>=1;
	}

	return r;
}

int inv(int b)
{
	return fexpo(b, MOD-2);
}

int32_t main()
{
	fat[0] = 1;
	for (int i = 1; i < MAXN; i++)
		fat[i] = (fat[i-1]*i) % MOD;

	cin >> t;
	int a = inv(365);;
	while (t--)
	{
		cin >> n >> x;
		if (n-x >= MAXN) 
		{
			cout << 0 << endl;
			continue;
		}

		int ans = fexpo(a, n-1);
		for (int i = 365-n+x; i < 365; i++)
		{
			ans = (ans * (i % MOD)) % MOD;
		}

		int c = 1;
		for (int i = n; i > x; i--) c = (c * (i % MOD)) % MOD;

		c = (c * inv(fat[n-x])) % MOD;


		ans = (ans * c) % MOD;

		cout << ans << endl;


	}

}
