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

int dist[10][10][10][10], a1, a2, a3, a4;
string a, b;

int main()
{_
	for (int i = 1; i <= 8; i++)
		for (int j = 1; j <= 8; j++)
			for (int k = 1; k <= 8; k++)
				for (int l = 1; l <= 8; l++)
				{
					dist[i][j][k][l] = (i==k && j==l)?0:INF;
					if (abs(i-k) == 2 && abs(j-l) == 1) dist[i][j][k][l] = 1;
					if (abs(i-k) == 1 && abs(j-l) == 2) dist[i][j][k][l] = 1;
				}

	for (int k1 = 1; k1 <= 8; k1++)
		for (int k2 = 1; k2 <= 8; k2++)
			for (int i1 = 1; i1 <= 8; i1++)
				for (int i2 = 1; i2 <= 8; i2++)
					for (int j1 = 1; j1 <= 8; j1++)
						for (int j2 = 1; j2 <= 8; j2++)
							dist[i1][i2][j1][j2] = min(dist[i1][i2][j1][j2], dist[i1][i2][k1][k2] + dist[k1][k2][j1][j2]);
	while (cin >> a >> b)
	{
		a1 = a[1]-'0';
		a2 = a[0]-'a'+1;
		a3 = b[1]-'0';
		a4 = b[0]-'a'+1;
		cout << "To get from " << a << " to " << b << " takes " << dist[a1][a2][a3][a4] << " knight moves." << endl;
	}
}












