#include <iostream>
#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int N, M, arr[100002], X, ini, meio, fim, ans;

int main()
{_
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    cin >> M;
    cout << endl;

    while (M--)
    {
        cin >> X;
        ini = 1, fim = N+1, ans = N+1;
        while (ini <= fim)
        {
            meio = ini + (fim-ini)/2;
            if (arr[meio] == X)
            {
                ini = meio + 1;
                fim = meio; 
                ans = meio;
            }
            else if (arr[meio] > X)
            {
                fim = meio - 1;
                ans = meio;
            }
            else
            {
                ini = meio + 1;
            }
        }

        cout << ans << endl;
    }

}