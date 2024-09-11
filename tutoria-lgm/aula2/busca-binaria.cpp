#include <iostream>

using namespace std;

int n, k, arr[1000];

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	int ini = 1, meio, fim = n;
	while (ini <= fim)
	{
		meio = (ini+fim)/2;
		if (arr[meio] >= k) fim = meio - 1;
		else ini = meio + 1;
	}

	// lower-bound: menor numero maior ou igual a k
	cout << (fim + 1 <= n ? fim + 1 : -1) << endl;
}
