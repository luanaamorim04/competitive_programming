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

int n, arr[MAX], a[MAX], b[MAX], c, d, f[MAX], resp, k;

int main()
{_
	cin >> n;
	for (int i = 0; i < n; i++) 
	{
		cin >> arr[i];
		f[arr[i]%200]++;
		if (f[arr[i]%200] >= 2) resp = arr[i]%200;
	}

	for (int i = 0; i < n; i++)
	{
		if (arr[i]%200 == resp)
		{
			cout << 1 << ' ' << i+1 << endl;
			k++;
			if (k==2) return 0;
		} 
		f[arr[i]%200] = i;
	}

	for (int i = 0; i < 200; i++)
	{
		int r = f[i];
		for (int j = 0; j < n; j++)
			for (int k = j+1; k < n; k++)
				if (((arr[k]+arr[j]) % 200) == i) 
				{
					cout << arr[j] << ' ' << arr[k] << endl;
					a[r]=j, b[r++]=k;
				}

		if (r >= 2)
		{
			cout << "YES" << endl;
			cout << 2 << ' ' << a[0]+1 << ' ' << b[0]+1 << endl;
			if (f[i]) cout << 1 << ' ' << 
			// cout << 2 << ' ' << a[1]+1 << ' ' << b[1]+1 << endl;
			return 0;
		}
	}

	cout << "No" << endl;
}











