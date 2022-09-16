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
#define dbug(x) cout << (#x) << " -> " << x << endl
#define ll long long
#define INF (1e15)
#define MAX (int) (3e5 + 5)
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

ll n, x, l, r, resp, freq[MAX], psa[MAX], t;

int main()
{_
	cin >> n >> x;
	while (n--)
	{
		cin >> l >> r;
		psa[l]++;
		psa[l+r+1]--;
	}

	for (int i = 1; i < MAX; i++) psa[i] += psa[i-1];

	resp = INF;
	for (int i = 0; i <= 480; i++)
	{
		ll maior = 0;
		for (int j = i; j < MAX; j+=x)
			maior += psa[j];

		if (resp > maior) resp = maior, t = i;
	}

	cout << t << ' ' << resp << endl;
}
















