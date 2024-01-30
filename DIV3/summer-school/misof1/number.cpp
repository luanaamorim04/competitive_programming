#include <iostream>
#define MAXN (int) (1e6 + 10)
#define MAXK (int) (5e3 + 10)
#define int long long
#define MOD (int) (1e9 + 7)
#define max(a, b) (a>b?a:b)

using namespace std;

int n, k, psa[MAXK], arr[MAXK], resp[MAXK], fat[MAXN];

int32_t main()
{
	cin >> n;
	int resp = 0;
	for (int dig = 1; dig <= 9; dig++)
	{
		int casa = 1, num = 0;
		for (int rep = 0; rep <= 10; rep++)
		{
			num += dig*casa;
			if (num > n) break;
			resp++;
			casa *= 10;
		}
	}
	
	int d = 0;
	while (n)
	{
		d++;
		n/=10;
	}

	cout << resp + max(d-1, 1) << endl;
}
