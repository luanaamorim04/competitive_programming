#include <iostream> 
#define MAXN (int) (2e5 + 10)
#define int long long

using namespace std;

int soma, n, p, arr[MAXN];

int32_t main()
{
	cin >> n >> p;
	int pp = p;
	for (int i = 1; i <= n; i++) 
	{
		cin >> arr[i];
		soma += arr[i];
	}
	for (int i = n+1; i <= 2*n; i++) arr[i] = arr[i-n];

	pp = p%soma;
	if (pp == 0)
	{
		cout << 1 << ' ' << n*(p/soma) << endl;
		return 0;
	}

	int resp = 1e9, tmp = 0, l = 1, a = 0, b = 0;
	for (int r = 1; r <= 2*n; r++)
	{	
		tmp += arr[r];
		while (tmp-arr[l] >= pp) tmp -= arr[l], l++;
		
		if (tmp >= pp && resp > r-l+1)
		{
			resp = r-l+1;
			a = l, b = r;
		}
	}

	cout << a << ' ' << n*(p/soma) + b-a+1 << endl;
}
