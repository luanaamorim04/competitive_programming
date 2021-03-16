#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int N, K;
long long memo[110][22][110];

long long f(int soma, int k, int x)
{
    if (soma < 0 || k > K) return 0;
    if (soma == 0 && k == K) return 1;
    if (memo[soma][k][x] != -1) return memo[soma][k][x];
    return memo[soma][k][x] = f(soma - x, k + 1, x + 1) + f(soma, k, x + 1);
}

int main()
{_
    cin >> N >> K;
    
    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= K; j++)
            for (int k = 0; k <= N; k++)
                memo[i][j][k] = -1;  

    cout << f(N, 0, 1) << endl;
}