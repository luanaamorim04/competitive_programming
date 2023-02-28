#include <iostream>
#define MAXN (int)(2000)

using namespace std;

int n, k, arr[MAXN];

int query(int idx)
{
	char c;
	cout << "? " << idx << endl;
	cin >> c;
	return c=='Y';
}

void erase()
{
	cout << 'R' << endl;
}

int main()
{
	cin >> n >> k;
	// if (k == 1)
	// {
	// 	for (int i = 1; i <= n; i++)
	// 	{
	// 		for (int j = i+1; j <= n; j++)
	// 		{
	// 			query(i);
	// 			if (query(j)) arr[j] = 1;

	// 		}
	// 	}
	// }

	if (k != 1) k>>=1;
	for (int i = 1; i <= n-k; i += k)
	{
		for (int x = i; x < i+k; x++)
			if (query(x)) arr[x] = 1;

		for (int j = i+k; j <= n; j++)
		{
			if (query(j)) arr[j] = 1;
			query(j-(((j-i)/k)*k));
		}

		erase();
	}

	int resp = 0;
	for (int i = 1; i <= n; i++)
		resp += (!arr[i]);

	cout << "! " << resp << endl;
}