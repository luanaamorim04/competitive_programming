#include <iostream>
#include <map>
#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

long long N, arr[200001], max_sum, ini, fim, meio, ans;

int main()
{_
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    for (int i = 1; i <= N; i++)
    {
        max_sum = arr[N] - arr[i];
        ini = 1, fim = i, ans = -1;
        while (ini <= fim)
        {
            meio = ini + (fim-ini)/2;
            if (arr[meio] == max_sum)
            {
                ans = meio;
                break;
            }
            else if (arr[meio] > max_sum)
            {
                fim = meio - 1;
            }
            else
            {
                ini = meio + 1;
            }
        }

        if (ans != -1)
        {
            cout << arr[ans] << endl;
            return 0;
        }
    }

    cout << 0 << endl;
}