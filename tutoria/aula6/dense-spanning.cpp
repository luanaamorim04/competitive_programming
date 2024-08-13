#include <iostream>
#include <vector>
#define MAXN (int) (1e3 + 10)
#define iii tuple<int, int, int>
#define all(x) x.begin(), x.end()
#define int long long

using namespace std;

int tam[MAXN], pai[MAXN], a, b, c, n, m, resp, diff;
vector<iii> arr;

void join(int a, int b)
{
	if (tam[a] < tam[b]) swap(a, b);
	pai[b] = a;
}

int find(int x)
{
	if (x == pai[x]) return x;
	return find(pai[x]);
}

int32_t main()
{
	cin >> n >> m;
	while (m--)
	{
		cin >> a >> b >> c;
		arr.push_back({c, a, b});
	}

	resp = 1e10;
	sort(all(arr));
	for (int i = 0; i < arr.size(); i++)
	{
		int menor = 1e10, maior = -1e10, q = 0;
		for (int j = 1; j <= n; j++) tam[j] = 1, pai[j] = j;

		for (int j = i; j < arr.size(); j++)
		{
			auto[c, a, b] = arr[j];
			int A = find(a), B = find(b);
			if (A == B) continue;
			menor = min(menor, c);
			maior = max(maior, c);
			join(A, B);
			q++;
		}

		if (q != n - 1) break;
		resp = min(resp, maior-menor);
	}

	if (resp == 1e10)
		cout << "NO" << endl;
	else
	{
		cout << "YES" << endl;
		cout << resp << endl;
	}

}
