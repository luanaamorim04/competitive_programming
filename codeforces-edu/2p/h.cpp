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
	int soma = 0, i = 1;
	while (soma+A <= s && i <= n) soma += A, v.push_back(a[i++]);

	int dist = 
	for (int i = v.size()-1; i >= 0; i--)
	{

	}


}
