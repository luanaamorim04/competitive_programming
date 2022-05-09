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
#define MAX (int) (400 + 5)
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

int t, n, q0, q1, q2, q3, resp;
char tab[MAX][MAX];

int main()
{_
	cin >> t;
	for (int k = 1; k <= t; k++)
	{
		q0 = q1 = q2 = q3 = 0;
		cin >> n;
		for (int i = 0; i < (n<<1); i++)
			for (int j = 0; j < (n<<1); j++)
				cin >> tab[i][j];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				q0 += (tab[i][j] == 'I');

		for (int i = 0; i < n; i++)
			for (int j = n; j < (n<<1); j++)
				q1 += (tab[i][j] == 'I');

		for (int i = n; i < (n<<1); i++)
			for (int j = 0; j < n; j++)
				q2 += (tab[i][j] == 'I');

		for (int i = n; i < (n<<1); i++)
			for (int j = n; j < (n<<1); j++)
				q3 += (tab[i][j] == 'I');

		resp = abs(q0-q3) + abs(q1-q2);
		cout << "Case #" << k << ": " << resp << endl;
	}
}












