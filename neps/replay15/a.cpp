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

unsigned ll n, arr[MAX], f[70], qnt[MAX], resp;

int main()
{_
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		for (int j = 0; j < 64; j++)
		{
			if (arr[i]&(1ULL<<j)) f[j]++;
		}

		int x = i, k = 0;
		while (!(x&1))
		{
			k++;
			x>>=1;
		}

		qnt[i] = qnt[i-1] + k;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 64; j++)
		{
			if (f[j] < i) continue;
			if ((qnt[f[j]] - (qnt[i]+qnt[f[j]-i])) == 0) resp = (resp + (1ULL<<j)) % MOD;
		}
	}

	cout << resp << endl;
}







