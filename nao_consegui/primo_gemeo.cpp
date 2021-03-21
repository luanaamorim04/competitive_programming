#include <iostream>
#include <string>

using namespace std;

int composto[1000009], q, a[1000005], b[100005], maxn, psa[1000009], gemeo[1000005];

void crivo(int x)
{
    for (int i = 2; i <= x; i++)
    {
        if (!composto[i])
        {
            if (!composto[i - 2])
            {
                gemeo[i - 2] = 1;
                gemeo[i] = 1;
            }
            for (int j = 2; i * j <= x; j++)
            {
                composto[i*j] = 1;
            }
        }

        if (i > 2) psa[i - 2] += psa[i - 3] + gemeo[i - 2];
    }

    return;
}


int main()
{
    cin >> q;
    psa[0] = 0;
    composto[0] = 1;
    composto[1] = 1;
    for (int i = 0; i < q; i++)
    {
        cin >> a[i] >> b[i];
        if (maxn < max(a[i], b[i])) maxn = max(a[i], b[i]);
    }

    crivo(maxn + 2);

    for (int i = 0; i < q; i++)
    {
        cout << psa[max(b[i], a[i])] - psa[min(a[i], b[i]) - 1] << endl;
    }
}