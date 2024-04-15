#include <iostream>
#include <bits/stdc++.h>
#define INF 1e18
#define int long long
#define MAXN (int) (1e6 + 10)
#define ii pair<int, int> 

using namespace std;

int n, arr[MAXN], m;

int pode(int tempo)
{
	int q = 0;
	for (int i = 0; i < n; i++)
		q += (tempo/arr[i]);

	return q >= m;
}

int32_t main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int ini = 0, meio, fim = INF;
	while (ini <= fim)
	{
		meio = (ini+fim)/2;
		if (pode(meio)) fim = meio - 1;
		else ini = meio + 1;
	}

	cout << fim + 1 << endl;


}




