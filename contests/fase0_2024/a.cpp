#include <iostream>
#include <vector>
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define MAXN (int) (501)
#define INF (int) (1e9)
#define MOD (int) (998244353)

using namespace std;

int n, m, k, l, a, b, tab[2010][2010];
char c;

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k >> l;
	--k, --l;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> c;
			if (c == '.') continue;
			tab[i][j] = -INF;
			++tab[max(0, i-l)][max(0, j-k)], ++tab[max(0, i-l)][j+k], ++tab[i+l][j+k], ++tab[i+l][max(0, j-k)];
			++tab[max(0, i-k)][max(0, j-l)], ++tab[max(0, i-k)][j+l], ++tab[i+k][j+l], ++tab[i+k][max(0, j-l)];
		}
	}
	
	int r = -1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (r < tab[i][j]) r = tab[i][j], a = i, b = j;

	cout << a << ' ' << b << endl;
}
