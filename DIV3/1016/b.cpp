#include <bits/stdc++.h>
#define int long long
#define MAXN (int)(1e6 + 10)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int)(1e9 + 7)
#define BASE 37
#define MAXL 20
#define INF (int)(1LL<<30)
#define PI 3.14159265359
#define EPS (1e-9)
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

int t, psa[MAXN];
string s;

int32_t main()
{_
	cin >> t;
	while (t--)
	{
		cin >> s;
		int resp = INF;
		int n = s.size();
		psa[0] = (s[0] == '0');
		for (int i = 1; i < s.size(); i++)
			psa[i] = psa[i-1] + (s[i] == '0');
		while (s[n-1] == '0') n--;
		for (int i = 1; i < n; i++)
		{
			if (s[i] == '0') continue;
			//cout << i << ' ' << psa[i-1] << ' ' << psa[n-1]-psa[i] << endl;
			resp = min(resp, i-psa[i-1] + (int)s.size()-i-(psa[n-1]-psa[i]));
		}

		if (s[0] != '0')resp = min(resp, (int)s.size()-1-psa[n-1]);
			
		cout << resp << endl;
	}

}
