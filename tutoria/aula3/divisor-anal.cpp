#include <iostream> 

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

int32_t main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i];
		num = (num*fexpo(a[i], b[i])) % MOD;
	}

	cout << num << ' '

}
