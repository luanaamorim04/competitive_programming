#include <iostream>

using namespace std;

int main()
{
    int n, k, d[45], res = 0;
    bool dp[]

    cin >> n >> k;

    for (int i = 0; i < k; i++)
        cin >> d[i];

    for (int i = 1; i <= n; i++)
    {
        if (dp[i] == true)
            for (int j = 0; j < k; j++)
            {
                if (i % d[j] == 0)
                    break;
            
                if (j == k - 1)
                    res++;
            }
    } 

    cout << res << endl;

}