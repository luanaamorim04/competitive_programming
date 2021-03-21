#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring>
#define ll long long
#define INF 99999999
#define MAX 300000
#define MOD 1000000007
#define par pair<int, int>
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, arr[200001], resp[200001];

int main()
{_
    cin >> n;
    arr[0] = -1;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        resp[i] = i - 1;
        while (arr[resp[i]] >= arr[i]) resp[i] = resp[resp[i]];
        cout << resp[i] << ' ';
    }
    cout << endl;
}