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

int f[200001], ff[200001], x, n, t, arr[200001], maior, c, resp;

int main()
{_
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        f[arr[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        ff[f[arr[i]]]++;
        if (maior < ff[f[arr[i]]])
        {
            maior = ff[f[arr[i]]];
            c = f[arr[i]];
        }
    }

    for (int i = 0; i < n; i++)
    {
        resp += max(0, f[arr[i]] - c);
    }

    
}