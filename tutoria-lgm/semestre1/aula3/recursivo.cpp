#include <iostream> 
#define int long long
#define MOD (int) (1e9 + 7)

using namespace std;

int t, a, b;

int fexpo(int base, int e)
{
	if (e == 0) return 1;
	int resp = fexpo((base*base) % MOD, e>>1);
	if (e&1) return (base*resp) % MOD;
	return resp;
}

int32_t main()
{
	cin >> t;
	while (t--)
	{
		cin >> a >> b;
		cout << fexpo(a, b) % MOD << endl;	
	}
}
