#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <stack>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define MAXN 1e5 + 9
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int k, num;

int sum(int x)
{
    int dig = 0;
    while (x)
    {
        dig += x % 10;
        x /= 10;
    }

    return dig == 10;
}

int main()
{_
    cin >> k;
    num = 0;
    while (k)
    {
        num++;
        if (sum(num)) k--;
    }

    cout << num << endl;
}