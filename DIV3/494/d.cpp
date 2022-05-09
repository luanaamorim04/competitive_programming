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
#include <bitset>
#define ll long long
#define INF (1e9)
#define MAX (2e5)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

map<int, int> freq, usei;
int n, q, x, arr[1<<20], pot, resp, ok;

int tenho(int x)
{
	int maior = x;
	while (x)
	{
		while (!freq[maior] && maior) maior>>=1;
		if (!maior) return 0;
		int y = min(freq[maior], x/maior);
		freq[maior] -= y;
		usei[maior] += y;
		x -= y*maior;
		resp += y;
	}
	return 1;
}

int main()
{_
	cin >> n >> q;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		freq[arr[i]]++;
	} 

	sort(arr, arr+n);

	while (q--)
	{
		resp = 0, ok = 1, pot = 0;
		cin >> x;
		while (x)
		{
			if (x&1) ok &= tenho(1<<pot);
			x>>=1;
			pot++;
		}

		for (auto [a, b] : usei)
		{
			freq[a] += b;
			usei[a] = 0;
		}

		cout << (ok ? resp : -1) << endl;
	}
}


















