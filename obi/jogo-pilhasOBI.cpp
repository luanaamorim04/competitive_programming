#include <iostream>
#include <vector>
//#include <bits/stdc++.h>
#define int long long
#define MAXN (int) (1e3 + 10)

using namespace std;

int n, n1, n2, x, quebra, freq[MAXN], pos[MAXN];
vector<int> v, v1;

int32_t main()
{
	cin >> n;
	cin >> n1;
	for (int i = 1; i <= n; i++) freq[i] = 1;
	for (int i = 0; i < n1; i++)
	{
		cin >> x;
		pos[x] = i+1;
	}

	cin >> n2;
	for (int i = 0; i < n2; i++)
	{
		cin >> x;
		pos[x] = n1 + n2 - i;
	}

	quebra = (pos[1] <= n1 ? n1 : n1 + 1);
	int resp = 0;
	for (int num = 1; num <= n; num++)
	{
//		cout << pos[num] << endl;
		int l = pos[num], r = quebra;
		if (l <= r)
		{
			for (int i = l; i <= r; i++)
				resp += freq[i];
			quebra = pos[num];
		}
		else
		{
			for (int i = l; i >= r; i--)
				resp += freq[i];
			quebra = pos[num];
		}

		freq[pos[num]] = 0;
	}
	cout << resp << endl;
}
