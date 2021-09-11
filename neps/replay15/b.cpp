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

int n, arr[MAX], freq[MAX];

int main()
{_
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 0; i < (1<<n); i++)
	{
		int soma = 0;
		for (int j = 0; j < n; j++)
		{
			if (i&(1<<j)) soma += arr[j];
		}

		freq[soma]++;
	}

	for (int i = 0; i <= 500; i++)
	{
		if (freq[i] >= 3) 
		{
			cout << i << endl;
			return 0;
		}
	}

	cout << 0 << endl;
}










