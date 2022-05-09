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
#define MAX (int) (2e5 + 5)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define esq(x) (x<<1)
#define dir(x) ((x<<1)+1)
#define lsb(x) (x & -x)
#define dbug(x) cout << #x << ": " << x << endl
#define dbugii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int t, n, fs, usei[10100], resp[101][101];

int main()
{_
	cin >> t;
	while (t--)
	{
		cin >> n;
		fs = 1;
		if (n == 2) 
		{
			cout << -1 << endl;
			continue;
		}
		int num = 0;
		for (int i = 2; i <= n; i++)
		{
			for (int j = 1, k = i; j <= n && k > 0; j++, k--)
			{
				resp[j][k] = ++num; 
			}
		}

		for (int i = 2; i <= n; i++)
		{
			for (int j = i, k = n; j <= n && k > 0; j++, k--)
			{
				resp[k][j] = ++num; 
			}
		}

		resp[1][1] = (n*n) - 1;
		resp[n][n] = (n*n);

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				cout << resp[i][j] << ' ';
			cout << endl;
		}

		
	}
}



