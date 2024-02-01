#include <iostream>
//#include <bits/stdc++.h>
#define MAXN (int) 501
#define INF (int) 1e9
#define MAXK (int) (5e3 + 10)
#define int long long
#define MOD (int) (1e9 + 7)
#define max(a, b) (a>b?a:b)

using namespace std;

int n;
string pref[MAXN], suff[MAXN], tab[MAXN][MAXN];

int lcc(string &a, string &b)
{
	int idx = 0;
	while (idx < min(a.size(), b.size()))
	{
		if (a[idx] != b[idx]) return idx;
		idx++;
	}

	return idx;
}

int is_suff(string &s, string &suff)
{
	int idx1 = s.size() - 1, idx2 = 0;
	while (idx2 < suff.size() && idx1 >= 0)
	{
		if (s[idx1] != suff[idx2]) return 0;
		idx1--;
		idx2++;
	}

	return 1;
}

int is_pref(string &s, string &pref)
{
	int idx1 = 0, idx2 = 0;
	while (idx1 < s.size() && idx2 < pref.size())
	{
		if (s[idx1] != pref[idx2]) return 0;
		idx1++;
		idx2++;
	}

	return 1;
}

int32_t main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> tab[i][j];
	
	for (int i = 1; i <= n; i++)
	{
		int k = INF;
		string last = tab[i][i==1?2:1];
		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;
			k = min(k, lcc(tab[i][j], last));
			last = tab[i][j];
		}

		if (k == 0)
		{
			cout << "NONE" << endl;
			return 0;
		}

		for (int c = 0; c < k; c++)
			pref[i] += (char)tab[i][i==1?2:1][c];
	}

	int many = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i==j) continue;

			if (!is_suff(tab[i][j], pref[j]) || !is_pref(tab[i][j], pref[i]))
			{
				cout << "NONE" << endl;
				return 0;
			}

			many |= (pref[j].size() + pref[i].size() > tab[i][j].size());
		}
	}

	if (many)
	{
		cout << "MANY" << endl;
		return 0;
	}

	cout << "UNIQUE" << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << pref[i] << endl;
	}
	return 0;

}
