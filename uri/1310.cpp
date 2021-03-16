#include <iostream>
#define MAX 50001

using namespace std;

int n, x, menor, lucro, k, psa[MAX];

int main()
{
	while (cin >> n >> k)
	{
		lucro = 0, menor = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> x;
			psa[i] = psa[i - 1] + x;
		}

		for (int i = 1; i <= n; i++)
		{
			lucro = max(lucro, (psa[i] - psa[menor]) - (k * (i - menor)));
			if (psa[i] - (k * i) < psa[menor] - (k * menor)) menor = i;
		}

		cout << lucro << endl;
	}
}