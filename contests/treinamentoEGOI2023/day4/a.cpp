// #include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
// #define int long long
#define MAXN (int) (2e5 + 4)

using namespace std;

int n, cor[MAXN], idx, c, i;
unordered_map<int, int> last;

int32_t main()
{
	scanf("%d", &n);
	for (i = 1; i <= n; ++i)
	{
		scanf("%d", &cor[i]);
		last[cor[i]] = i;
	}

	idx = 1, c = cor[1];
	while (idx <= n)
	{
		while (idx <= last[c])
		{
			printf("%d\n", c);
			idx++;
		}
		c = cor[idx];
	}
}