#include <bits/stdc++.h>
#define int long long
#define MAXN (int) (1e6 + 10)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int) (1e9 + 7)
#define BASE 37
#define MAXL 20
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

int t, n, m, k;

int pode(int maior)
{
	int linha = (m-maior)/(maior+1) + 1;
	int sobra = max(0ll, m - linha*maior - linha);
//	cout << maior << ' ' << linha << ' ' << sobra << endl;//n*(linha*maior + sobra) << endl;
	return (n*(linha*maior + sobra) >= k);
}

int32_t main()
{_
	cin >> t;
	while (t--)
	{
		cin >> n >> m >> k;
		int ini = 1, meio, fim = m; 
		while (ini <= fim)
		{
			meio = (ini+fim)/2;
			if (pode(meio)) fim = meio - 1;
			else ini = meio + 1;
		}
		cout << fim + 1 << endl;
	}
}	
