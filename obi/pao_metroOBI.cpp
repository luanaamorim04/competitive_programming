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
#define MAX 10009
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, k, pao[MAX], ini, meio, fim;

int d(int x)
{
    int ans = 0;
    for (int i = 0; i < k; i++)
    {   
        ans += (pao[i]/x);
    }

    return ans;
}

int main()
{_
    cin >> n >> k;
    for (int i = 0; i < k; i++)
        cin >> pao[i];

    ini = 1, fim = MAX;
    while (ini <= fim)
    {
        meio = ini + (fim-ini)/2;

        if (d(meio) >= n) ini = meio + 1;
        else fim = meio - 1;
    }

    cout << ini - 1 << endl;
}