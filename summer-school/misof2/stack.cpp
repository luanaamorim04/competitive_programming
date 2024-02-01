#include <iostream> 
#define int long long
#define MAXN (int) (1e5)
#define INF (int) (1e9)

using namespace std;


int n, arr[MAXN];

int32_t main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	arr[0] = INF;
	for (int i = 0; i <= n; i++)
	{
		int ok = 1;
		if (arr[i+1] > arr[i]) continue;
		for (int j = 2; j <= i; j++)
			ok &= (arr[j] >= arr[j-1]);
		for (int j = i+2; j <= n; j++)
			ok &= (arr[j] >= arr[j-1]);
		
		if (i)ok &= (arr[1] >= arr[n]);
		if (ok)
		{
			cout << "Phew" << endl;
			return 0;
		}
	}	

	cout << "Lie" << endl;

}
