#include <iostream>
#define MAXN (int) (1e6 + 10)

using namespace std;

int n, m, a, pai[MAXN], tam[MAXN], maior[MAXN];
char op;

int find(int x)
{
	if (x == pai[x]) return x;
	return find(pai[x]);
}

void join(int a, int b)
{
	int A = find(a), B = find(b);
	if (tam[A] < tam[B]) swap(A, B);
	maior[A] = max(maior[A], maior[B]);
	tam[A] += tam[B];
	pai[B] = A; 
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n+1; i++) pai[i] = i, maior[i] = i, tam[i] = 1;

	while (m--)
	{
		cin >> op >> a;
		if (op == '-') join(a, a+1);
		else cout << (maior[find(a)] > n ? -1 : maior[find(a)]) << endl;
	}
}
