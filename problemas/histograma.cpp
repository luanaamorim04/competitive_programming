#include <iostream>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

long long i, n, h[100002], esq[100002], dir[100002], resp, k;

int main()
{_
    h[0] = -1;
    while (cin >> n && n)
    {
        resp = h[n + 1] = -1;
        for (i = 1; i <= n; ++i)
        {
            cin >> h[i];
            esq[i] = i - 1;
            while (h[esq[i]] >= h[i]) esq[i] = esq[esq[i]];
        }

        for (i = n; i >= 1; --i)
        {
            dir[i] = i + 1;
            while (h[dir[i]] >= h[i]) dir[i] = dir[dir[i]];
            k = h[i]*(dir[i] - esq[i] - 1);
            if (resp < k) resp = k;
        }

       cout << resp << endl;
    }
}