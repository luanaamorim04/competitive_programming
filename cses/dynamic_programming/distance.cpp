#include <iostream>

using namespace std;

string s1, s2;
int n, memo[5001][5001];

int f(int a, int b)
{
    if (a < 0) return b + 1;
    if (b < 0) return a + 1;
    if (memo[a][b] != -1) return memo[a][b];
    if (s1[a] == s2[b]) return f(a - 1, b - 1);
    return memo[a][b] = min(f(a - 1, b - 1), min(f(a - 1, b), f(a, b - 1))) + 1;
}

int main()
{
    cin >> s1 >> s2;

    for (int i = 0; i < 22; i++)
        for (int j = 0; j < 22; j++)
            memo[i][j] = -1;

    cout << f(s1.size() - 1, s2.size() - 1) << endl;
}