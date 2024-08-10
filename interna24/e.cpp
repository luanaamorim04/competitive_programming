#include <iostream>
#include <iomanip>
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
#define INF (int) (1e18 + 10)
#define all(x) x.begin(), x.end()
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)

using namespace std;

int t, n, k, arr[MAXN];

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		int ok = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
		}

		for (int i = 1; i <= n; i++)
		{
			if (arr[i] < k && arr[i]%k == 0) 
			{
				cout << "YEY" << endl;
				ok = 1;
				break;
			}

			for (int j = i + 1; j <= n; j++)
			{
				int a, b;
				if (arr[i] == arr[j]) continue;
				else if (arr[i]%k == 0 && arr[j]%k == 0 && abs(arr[i] - arr[j]) <= k) 
				{
					cout << "YEA" << endl;
					ok = 1;
					break;
				}
				else if (arr[i]%k == arr[j]%k) continue;
				gcd(arr[i]%k, arr[j]%k, a, b);
				//cout << arr[i]%k << ' ' << arr[j]%k << endl;
				//cout << a << ' ' << b << endl;
				cout << endl;
				if ((a*arr[i] + b*arr[j]) % k == 0)
				{
					ok = 1;
					cout << "YES" << endl;
					break;
				}	
			}
			if (ok) break;
		}

		if (!ok) cout << "NO" << endl;
	}
}




