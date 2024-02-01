#include <iostream>

using namespace std;

int n, arr[MAXN];

int f(int i, int k, int maior)
{
	if (maior) //i-1 foi maior
	{
		return f(i+1, k, 0) + max(0, arr[i] - arr[i-1] + 1);
	}
	else
	{
		return min(f(i+1, k+1, 1) + max(0, arr[i+1] - arr[i] + 1), f(i+1, k, 0));
	}

	return f(i+1, k+1, 1)
}

int32_t main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
}
