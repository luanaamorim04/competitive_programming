#include <iostream>

using namespace std;

int main()
{
    long long n, soma = 0, a;
    cin >> n;
    for (int i = 1; i < n; i++)
    {   
        cin >> a;
        soma += a;
    }

    cout << (n*(n + 1) / 2) - soma << endl;
}