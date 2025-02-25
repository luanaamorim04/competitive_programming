#include <iostream>
#define MAXN (int) (3e5 + 10)
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
		while (arr[r]-arr[l+1] > s) l++;

		resp += (l-1) + (arr[r]-arr[l]>s);
	}

	cout << resp << endl;
}

