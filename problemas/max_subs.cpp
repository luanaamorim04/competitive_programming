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

int n, m, arr[40], resp;
vector<int> somas;

int bb(int x)
{
    int ini = 0, meio, fim = somas.size() - 1;
    int k = m - x - 1;
    while (ini <= fim)
    {
        meio = ini + (fim-ini)/2;
        if (somas[meio] <= k) ini = meio + 1;
        else fim = meio - 1;
    }

    if (!ini) return 0;
    return (somas[ini - 1] + x) % m;
}   

int main()
{_
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr[i] %= m;
    }

    int k = n/2;

    for (int mask = 0; mask < (1<<k); mask++)
    {
        int sum = 0;
        for (int j = 0; j < k; j++)
        {
            if (mask & (1<<j)) sum = (sum + arr[j]) % m;
        }
        somas.push_back(sum);
    }

    sort(somas.begin(), somas.end());

    for (int mask = 0; mask < (1<<(n-k)); mask++)
    {
        int sum = 0;
        for (int j = 0; j < n-k; j++)
        {
            if (mask & (1<<j)) sum = (sum + arr[n - 1 - j]) % m;
        }
        
        resp = max(resp, bb(sum));
    }

    cout << resp << endl;
}