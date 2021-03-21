#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

// calcula a soma minima do canto superior esquerdo ate o canto inferior direito!!!!
int main()
{
    int n, m;
    cin >> n >> m;
    int sqr[n][m], dp[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> sqr[i][j];

    dp[0][0] = sqr[0][0];

    for (int row = 0; row < n; row++)
        for (int col = 0; col < m; col++)
        {
            if (row != 0 && col != 0)
                dp[row][col] = sqr[row][col] + min(dp[row - 1][col], dp[row][col - 1]);
            else if (col != 0)
                dp[row][col] = sqr[row][col] + dp[row][col - 1];
            else if (row != 0)
                dp[row][col] = sqr[row][col] + dp[row - 1][col];
        }

    cout << dp[n - 1][m - 1] << '\n';

}