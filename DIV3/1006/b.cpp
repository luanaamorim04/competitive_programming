#include <bits/stdc++.h>
#define int long long
#define MAXN (int) (2e5 + 10)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int) (1e9 + 7)

using namespace std;

int t, n, psa[MAXN];
string s;

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> n >> s;
		int qtd = 0, last = -1;
		for (int i = 0; i < s.size(); i++)
		{
			qtd += (s[i] == '-');
		}

		cout << ((qtd+1)/2)*(qtd/2)*(s.size()-qtd) << endl;

	}
}
