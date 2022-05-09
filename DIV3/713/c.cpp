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
#define ll long long
#define INF (1e9)
#define MAX (2e5)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int t, a, b, A, B, ok;
string s;

int main()
{_
	cin >> t;
	while (t--)
	{
		cin >> a >> b;
		cin >> s;
		ok = 1;
		int n = s.size();
		A = B = 0;
		for (int i = 0; i < n; i++)
		{
			A += (s[i] == '0');
			B += (s[i] == '1');
		}

		for (int i = 0; i < n/2; i++)
		{
			if (s[i] == '?' && s[n-i-1] == '?') continue;
			if (s[i] == '?') s[i] = s[n-i-1], (s[i] == '0' ? A++ : B++);
			if (s[n-i-1] == '?') s[n-i-1] = s[i], (s[i] == '0' ? A++ : B++);
		}

		for (int i = 0; i < n/2; i++)
		{
			if (s[i] != s[n-i-1])
			{
				ok = 0;
				continue;
			}
			if (s[i] == '?' && s[n-i-1] == '?') 
			{
				if (A + 2 <= a) A += 2, s[i] = s[n-i-1] = '0';
				else B += 2, s[i] = s[n-i-1] = '1';
			}
		}

		if (n&1 && s[n/2] == '?')
		{
			if (A < a && a-A == 1) s[n/2] = '0', A++;
			else s[n/2] = '1', B++;
		}

		if (A != a || B != b || !ok)
		{
			cout << -1 << endl;
			continue;
		}
		cout << s << endl;
		
	}
}
