#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define MAXN (int) (2e5 + 10)
#define INF (int) (1e9 + 10)
#define ii pair<int, int> 
#define all(x) x.begin(), x.end()

using namespace std;

int k, resp, a, b, t, n, m;
string s[MAXN];

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> a >> b >> k;
		int lado = (a+k-1)/k;
		int sobe = (b+k-1)/k;
		
		if (lado > sobe) cout << 2*lado  - 1<< endl;
		else if (sobe > lado) cout << 2*sobe << endl;
	}
}
