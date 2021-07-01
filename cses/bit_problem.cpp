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

int n, freq[1<<20], arr[MAX], f1[1<<20], f2[1<<20], f3[1<<20];

int main()
{_
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		freq[arr[i]]++;
	}
	for (int j = 0; j < (1<<20); j++)
		f1[j] = freq[j], f2[j] = freq[j], f3[j] = freq[(~j)&((1<<20)-1)];

	for (int i = 0; i < 20; i++)
		for (int j = 0; j < (1<<20); j++)
			if (j&(1<<i)) f1[j] += f1[j^(1<<i)];

	for (int i = 0; i < 20; i++)
		for (int j = 0; j < (1<<20); j++)
			if (!(j&(1<<i))) f2[j] += f2[j^(1<<i)];

	for (int i = 0; i < 20; i++)
		for (int j = 0; j < (1<<20); j++)
			if ((~j)&(1<<i)) f3[j] += f3[j^(1<<i)];

	for (int i = 0; i < n; i++)
	{
		cout << f1[arr[i]] << ' ' << f2[arr[i]] << ' ' << n - f3[arr[i]] << endl;
	}
}





