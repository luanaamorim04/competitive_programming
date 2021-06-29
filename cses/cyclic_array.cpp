#include <iostream>
#include <vector>
#define ll long long
#define MAX (int) (2e5 + 5)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, k, resp, i;
ll arr[MAX], psa[MAX];
pair<int, ll> memo[MAX];

int f(int idx)
{
	int ini, meio, fim, resp = 0;
	ll last;
	vector<int> v;
	while (idx <= n)
	{
		if (memo[idx].first != -1 && memo[idx].second != -1) 
		{
			resp += memo[idx].first;
			last = memo[idx].second;
			break;
		}
		ini = idx, fim = n;
		while (ini <= fim)
		{
			meio = ini + ((fim-ini)>>1);
			if (psa[meio]-psa[idx-1] <= k) ini = meio + 1;
			else fim = meio - 1;
		}

		v.push_back(idx);
		last = psa[ini-1]-psa[idx-1];
		idx = ini;
		resp++;
	}	

	for (int i = 0; i < v.size(); i++)
	{
		memo[v[i]].second = last;
		memo[v[i]].first = resp - i;
	}

	return resp;
}

int main()
{_
	cin >> n >> k;
	for (i = 1; i <= n; i++)
	{
		cin >> arr[i];
		psa[i] = psa[i-1] + arr[i];
		memo[i] = {-1, -1};
	}

	resp = n;
	for (i = 1; i <= n; i++)
	{
		f(i);
		if (memo[i].second + psa[i-1] <= k) resp = min(resp, memo[i].first);
	}

	cout << resp << endl;
}










