#include <iostream> 
#define int long long
#define MOD (int) (1e9 + 7)

using namespace std;

int t, a, b;

int fexpo(int base, int e)
{
	int r = 1;
	while (e)
	{
		if (e&1) r = (r*base) % MOD;
		base = (base*base) % MOD;
		e >>= 1; // e/2
	}

	return r;
}

int32_t main()
{
	cin >> t;
	while (t--)
	{
		cin >> a >> b;
		cout << fexpo(a, b) << endl;	
	}
}
