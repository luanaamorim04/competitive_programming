#include <iostream>
#include <map>
#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, fat[9], x, aux, maxn;
map<int, int>freq[10];

int main()
{_
    cin >> n;
    fat[0] = 1;
    for (int i = 1; i <= n; i++)
        fat[i] = fat[i - 1] * i;

    aux = fat[n]-1;

    while (aux--)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> x;
            freq[j][x]++;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (freq[i][j] < (fat[n] / n)) cout << j << ' ';
        }
    }

    cout << endl;
}