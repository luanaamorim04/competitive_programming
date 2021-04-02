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

string num, out;

int N, M, memo[1009][1009];

int f(int pos, int k)
{
    if (pos == M) return !(k % N);
    if (memo[pos][k] != -1) return memo[pos][k];
    if (num[pos] != '?') 
    {
        out[pos] = num[pos];
        return memo[pos][k] = f(pos + 1, (k*10 + num[pos] - '0') % N);
    }

    int ans = 0;
    for (int i = (pos ? 0 : 1); i < 10; i++)
    {
        out[pos] = i + '0';
        ans |= f(pos + 1, (k*10 + i) % N);
        if (ans) return memo[pos][k] = 1;
    }

    return memo[pos][k] = 0;
}

int main()
{_
    cin >> num >> N;
    M = num.size();
    out = num;

    for (int i = 0; i <= M; i++)
        for (int j = 0; j <= N; j++)
            memo[i][j] = -1;

    if (!f(0, 0)) 
        cout << '*' << endl;
    else 
        cout << out << endl;
}