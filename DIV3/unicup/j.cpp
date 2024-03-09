#include <iostream>

using namespace std;

int n, t;

int ask(int u, int v)
{
	int r;
	cout << "? " << u << ' ' << v << endl;
	cin >> r;
   	return r;	
}

void ans(int r)
{
	cout << "! " << r << endl;
	return;
}

int diff(int a, int b, int c)
{
	for (int i = 1; i <= n; i++)
		if (i != c && i != a && i != b) return i;
	return -1;
}

int32_t main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		int ok = 0, idx = 1;
		while (idx < n)
		{
			int r = ask(idx, idx+1);
			if (r == 1)
			{
				int r1 = ask(idx, diff(idx, idx+1, 0));
				int centro = 0;
				if (r1 == 1)
				{
					if (ask(idx, diff(idx, idx+1, diff(idx, idx+1, 0))))
						centro = 1;
				}
				else
				{
					r1 = ask(idx+1, diff(idx, idx+1, 0));
					if (r1 && ask(idx+1, diff(idx, idx+1, diff(idx, idx+1, 0))))
						centro = 1;
				}
				ans(centro + 1);
				ok = 1;
				break;
			}
			idx += 2;
		}

		if (ok) continue;
		if ((n&1) == 0) 
		{
			ans(1);
		}
		else
		{
			int r = ask(n, n-1);
			if (!r) ans(1);
			else
			{
				int r1 = ask(n, diff(n, n-1, 0));
				if (!r1) ans(1);
				else
				{
					int r2 = ask(n, diff(n, n-1, diff(n, n-1, 0)));
					if (!r2) ans(1);
					else ans(2);
				}
			}
		}
	}
}
