#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring>
#include <set>
#include <stack>
#include <bitset>
#define ll long long
#define INF (1e9)
#define MAX (int) (2e5 + 5)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define sz(x) (int) ((x).size())
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define lsb(x) (x & -x)
#define W(x) cout << #x << ": " << x << endl
#define Wii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int t, vis['z' + 5],  p['z' + 5];
string s, r1, r2;
vector<int> pos['z' + 5];

int main()
{_
	cin >> t;
	while (t--)
	{
		cin >> s;
		r1.clear();
		r2.clear();
		int ok = 1;
		for (int i = s.size() - 1; i >= 0; i--)
		{
			vis[s[i]] += 1;
			p[s[i]] = vis[s[i]];
			if (vis[s[i]] > 1) continue;
			r1 += s[i];
		}

		reverse(all(r1));
		for (int i = r1.size() - 1; i >= 0; i--)
		{
			if (vis[r1[i]]%(i+1)) ok = 0;
			vis[r1[i]] /= (i+1);
		}

		for (int i = 0; i < s.size(); i++)
		{
			if (vis[s[i]] == 0) break;
			vis[s[i]]--;
			r2 += s[i];
		}

		for (int i = 0; i < r2.size(); i++)
			pos[r2[i]].push_back(i);

		int soma = 0, idx = 0, i = r2.size()-1, last = 0;
		while (idx < r1.size())
		{
			for (int j = 'a'; j <= 'z'; j++) vis[j] = 0;
			int k = INF;
			for (int j = last; j <= i; j++)
			{
				if (pos[s[j]][vis[s[j]]] < k) ok = 0;
				vis[s[j]]++;
				k = pos[s[j]][vis[s[j]]];
				cout << k << endl;
			}

			soma += p[r1[idx++]];
			last = i;
			i += (r2.size() - soma);
		}

		cout << ok << endl;


		// if (ok) cout << r2 << ' ' << r1 << endl;
		// else cout << -1 << endl;
	}
}







