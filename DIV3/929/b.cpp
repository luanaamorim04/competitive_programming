#include <iostream>
#include <vector>
#define MAXN (int) (2e5 + 10)
#define INF 1e9
#define all(x) x.begin(), x.end()
#define int long long
#define ii pair<int, int>

using namespace std;

int freq[3], n, m, t, k, arr[MAXN], soma;

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> t;
	while (t--)
	{
		cin >> n;
		soma = 0;
		freq[0] = freq[1] = freq[2] = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			freq[arr[i]%3]++;
			soma = (soma + arr[i]) % 3;
		}

		if (!soma) 
		{
			cout << 0 << endl;
		}	
		else if (soma == 2) 
		{
			cout << 1 << endl;
		}
		else if (soma == 1)
		{
			if (freq[1]) cout << 1 << endl;
			else cout << 2 << endl;
		}

	}
}
