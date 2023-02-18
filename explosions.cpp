#include <iostream>
#define MAXN (int)(3e5 + 10)
#define int long long

using namespace std;

int t, n, arr[MAXN], psa[MAXN];

int f(int pwr, int range)
{

}

int32_t main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
			psa[i] = psa[i-1] + arr[i];
		}

		int resp = 0;
		for (int i = 1; i <= n; i++)
		{
			int ini = 1, meio, fim = arr[i];
			while (ini <= fim)
			{
				meio = (ini+fim)>>1;
				if (f(i, meio)) ini = meio + 1;
				else fim = meio - 1;
			}

			resp = max(resp, ini - 1);
		}

		cout << resp << endl;
	}
}