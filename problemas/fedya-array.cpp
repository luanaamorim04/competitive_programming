#include <iostream>

using namespace std;

int t, a, b;

int32_t main()
{
	cin >> t;
	while (t--)
	{
		cin >> a >> b;
		cout << 2*(a-b) << endl;
		int curr = a;
		while (curr != b)
		{
			cout << curr << ' ';
			curr--;
		}

		curr = b;
		while (curr != a)
		{
			cout << curr << ' ';
			curr++;
		}

		cout << endl;
	}
}
