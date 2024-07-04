#include <iostream>
#include <algorithm>
#include <numeric>
#include <math.h>
#define INF 1e18
#define int long long
#define ii pair<int, int>

using namespace std;

int n, a, b, c, l, r;

ii integra(int a, int b, int c, int l, int r)
{
	return {abs(a*r*r*r*2 + b*r*r*3 + c*r*6 - a*l*l*l*2 - b*l*l*3 - c*l*6), 6};
}

ii raizes(int a, int b, int c)
{
	if (b*b < 4*a*c) return {-INF, INF};
	int del = round(sqrt(b*b - 4*a*c));
	return {(-b - del)/(2*a), (-b + del)/(2*a)};
}

ii soma(ii a, ii b)
{
	int num = a.first*b.second + b.first*a.second;
	int de = a.second*b.second;
	int g = gcd(num, de);
	return {num/g, de/g};
}

int32_t main()
{
	cin >> n;
	while (n--)
	{
		cin >> a >> b >> c >> l >> r;
		ii resp = {0, 1};
		ii x0 = raizes(a, b, c);

		if (x0.first <= l && x0.second >= r)
		{
			resp = soma(resp, integra(a, b, c, l, r));
		}
		else if (x0.first > l && x0.second < r)
		{
			resp = soma(integra(a, b, c, l, x0.first), integra(a, b, c, x0.first, x0.second));
			resp = soma(resp, integra(a, b, c, x0.second, r));
		}
		else if (x0.first > l)
		{
			resp = soma(integra(a, b, c, l, x0.first), integra(a, b, c, x0.first, r));
		}
		else if (x0.second < r) 
		{
			resp = soma(integra(a, b, c, l, x0.second), integra(a, b, c, x0.second, r));
		}

		cout << resp.first << "/" << resp.second << endl;
	}
}
