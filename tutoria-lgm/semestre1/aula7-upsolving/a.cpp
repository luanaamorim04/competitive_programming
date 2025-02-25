#include <iostream>
#include <vector>
#define MAXN (int) (2e5 + 10)
#define INF (1e15)

using namespace std;

int a, b, x, n, m, v[MAXN], k, freq[MAXN];
long long tmp, resp;
vector<int> stick[MAXN];

int add(int pos)
{
	int muda = 0;
	for (int x : stick[pos])
	{
		muda += (!freq[x]); freq[x]++;
	}
	return muda;

}

int del(int pos)
{
	int muda = 0;
	for (int x : stick[pos])
	{
		--freq[x]; muda += (!freq[x]);
	}

	return muda;
}

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> k >> v[i];
		for (int j = 1; j <= k; j++)
		{
			cin >> x;
			stick[i].push_back(x);
		}	
	}

	resp = INF;
	int qnt = 0, l = 1;
	for (int r = 1; r <= n; r++)
	{
		qnt += add(r); tmp += v[r];

		while (qnt == m)
		{
			if (resp > tmp)
			{
				resp = tmp;
				a = l; b = r;
			}

			tmp -= v[l];
			qnt -= del(l);
			l++;
		}
		
	}

	cout << (resp == INF ? -1 : resp) << endl;
	if (resp != INF) cout << a << ' ' << b << endl;
}
