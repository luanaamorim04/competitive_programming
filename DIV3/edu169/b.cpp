#include <iostream>
#include <vector>
#include <map>
#include <queue> 
//#include <bits/stdc++.h>
#define MAXN (int) (2e5 + 10)
#define MOD (int) (1e9 + 7)
#define ii pair<int, int> 
#define iii tuple<int, int, int> 
#define all(x) x.begin(), x.end()
#define int long long

using namespace std;

int l, r, c, t, n, k, arr[10][MAXN];
map<string, int> mapa;
string s[MAXN];

void add(int id, int pos)
{
	arr[id][pos]++;
}

int esq(int id, int p)
{
	int ini = 1, meio, fim = p;
	while (ini <= fim)
	{
		meio = (ini+fim)/2;
		if (arr[id][p] - arr[id][meio-1] != 0) ini = meio + 1;
		else fim = meio - 1;
	}

	return ini - 1;
}

int dir(int id, int p)
{
	int ini = p, meio, fim = n;
	while (ini <= fim)
	{
		meio = (ini+fim)/2;
		if (arr[id][meio] - arr[id][p-1] != 0) fim = meio - 1;
		else ini = meio + 1;
	}

	return fim + 1;
}

int32_t main()
{
	ios_base::sync_with_stdio(false), cin.tie(0);
	cin >> t;
	string a[] = {"BG", "BR", "BY", "GR", "GY", "RY"};

	for (string s : a)
		mapa[s] = ++c;

	while (t--)
	{
		cin >> n >> k;
		for (int i = 1; i <= 6; i++)
			for (int j = 1; j <= n; j++)
				arr[i][j] = 0;

		for (int i = 1; i <= n; i++)
		{
			cin >> s[i];
			add(mapa[s[i]], i);
		}

		for (int i = 1; i <= 6; i++)
			for (int j = 1; j <= n; j++)
				arr[i][j] += arr[i][j-1];


		while (k--)
		{
			cin >> l >> r;
			if (r < l) swap(r, l);

			int resp = 1e9;
			if (s[l][0] == s[r][0] || s[l][1] == s[r][0] || s[l][0] == s[r][1] || s[l][1] == s[r][1]) 
				cout << abs(r-l) << endl;
			else
			{
				for (int i = 0; i <= 1; i++)
				{
					int tmp = 1e9;
					for (int j = 0; j <= 1; j++)
					{
						string curr;
						curr += s[l][i];
						curr += s[r][j];
						sort(all(curr));
						int procura = mapa[curr];
//						cout << curr << ' ' << dir(procura, r) << endl;
						int menor = esq(procura, l);
						int maior = dir(procura, r);

						if (arr[procura][r] - arr[procura][l-1]) tmp = r-l;
						if (menor != 0) tmp = min(tmp, l-menor + r-menor);
						if (maior != n+1) tmp = min(tmp, maior-r + maior-l);
					}
					resp = min(resp, tmp);
				}
				cout << (resp == 1e9 ? -1 : resp) << endl;
			}

		}
 	}
}

