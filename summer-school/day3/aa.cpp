#include <iostream>
#define MAXN (int) (1e5 + 10)

using namespace std;

int n, f[MAXN], ini, lose, last;

int game(int l, int r, int ini)
{
	if (r&1)
	{
		return !((ini+l)&1);
	}


	int win = 0, padrao = 1, mid = r/2;
	while (r > l)
	{
		mid = r/2;
		if ((mid&1) && win && !padrao) //foi o maximo possivel 
		{
			return !((ini+l)&1);
		}

		win ^= 1;
		r /= 2;	
		padrao ^= 1;
	}

	if (!padrao) return (win^ini);
	else return ()


	return (win^ini);
}

int32_t main()
{
	cin >> n;
	ini = 1;
	while (n--)
	{
		cin >> l >> r;
		if (!game(l, r, ini)) ini = 1;
		else ini = 0;	
	}



	for (int i = n+1; i < MAXN; i++)
		f[i] = 1;
	for (int i = n; i >= 1; i--)
	{
		f[i] = (!f[2*i] || !f[i+1]);
	}

	for (int i = 1; i <= n; i++)
		cout << f[i] << ' ' << i << endl;
}
