#include <iostream>
#define MAXN (int) (1e6 + 10)
#define MAXK (int) (5e3 + 10)
#define int long long
#define MOD (int) (1e9 + 7)

using namespace std;

int n, k, psa[MAXK], arr[MAXK], resp[MAXK], fat[MAXN];

int32_t main()
{
	fat[0] = 1;
	for (int i = 1; i < MAXN; i++)
		fat[i] = (fat[i-1]*i) % MOD;
	cin >> n >> k;
	for (int i = 1; i <= k; i++)
	{
		cin >> arr[i];
		psa[i] = (psa[i-1] + arr[i]);
		resp[i] = (fat[n-psa[i]]*fat[psa[i]]) % MOD;
		for (int j = 1; j < i; j++)
		{
			resp[i] = (resp[i] - (fat[n-psa[i]]*((fat[psa[j]]*fat[psa[i] - psa[j]]) % MOD) % MOD) + MOD) % MOD;
		}
	}

	int ans = fat[n];
	for (int i = 1; i <= k; i++)
		ans = (ans - resp[i] + MOD) % MOD;
	cout << ans << endl;
}
