#include <iostream>

using namespace std;

int main()
{
    int n, t[100001], soma1 = 0, soma2 = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
        soma1 += t[i];
    }

    for (int i = 0; i < n; i++)
    {
        soma1 -= t[i];
        for (int j = i; j < i + 1; j++)
        {
            soma2 += t[j];
            if (soma2 == soma1)
            {
                cout << j + 1 << endl;
                return 0;

            }
        }
    }



}