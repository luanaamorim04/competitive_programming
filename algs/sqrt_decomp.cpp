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

ll bloco[1<<20], arr[1<<20], raiz, n, a, b, resp, m, k, idx;

int main()
{_
	cin >> n >> m;
	raiz = sqrt(n) + 1;
	k = 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		if (idx < raiz) bloco[k] += arr[i];
		else bloco[++k] = arr[i], idx = 0;
		idx++;
	}

	while (m--)
	{
		cin >> a >> b;
		resp = 0;
		int fs = ((a+raiz-1)/raiz);
		int last = ((b+raiz-1)/raiz) - 1;

		if (fs >= last) 
		{
			for (int i = a; i <= b; i++) resp += arr[i];
		}
		else
		{
			for (int i = a; i <= (raiz*fs); i++)
				resp += arr[i];

			for (int i = fs + 1; i <= last; i++)
				resp += bloco[i];

			for (int i = (raiz*last) + 1; i <= b; i++)
				resp += arr[i];
		}

		cout << resp << endl;
	}
}












