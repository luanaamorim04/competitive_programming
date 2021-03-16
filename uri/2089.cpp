#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int soma, n, a[1009], dp[100009];

int main()
{_
    while (cin >> soma >> n && n)
    {
        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i <= soma; i++)
            dp[i] = 0;

        dp[0] = 1;
        for (int i = 0; i < n; i++)
            for (int j = soma; j >= a[i]; j--)
                dp[j] |= dp[j - a[i]];

        cout << (dp[soma] ? "sim" : "nao") << endl;
    }
}