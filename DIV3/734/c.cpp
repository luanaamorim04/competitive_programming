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

struct word
{
	int a, b, c, d, e;
	string s;
};

int t, n;
word arr[MAX];

int cmp1(word x, word y)
{
	return x.a > y.a;
}

int cmp2(word x, word y)
{
	return x.b > y.b;
}

int cmp3(word x, word y)
{
	return x.c > y.c;
}

int cmp4(word x, word y)
{
	return x.d > y.d;
}

int cmp5(word x, word y)
{
	return x.e > y.e;
}

int main()
{_
	cin >> t;
	while (t--)
	{
		cin >> n;
		int resp = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i].s;
			int x, y, z, w, k;
			x = z = y = k = w = 0;
			for (int j = 0; j < arr[i].s.size(); ++j)
			{
				if (arr[i].s[j] == 'a') x++;
				if (arr[i].s[j] == 'b') y++;
				if (arr[i].s[j] == 'c') z++;
				if (arr[i].s[j] == 'd') w++;
				if (arr[i].s[j] == 'e') k++;

				arr[i].a = x - (arr[i].s.size() - x);
				arr[i].b = y - (arr[i].s.size() - y);
				arr[i].c = z - (arr[i].s.size() - z);
				arr[i].d = w - (arr[i].s.size() - w);
				arr[i].e = k - (arr[i].s.size() - k);
			}
		}

		sort(arr, arr+n, cmp1);
		int x = 0;
		for (int i = 0; i < n; ++i)
		{
			x += arr[i].a;
			if (x <= 0) continue;
			resp = max(resp, i+1);
		}
		sort(arr, arr+n, cmp2);
		x = 0;
		for (int i = 0; i < n; ++i)
		{
			x += arr[i].b;
			if (x <= 0) continue;
			resp = max(resp, i+1);
		}
		sort(arr, arr+n, cmp3);
		x = 0;
		for (int i = 0; i < n; ++i)
		{
			x += arr[i].c;
			if (x <= 0) continue;
			resp = max(resp, i+1);
		}
		sort(arr, arr+n, cmp4);
		x = 0;
		for (int i = 0; i < n; ++i)
		{
			x += arr[i].d;
			if (x <= 0) continue;
			resp = max(resp, i+1);
		}
		sort(arr, arr+n, cmp5);
		x = 0;
		for (int i = 0; i < n; ++i)
		{
			x += arr[i].e;
			if (x <= 0) continue;
			resp = max(resp, i+1);
		}
		sort(arr, arr+n, cmp1);
		x = 0;
		for (int i = 0; i < n; ++i)
		{
			x += arr[i].a;
			if (x <= 0) continue;
			resp = max(resp, i+1);
		}

		cout << resp << endl;
	}
}











