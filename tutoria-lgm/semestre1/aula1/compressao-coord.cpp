#include <iostream>
#include <map>
#define MAXN (int) (2e5 + 10)

using namespace std;

int n, arr[MAXN];
map<int, int> val;

int32_t main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	
	sort(arr, arr+n);

	for (int i = 0; i < n; i++)
		val[arr[i]] = i;

	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ' << val[arr[i]] << endl;
	cout << endl;

}
