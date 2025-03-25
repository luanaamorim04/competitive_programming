#include <bits/stdc++.h>
#define int long long
#define MAXN (int) (2e5 + 10)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int) (1e9 + 7)

using namespace std;

int t, n;

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	int nao[] = {1, 8, 49, 288, 1681, 9800, 57121, 332928};

	while (t--)
	{
		cin >> n;
		int ok = 1;
		for (auto x : nao) ok &= (n != x);
		if (!ok) 
		{
			cout << -1 << endl;
			continue;
		}

		int soma = 0;
		for (int i = 1; i <=n ; i++)
		{
			if (soma+i == (int)sqrt(soma+i)*(int)sqrt(soma+i)) soma = soma+i+i+1, cout << ++i << ' ' << i-1 << ' ';
			else soma += i, cout << i << ' ';
		}

		cout << endl;
	}
}
