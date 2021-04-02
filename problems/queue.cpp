#include <iostream>
#include <queue>

using namespace std;

const int mod = 1000007;
long long k, n, t, soma, i;

int main()
{
    cin >> t;
    while (t--)
    {
        queue<long long> fib;
        soma = 0;
        cin >> k >> n;
        for (i = 0; i < n; i++)
        {
            if (i < k)
            {
                fib.push(i);
                soma  = (soma + i) % mod;
            }
            else
            {
                fib.push(soma);
                soma = (soma + soma - fib.front() + mod) % mod;
                fib.pop();
            }
        }
        cout << fib.back() % 1000007 << endl;
    }
}