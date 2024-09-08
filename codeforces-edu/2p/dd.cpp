#include <iostream> 
#include <vector> 
#define MAXN (int) (2e5 + 10)

using namespace std;

int x, a, b, c, d, freq[MAXN][5];


int32_t main()
{
	cin >> a;
	for (int i = 1; i <= a; i++) 
	{
		cin >> x;
		freq[x][0]++;
	}
	cin >> b;
	for (int i = 1; i <= b; i++) 
	{
		cin >> x;
		freq[x][1]++;
	}
	cin >> c;
	for (int i = 1; i <= c; i++) 
	{
		cin >> x;
		freq[x][2]++;
	}
	cin >> d;
	for (int i = 1; i <= d; i++) 
	{
		cin >> x;
		freq[x][3]++;
	}

	int l = 1, q[] = {0, 0, 0, 0}, resp = 1e9; 
	for (int r = 1; r < MAXN; r++)
	{
		for (int i = 0; i < 4; i++) q[i] += freq[r][i];
		while (1)
		{
			int ans = 1;
			for (int i = 0; i < 4; i++) ans &= (q[i] - freq[l][i] > 0);
			if (!ans) break;
			for (int i = 0; i < 4; i++) q[i] -= freq[l][i];
			l++;
		}	

		if (q[0] && q[1] && q[2] && q[3] && resp > r-l+1)
		{
			resp = r-l+1;
			a = l;
		}
	}

	int r[] = {0, 0, 0, 0};
	for (int i = a; i < a+resp; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (q[j] && freq[i][j]) q[j]=0, r[j] = i;
		}
	}

	for (int i : r) cout << i << ' ';
	cout << endl;

	
}
