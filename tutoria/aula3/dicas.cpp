#include <iostream> 
#include <vector> 
#define MAXN (int) (1e5 + 10)
#define ii pair<int, int> 

using namespace std;

vector<ii> grafo[MAXN];
int c, a, b, m, n;

int32_t main()
{
	cin >> n >> m;
	while (m--)
	{
		cin >> a >> b >> c;
		grafo[a].push_back({b, c});
	}

	for (int i = 1; i <= n; i++)
	{
		for (auto[v, peso] : grafo[i])
		{

		}
	}
}
