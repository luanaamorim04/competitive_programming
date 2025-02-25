#include <iostream>
#define MAXN (int) (2e5 + 10)
#define int long long

using namespace std;

int n, s, arr[MAXN], resp, soma;

int32_t main()
{
	cin >> n >> s;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	int l = 1;
	for (int r = 1; r <= n; r++)
	{
		soma += arr[r];
		while (soma > s) soma -= arr[l], l++;

		resp += (r-l+1)*(r-l+2)/2;
	}

	cout << resp << endl;
}
