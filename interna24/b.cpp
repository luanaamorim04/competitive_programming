#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
//#include <bits/stdc++.h>
#define MAXN (int) (2e5 + 10)
#define int long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define MOD (int) (1e9 + 7)
#define INF (int) (1e9 + 10)
#define all(x) x.begin(), x.end()
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)

using namespace std;

int k, n, m, t, arr[MAXN];
char c;

string soma(string s)
{
	int idx = s.size() - 1;
	while (s[idx] == '9')
	{
		s[idx] = '0';
		idx--;
	}

	s[idx]++;

	return s;
}

string mult(string s)
{
	int idx = s.size() - 1, r = 0;
   	for (int i = s.size() - 1; i > 0; i--)
	{
		if (s[i] >= '5') s[i] = (((s[i] - '0')*2 + r) % 10) + '0', r = 1;
		else s[i] = ((s[i] - '0')*2 + r) + '0', r = 0;
	}

	string e;
	int ok = 0;
	for (int i = 0; i < s.size(); i++)
		if (ok || s[i] != '0') e += s[i], ok = 1;
	return e;
}


int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	string s;
	s += '0';
	s += '0';
	for (int i = 1; i <= n; i++)
	{
		cin >> c;
		s += c;
	}

	cout << soma(mult(s)) << endl;

}

