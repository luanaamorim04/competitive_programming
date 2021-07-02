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

ll n, arr[1<<20], freq[1<<20], f[1<<20], resp, x;

int main()
{_	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		freq[arr[i]]++;
	}

	for (int j = 0; j < (1<<20); j++)
		f[j] = freq[j];

	for (int i = 0; i < 20; i++)
		for (int j = 0; j < (1<<20); j++)
			if (j&(1<<i)) f[j] += f[j^(1<<i)];

	for (int i = 0; i < n; i++)
		resp += f[arr[i]^((1<<20) - 1)];

	resp -= freq[0];
	resp>>=1;
	cout << resp << endl;
}
