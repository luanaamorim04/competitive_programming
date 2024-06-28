#include <iostream>
#include <vector>
#define all(x) x.begin(), x.end()

using namespace std;

int dp[10][1<<10], resp;
char tab[10][10];

int32_t main()
{
	for (int i = 1; i <= 8; i++)
		for (int j = 1; j <= 8; j++)
			cin >> tab[i][j];

	vector<int> perm;
	for (int i = 1; i <= 8; i++) perm.push_back(i);
	do
	{
		int pode = 1;
		for (int i = 0; i < 8; i++)
		{
			if (tab[i+1][perm[i]] != '.') pode = 0;
		}

		resp += pode;
	} while (next_permutation(all(perm)));

	cout << resp << endl;

	dp[0][0] = 1;
	for (int col = 1; col <= 8; col++)
	{
		for (int mask = 0; mask < (1<<8); mask++) //linhas já usadas
		{
			if (__builtin_popcount(mask) != col) continue;
			for (int linha = 0; linha < 8; linha++)
			{
				if (!(mask&(1<<linha)) || tab[linha+1][col] != '.') continue;
				dp[col][mask] += dp[col-1][mask^(1<<linha)];
				printf("dp[%d][%d] = %d\n", col, linha+1, dp[col][mask]);
			}
		}
	}
	
	int resp = 0;
	cout << dp[8][(1<<8) - 1] << endl;
}
