#include <iostream>
#define MOD (int) (1e9 + 7)
#define MAX 2

using namespace std;

long long n;

struct matrix
{
    long long m[MAX][MAX];
};

matrix t, p, ans;

matrix mult(matrix a, matrix b)
{
    matrix ans;
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
        {
            ans.m[i][j] = 0;
            for (int k = 0; k < MAX; k++)
                ans.m[i][j] = (ans.m[i][j] + ((a.m[i][k]*b.m[k][j]) % MOD)) % MOD; 
        }

    return ans;
}

matrix fexpo(matrix a, long long b)
{
    matrix ans;
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            ans.m[i][j] = (i==j);

    while (b)
    {
        if (b & 1) ans = mult(ans, a);
        a = mult(a, a);
        b >>= 1;
    }

    return ans;
}

int main()
{
    cin >> n;
    t.m[0][0] = t.m[0][1] = t.m[1][0] = 1, t.m[1][1] = 0;
    p.m[0][0] = p.m[0][1] = p.m[1][1] = 0, p.m[1][0] = 1;
    t = fexpo(t, n);
    ans = mult(t, p);
    cout << ans.m[0][0] << endl;
}