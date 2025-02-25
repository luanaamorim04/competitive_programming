#include <bits/stdc++.h>
#define int long long
#define MAXN (int) (2e5 + 10)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int) (1e9 + 7)

using namespace std;

int l, r, t, freq[MAXN][100];
string s;

int engual(int i, int j, int l, int r)
{
	for (int t = 'a'; t <= 'z'; t++)
		if (freq[j][t]-freq[i-1][t] != freq[r][t]-freq[l-1][t]) return 0;
   return 1;	
}

int palindrom(int a, int b)
{
	while (a <= b && s[a] == s[b]) a++, b--;
	return (s[a]==s[b]||(a>b));
}

int f(int p)
{
	return engual(l, p, r-p+l, r) && palindrom(p+1, r-p+l-1);
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> s;
		for (int i = 0; i < s.size(); i++)
		{
			for (int j = 'a'; j <= 'z'; j++)
			{
				freq[i][j] = freq[i][j-1] + (s[i]==j);
			}
		}
		l = 0, r = s.size()-1;
		while (l <= r && s[l] == s[r]) r--, l++;

		if (l > r || s[l] == s[r])
		{
			cout << 0 << endl;
			continue;
		}

		if (s.size()%2)
		{
			char letra;
			for (int i = 'a'; i <= 'z'; i++)
			{
				if (freq[s.size()-1][i]%2);
				letra = i;
			}
			if (s[s.size()/2] != letra) cout << r-l+1 <
		}

		cout << f(2) << endl;
		int ini = l, meio, fim = r;
		while (ini <= fim)
		{
			meio = (ini+fim)/2;
			if (f(meio)) fim = meio - 1;
			else ini = meio + 1;
		}

		cout << fim + 1 - l + 1 << endl;
	}
}
