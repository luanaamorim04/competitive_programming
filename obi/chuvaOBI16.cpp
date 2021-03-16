#include <iostream>

using namespace std;

int h[100000], counter = 0;

void count(int ini, int fim)
{
    if (ini == fim) return;

    int b = min(h[ini], h[fim]);
    if (b == h[ini])
    {
        for (int i = ini + 1; i < fim; i++)
        {
            if (h[i] < b)
                counter++;
            else
            {
                count(i, fim);
                return;
            }
        }
        return;
    }
    else
    {
        for (int i = fim - 1; i > ini; i--)
        {
            if (h[i] < b)
                counter++;
            else
            {
                count(ini, i);
                return;
            }
        }
        return;
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> h[i];

    count(0, n - 1);
    cout << counter << '\n';

}