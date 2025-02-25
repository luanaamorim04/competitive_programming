#include <iostream>
#include <vector> 
#define MAXN (int) (3e5 + 10)

using namespace std;

int a, b, n, m, pai[MAXN], tam[MAXN], par[MAXN];

int paridade(int x)
{
	int p = 0;
	while (x != pai[x])
	{
		p ^= par[x];
		x = pai[x];
	}

	return p;
}
int find(int x)
{
	if (x == pai[x]) return x;
	return find(pai[x]);
}
void join(int a, int b)
{
	int A = find(a), B = find(b);
	if (A == B) return;
	if (tam[A] < tam[B]) swap(A, B);
	pai[B] = A;
	tam[A] += tam[B];
	par[B] = 1^paridade(a)^paridade(b);
}





int32_t main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		pai[i] = i, tam[i] = 1;
	
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b;
		if (find(a) != find(b))
		{
			join(a, b);
			continue;
		}

		if (paridade(a) == paridade(b))
		{
			cout << i << endl;
			return 0;
		}

		
	}	

	cout << -1 << endl;
}
