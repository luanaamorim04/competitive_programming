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
#define MAX (int) (2e3 + 5)
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

int t, n, arr[MAX], pos[MAX], resp[MAX], tot;

int main()
{_
	cin >> t;
	while (t--)
	{
		memset(resp, 0, sizeof resp);
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
			pos[arr[i]] = i;
		}

		int qnt = n;
		while (pos[qnt] == qnt && qnt>1)
			--qnt;

		tot = qnt;

		while (qnt > 0)
		{
			int k = (pos[qnt]==qnt?0:pos[qnt]);
			resp[qnt] = k;
			for (int i = 1; i <= qnt; i++)
			{
				pos[i] = (pos[i] + (qnt-k)) % qnt;
				if (!pos[i]) pos[i] = qnt;
			}
			--qnt;
		}

		for (int i = 1; i <= n; i++)
			cout << resp[i] << ' ';
		cout << endl;

	}
}










