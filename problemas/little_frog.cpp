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

int n, i;

int main()
{_
    cin >> n;
    i = 1;
    cout << n << ' ';
    for (int dif = n - 1; dif >= 1; dif--)
    {
        i *= -1;
        n += (dif*i);
        cout << n << ' ';
    }
}