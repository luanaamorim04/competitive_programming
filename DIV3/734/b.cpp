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

int t, n, arr[MAX], freq[MAX], k, resp[MAX], f[MAX], l[MAX], menor, last, cor[MAX];
priority_queue<par, vector<par>, greater<par> > fila;

int main()
{_
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			freq[arr[i]]++;
		}

		int tot = 0;
		int last = 1;
		int cor = 0;
		for (int i = 1; i <= n; ++i)
		{
			tot += min(k, freq[i]);
		}

		menor = tot/k;
	
		for (int i = 0; i < n; i++)
		{
			int c = max(l[arr[i]], cor);
			if (c == k || f[c + 1]==menor) cout << 0 << ' ';
			else 
			{
				l[arr[i]] = c + 1;
				f[l[arr[i]]]++;
				cout << l[arr[i]] << ' ';
				if (f[l[arr[i]]] == menor) cor = max(cor, l[arr[i]]);
			}

		}
		cout << endl;

		memset(freq, 0, sizeof freq);
		memset(resp, 0, sizeof resp);
		memset(l, 0, sizeof l);
		memset(f, 0, sizeof f);
	}
}	










