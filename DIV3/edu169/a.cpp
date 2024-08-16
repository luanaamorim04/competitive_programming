#include <iostream>
#include <vector>
#include <map>
#include <queue> 
//#include <bits/stdc++.h>
#define MAXN (int) (2e5 + 10)
#define MOD (int) (1e9 + 7)
#define ii pair<int, int> 
#define iii tuple<int, int, int> 
#define all(x) x.begin(), x.end()
#define int long long

using namespace std;

int n, m, t, arr[MAXN], l, r, i, j;

int32_t main()
{
	ios_base::sync_with_stdio(false), cin.tie(0);
	cin >> t;
	while (t--)
	{
		int soma = 0;
		cin >> n;
		for (int i = 0; i < n; i++) 
		{
			cin >> arr[i];
			soma += arr[i];
		}

		cout << (soma&1 ? "Bob" : "Alice") << endl;
 	}
}
