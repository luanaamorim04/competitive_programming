#include <iostream>
#include <bits/stdc++.h>
#define MAXN (int) (1e6 + 5)

using namespace std;

string s;
int n, pref[MAXN], qtd, suff[MAXN], last[26], psa[MAXN], resp;

int32_t main()
{
	cin >> n >> s;
	for (int maior = 'a'; maior <= 'z'; maior++)
	{
		memset(last, 0, sizeof last);
		for (int i = 1; i <= n; i++)
		{
			psa[i] = psa[i-1] + (s[i-1] == maior);
			if (s[i-1] == maior) continue;

			int letra = s[i-1]-'a';
			if (pref[last[letra]] > 0)
				pref[i] = pref[last[letra]] + psa[i] - psa[last[letra]] - 1;
			else 
				pref[i] = psa[i] - psa[last[letra]] - 1;

			last[letra] = i;
		}

		memset(last, 0, sizeof last);

		for (int i = n; i >= 1; i--)
		{
			psa[i] = psa[i+1] + (s[i-1] == maior);
			if (s[i-1] == maior) continue;

			int letra = s[i-1]-'a';
			if (suff[last[letra]] > 0)
				suff[i] = suff[last[letra]] + psa[i] - psa[last[letra]] - 1;
			else 
				suff[i] = psa[i] - psa[last[letra]] - 1;

			last[letra] = i;
			resp = max(resp, suff[i] + pref[i] + 1);
		}
	}	

	cout << resp << endl;
}