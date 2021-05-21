#include <iostream>
#include <map>
#include <stdio.h>
#include <algorithm>
#define ll long long
 
std::map<ll, int> sums;
int n, k, i, j;
ll arr[41], soma, resp, m;
 
int main()
{
	scanf("%d%lld", &n, &m);
	k = (n>>1);
	for (i = 0; i < n; i++) scanf("%lld", &arr[i]);

	std::sort(arr, arr+n);
 
	for (i = 0; i < (1<<k); ++i)
	{
		soma = 0;
		for (j = 0; j < k; ++j)
			if (i & (1<<j)) soma += arr[j];
		
		if (soma <= m) ++sums[soma];
	}
 
	k = n-k;
 
	for (i = 0; i < (1<<k); ++i)
	{
		soma = 0;
		for (j = 0; j < k; ++j)
			if (i & (1<<j)) soma += arr[n-j-1];
 
		if (sums.count(m - soma)) resp += sums[m - soma];
	}
 
	printf("%lld\n", resp);
 	return 0;
 
}