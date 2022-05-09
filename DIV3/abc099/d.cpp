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
#define MAX (int) (500 + 5)
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

int tab[MAX][MAX], c[MAX][MAX], n, m, w[40][3];
vector<int> grupo[3];
int resp, tmp;

int main()
{_
	cin >> n >> m;
	resp = INF;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			cin >> c[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> tab[i][j];
			grupo[(i+j) % 3].push_back(tab[i][j]-1);
		}

	for (int i = 0; i < m; i++)
	{
		for (int l = 0; l < grupo[0].size(); l++)
			w[i][0] += c[grupo[0][l]][i];
		for (int l = 0; l < grupo[1].size(); l++)
			w[i][1] += c[grupo[1][l]][i];
		for (int l = 0; l < grupo[2].size(); l++)
			w[i][2] += c[grupo[2][l]][i];
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (j==i) continue;
			tmp = 0;
			for (int k = 0; k < m; k++)
			{
				if (k==i || k==j) continue;
				
				resp = min(resp, w[i][0] + w[j][1] + w[k][2]);
			}
		}
	}

	cout << resp << endl;
}






























