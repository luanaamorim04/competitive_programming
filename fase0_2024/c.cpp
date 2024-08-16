#include <iostream>
#include <vector>
#define MAXN (int) (110)
#define all(x) x.begin(), x.end()

using namespace std;

int n, g, a, b, m, grau[MAXN], qtd, maior_f, f[MAXN], maior, pai[MAXN], vis[MAXN], tam[MAXN], total, tam_um;
vector<int> comps[MAXN], graus;

int find(int x)
{
	if (x == pai[x]) return x;
	return pai[x] = find(pai[x]);
}

void join(int a, int b)
{
	a = find(a); b = find(b);
	if (a == b) return;
	tam[a] += tam[b];
	pai[b] = pai[a];
}

int32_t main()
{
	cin >> n;
	qtd = 1000;
	for (int i = 1; i <= n+1; i++)
	{
		cin >> m;
		graus.push_back(m);
		total += m;
		for (int j = 1; j <= n; j++) 
			vis[j] = 0, tam[j] = 1, pai[j] = j;

		while (m--)
		{
			cin >> a >> b;
			join(a, b);
		}

		for (int j = 1; j <= n; j++)
			if (!vis[pai[find(j)]]) vis[pai[find(j)]] = 1, comps[i].push_back(tam[find(j)]);

		qtd = min(qtd, (int)comps[i].size());
		sort(all(comps[i]));
	}

	total/=(n-1);
	for (int i = 0; i <= n; i++)
	{
		if (total == graus[i]) 
		{
			cout << comps[i+1].size() + 1 << endl;
			cout << 1 << ' ';
			int b = 1;
			for (int x : comps[i+1]) 
			{
				if (!b) cout << ' ';
				cout << x;
				b = 0;
			}

			cout << endl;
			return 0;
		}	
	}

	if (total == 0)
	{
		for (int i = 1; i <= n+1; i++) cout << 1 << ' ';
		cout << endl;
		return 0;
	}

	if (qtd == 1)
	{
		cout << 1 << endl;
		cout << n + 1 << endl;
		return 0;
	}

	for (int i = 1; i <= n+1; i++)
	{
		if (comps[i].size() != qtd) continue;
		for (int x : comps[i]) maior = max(maior, x);
	}
	for (int i = 1; i <= n+1; i++)
	{
		if (comps[i].size() != qtd) continue;
		for (int x : comps[i]) f[i] += (maior==x);
		maior_f = max(maior_f, f[i]);
	}

	for (int i = 1; i <= n+1; i++)
	{
		int ok = 1;
		if (comps[i].size() != qtd || f[i] != maior_f - 1) continue;
		cout << qtd << endl;
		int b = 1;
		for (int x : comps[i])
		{
			if (!b) cout << ' ';
			if (x == maior-1 && ok) ok = 0;
			else cout << x;
		}
		cout << maior << endl;
		return 0;
	}

	cout << qtd << endl;
	int b = 1;
	for (int x : comps[1])
	{
		if (!b) cout << ' ';
		cout << maior;
		b = 0;
	}
	cout << endl;

}	
