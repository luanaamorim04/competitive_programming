#include <iostream>
#include <vector>
#include <queue>
#define int unsigned long long
#define MAXN (int) (2e5 + 10)
#define INF (int) (1e9)

using namespace std;

int t, n, tot, a, b, c, arr[MAXN], soma;

int f(int chute)
{
	return chute*a + b;
}

int32_t main()
{
	cin >> t;
	while (t--)
	{
		cin >> n >> tot;
		b = 0;
		soma = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
			soma += (arr[i]*arr[i]);
			b += arr[i];
		}

		a = n*4;
		b *= 4;

		int ini = 1, meio, fim = INF;
		while (ini <= fim)
		{
			meio = (ini+fim)/2;
			if (f(meio) <= (tot - soma)/meio) ini = meio + 1;
			else fim = meio - 1; 
		}

		cout << ini - 1 << endl;
		// cout << f(ini - 1) << endl;
	}
}