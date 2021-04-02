#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring>
#define ll long long
#define INF 99999999
#define MAX 300000
#define MOD 1000000007
#define par pair<int, int>
#define all(v) (v.begin(), v.end())
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll n, m, arr[1<<20], cp[1<<20];
map<par, int> resp;
map<int, int> freq;

int bb(int ini, ll x)
{
	int meio, fim = n - 1;
	while (ini <= fim)
	{
		meio = ini + (fim-ini)/2;
		if (arr[meio] == x) return 1;
		else if (arr[meio] < x) ini = meio + 1;
		else fim = meio - 1;
	}
	return 0;
}

int main()
{_
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		cp[i] = arr[i];
	}

	sort(arr, arr+n);
	for (int i = 0; i < n; i++)
		resp[{cp[i], ++freq[cp[i]]}] = i + 1; 
	
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] + arr[j] > m) continue; 
			int x = m - (arr[i] + arr[j]);
			if (bb(j + 1, x))
			{
				cout << resp[{arr[i], 1}] << ' ' << resp[{arr[j], 1 + (arr[i] == arr[j])}] << ' ' 
				<< resp[{x, 1 + (x == arr[j]) + (x == arr[i])}] << endl;
				return 0;
			}
		}
	}

	cout << "IMPOSSIBLE" << endl;
}
