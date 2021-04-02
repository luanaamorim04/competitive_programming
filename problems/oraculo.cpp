#include <iostream>

using namespace std;

long long fact(int a, int b)
{
    if (a <= 1) return 1;
    long long res = a * fact(a - b, b);
    return res;
}

int main()
{
    int m, n, k;
    string s;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> n;
        cin >> s;
        k = s.size();
        cout << fact(n, k) << endl;
    }
}