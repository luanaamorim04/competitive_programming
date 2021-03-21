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

long long n, arr[200001], esq[200001], dir[200001], resp;

int main()
{_
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        esq[i] = i - 1;
        cin >> arr[i];
        while (arr[esq[i]] >= arr[i]) esq[i] = esq[esq[i]];
    }

    for (int i = n; i >= 1; --i)
    {
        dir[i] = i + 1;
        while (arr[dir[i]] >= arr[i]) dir[i] = dir[dir[i]];
        resp += (arr[i])*(i - esq[i])*(dir[i] - i);
    }

    cout << resp << endl;
}