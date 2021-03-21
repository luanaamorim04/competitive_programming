#include <iostream>

using namespace std;

int main()
{
    int n, counter = 0;
    cin >> n;
    int v[n];
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int last = 2;

    for (int i = 0; i < n; i++)
    {
        if (v[i] != last)
        {
            last = v[i];
            counter++;
        }
    }

    cout << counter;
}