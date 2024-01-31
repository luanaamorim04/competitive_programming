//#include <bits/stdc++.h> 
#include <vector>
#include <iostream>
#define int long long
#define MAXN (int) (1e5)
#define par pair<int, int>
#define INF (int) (1e9)
#define max(a, b) (a>b?a:b)
#define min(a, b) (a<b?a:b)

using namespace std;

int t, uniao[8], r1[4], r2[4];

int inside(par p, int a[])
{
	auto[x, y] = p;
	return (a[0] <= x && x <= a[2] && a[1] <= y && y <= a[3]);
}

int32_t main()
{
	int x[] = {0, 2, 4, 6};
	int y[] = {1, 3, 5, 7};

	cin >> t;
	while (t--)
	{
		for (int i = 0; i < 4; i++)
		{
			cin >> r1[i];
			uniao[i] = r1[i];
		}
		for (int i = 0; i < 4; i++)
		{
			cin >> r2[i];
			uniao[i+4] = r2[i];
		}
		int resp = 0;

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				for (int ii = 0; ii < 4; ii++)
					for (int jj = 0; jj < 4; jj++)
					{
						int ok = 1;
						par p1 = {uniao[x[i]], uniao[y[j]]};
						par p2 = {uniao[x[i]], uniao[y[jj]]};
						par p3 = {uniao[x[ii]], uniao[y[j]]};
						par p4 = {uniao[x[ii]], uniao[y[jj]]};
						

						ok &= (inside(p1, r1) || inside(p1, r2));
						ok &= (inside(p2, r1) || inside(p2, r2));
						ok &= (inside(p3, r1) || inside(p3, r2));
						ok &= (inside(p4, r1) || inside(p4, r2));

						if (ok) resp = max(resp, abs(uniao[x[i]]-uniao[x[ii]])*abs(uniao[y[j]]-uniao[y[jj]]));
					}

		cout << resp << endl;
	}
}	
