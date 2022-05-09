#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring>
#include <set>
#define ll long long
#define INF (1e9)
#define MAX (2e5)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
using namespace std;
 
ll t, n, arr[1<<20], soma, sum, achou, c[1<<20], x;
 
int main()
{_
	cin >> t;
	while (t--)
	{
		cin >> n;
		soma = 0;
		for (int i = 0; i < n + 2; i++)
		{
			cin >> arr[i];
			soma += arr[i];
			c[i] = arr[i];
		}
 
		sort(c, c+n+2);
 
		sum = c[n+1];
		x = -1;
 
		for (int i = 0; i < n+1; i++)
		{
			if (soma - c[i] - sum == sum)
			{
				x = c[i];
			}
		}
 
		if (x==-1)
		{
			if (soma - c[n] - c[n+1] == c[n])  x = c[n+1], sum = c[n];
			else 
			{
				cout << -1 << endl;
				continue;
			}
		} 
 
		for (int i = 0; i < n+2; i++)
		{
			if (arr[i] == sum)
			{
				sum = -1;
			}
			else if (arr[i] == x)
			{
				x = -1;
			}
			else
			{
				cout << arr[i] << ' ';
			}
		}
 
		cout << endl;
	}
}
 
