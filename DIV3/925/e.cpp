#include <iostream>
#include <queue>
//#include <bits/stdc++.h>
#include <vector>
#define MAXN (int) (2e5 + 10)
#define max(a, b) (a > b ? a : b)
#define INF (int) (1e9)
#define int long long
#define all(x) x.begin(), x.end()

using namespace std;

int t, n, m, arr[MAXN], resp;

int32_t main()
{
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		priority_queue<int> dig; 
		resp = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
			int num = arr[i], lead = 0;
			while (num)
			{
				if (num%10 == 0) lead++, num /=10;
				else break;
			}

			while (num)
			{
				resp++;
				num /= 10;
			}

			resp += lead;
			dig.push(lead);
		}

		while (!dig.empty())
		{
			int maior = dig.top();
			resp -= maior;
			dig.pop();
			dig.push(0); //anna
			dig.pop();
		}

		cout << (resp>m ? "Sasha" : "Anna") << endl;
	}
	return 0;
}
