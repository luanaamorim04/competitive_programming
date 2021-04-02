#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#define ll long long
#define INF 99999999
#define MAX 300000
#define MOD 1000000007
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, arr[500001], resp, menor, k, sum;

int main()
{_
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += (i < k)*arr[i];
    }

    menor = INF;
    for (int i = 0; i <= n - k; i++)
    {
        if (menor > sum)
        {
            menor = sum, resp = i + 1;
        }
        sum -= arr[i];
        sum += arr[i + k];
    }

    cout << resp << endl;
}