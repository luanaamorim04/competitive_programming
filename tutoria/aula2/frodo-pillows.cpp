#include <iostream>
#define int long long

using namespace std;

int n, m, k;

int pode(int q)
{
	if (q < k || q < n-k+1) return 0;
	int pref = (q*(q+1))/2 - ((q-k)*(q-k+1))/2;
	int suff = (q*(q+1))/2 - ((q-(n-k+1))*(q-(n-k+1)+1))/2;
	cout << pref << ' ' << suff << endl;

	return pref+suff-q <= m;
}

int32_t main()
{
	cin >> n >> m >> k;
	int ini = max(k, n-k+1), meio, fim = m;
	while (ini <= fim)
	{
		meio = (ini+fim)/2;
		if (pode(meio)) ini = meio + 1;
		else fim = meio - 1;
	}

	cout << ini - 1 << endl;

	cout << pode(1) << endl;
}
