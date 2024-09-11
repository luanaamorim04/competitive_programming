#include <iostream>
#define MAXN (int) (1e6 + 10)

using namespace std;

int n, m, a, pai[MAXN], tam[MAXN], maior[MAXN];
char op;

int find(int x)
{
	if (x == pai[x]) return x;
	return pai[x] = find(pai[x]);
}

void join(int a, int b)
{
	int A = find(a), B = find(b);
	maior[A] = maior[B];
	tam[A] += tam[B];
	pai[A] = B; 
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) pai[i] = i, maior[i] = i, tam[i] = 1;

	for (int i = 0; i < n; i++)
	{
		int p;
		cin >> p;
		p--;
		cout << find(p)+1 << ' ';
		join(find(p), find(p)+1%n);
	}
	cout << endl;

}

