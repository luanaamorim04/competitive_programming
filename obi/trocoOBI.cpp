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

int N, X, a[100009], dp[100009];

int main()
{_
    cin >> X >> N;

    for (int i = 1; i <= N; i++)
        cin >> a[i];

    dp[0] = 1;
    for (int i = 1; i <= N; i++)
        for (int j = X; j >= a[i]; j--)
            dp[j] |= dp[j - a[i]];

    cout << (dp[X] ? 'S' : 'N') << endl;
}