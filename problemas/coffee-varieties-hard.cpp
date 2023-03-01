#include <iostream>
#define MAXN 2000

using namespace std;

int n, k, arr[MAXN], resp;

int query(int x)
{
	char c;
	cout << "? " << x << endl;
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
	for (int i = 1; i <= n-k+1; i+=k)
	{
		for (int j = i; j < i+k; j++)
			arr[j] |= query(j);
		erase();
	}

	for (int i = 1; i <= n+1-(2*k); i+=k)
	{
		for (int j = i+k; j <= n+1-k; j+=k)
		{
			for (int a = i; a < i+(k>>1); a++) query(a);

			for (int c = j; c < j+(k>>1); c++) arr[c] |= query(c);

			for (int b = i+(k>>1); b < i+k; b++) arr[b] |= query(b);

			for (int d = j+(k>>1); d < j+k; d++) arr[d] |= query(d);

			erase();

			for (int a = i; a < i+(k>>1); a++)
				query(a);

			for (int d = j+(k>>1); d < j+k; d++)
				arr[d] |= query(d);

			erase();
		}		
	}

	for (int i = 1; i <= n; i++)
		resp += (!arr[i]);

	cout << "! " << resp << endl;
}
