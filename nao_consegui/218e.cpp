#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#define INF 999999999
#define MOD 1000000007
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

map<int, int> mapa;
int n, k, arr[300001], resp, atual;

int main()
{_
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mapa[arr[i]] = i + 1;
    }

    sort(arr, arr+n);

    cin >> k;

    atual = INF;

    for (int i = k - 1; i < n; i++)
        if (atual > arr[i] - arr[i - k + 1])
        {
            atual = arr[i] - arr[i - k + 1];
            resp = i;
        }

    for (int i = resp; i < resp + k; i++)
        cout << mapa[arr[i]] << ' '; 

    cout << endl;
}