#include <iostream>

using namespace std;

int n, a, tot;

long long bb(int x)
{
    long long ini = 1, fim = (1e9), meio, ans;
    while (ini <= fim)
    {
        meio = (ini + fim) / 2;
        long long k = (meio*(meio + 1)) / 2;
        if (k > x) fim = meio - 1, ans = k - x;
        else ini = meio + 1;
    }

    return ans;
}   

int main()
{
    cin >> n;
    while (n--)
    {
        cin >> a;
        cout << bb(a) << endl;
    }
}