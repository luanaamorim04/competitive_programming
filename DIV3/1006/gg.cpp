#include <bits/stdc++.h>
#define int long long
#define MAXN (int) (2e5 + 10)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int) (1e9 + 7)

using namespace std;

int t, n, k;

int quad(int i)
{
//	return ((i*(i+1) % MOD)*(2*i + 1) % MOD)*inv(6) % MOD;
	return (i*(i+1)*(2*i + 1))/6;
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		int resp = 0, last = 1;
		for (int b = 2; b*b <= n && b <= k; b++) //menores que raiz
		{
			int x = n, num = 0;
			while (x)
			{
				num = (num*b + (x%b)) % MOD;
				x /= b;
			}

			resp = (resp + num) % MOD;
			last = b;
		}

		if (k < n && k*k <= n) 
		{
			cout << resp << endl;
			continue;
		}

		//maior que raiz e menor que n
		//brute all n/i... and find all [l, r] 
		//resp = in + n/i - (i**2)(n/i)
		for (int res = 1; res*res <= n; res++)
		{
			int l, r, ini = last+1, meio, fim = n-1;
			while (ini <= fim)
			{
				meio = (ini+fim)/2;
				if (n/meio <= res) fim = meio - 1;
				else ini = meio + 1;
			}
			l = min(k, fim+1);
			ini = 1, fim = n-1;
			while (ini <= fim)
			{
				meio = (ini+fim)/2;
				if (n/meio >= res) ini = meio + 1;
				else fim = meio - 1;
			}
			r = min(k, ini - 1);
			cout << res << l << r << endl;
			if (r <= last) continue;
			resp = (resp + res*(r-l+1) - (res*(quad(r)-quad(l-1)+MOD)%MOD)+MOD)%MOD;
		}

		int x = min(k, n-1);
		int r = ((x*(x+1))/2 - (last*(last+1))/2) % MOD;
		resp = (resp + n*r) % MOD;

		if (k < n)
		{
			cout << resp << endl;
			continue;
		}

		resp = (resp + 1 + ((k-n)%MOD)*n) % MOD;
		cout << resp << endl;
	}
}
