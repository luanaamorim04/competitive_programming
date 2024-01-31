#include <iostream> 
#define int long long
#define MAXN (int) (1e5)
#define INF (int) (1e9)

using namespace std;

int n, a, b, pa[MAXN], pb[MAXN];

int32_t main()
{
	cin >> n>> a >> b;
	int resp = INF;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (!i && !j) continue;
			if (((a*i) + (b*j)) % n == 0)resp = min(resp, i+j);
		}
	}

	cout << resp << endl;

}
