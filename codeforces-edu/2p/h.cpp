#include <iostream>

using namespace std;

int32_t main()
{
	cin >> n >> m >> s >> A >> B;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];

	if (A > B)
	{
		swap(A, B);
		swap(a, b);
	}

	sort(a+1, a+n+1, greater<int>());
	sort(b+1, b+m+1, greater<int>());
	int soma = 0, idx = 1, idy = 1, diff = (B+A-1)/A;
	while (soma+A <= s && idx <= n) soma += A, v.push_back(a[idx++]);


	int l = idx-1;
	for (int i = 1; i <= m; i++)
	{
		int sum = 0, c;
		while (sum < b[idy] &&)
	}


}
