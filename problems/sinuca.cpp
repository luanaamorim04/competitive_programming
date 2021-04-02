#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#define INF 999999999
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, k[70];

void func(int n)
{
    for (int i = 1; i < n; i++)
    {
        if (k[i] == k[i - 1])
            k[i - 1] = 1;
        else 
            k[i - 1] = -1;
    }

    if (n == 1) cout << (k[0] == 1 ? "preta\n" : "branca\n");
    else func(n - 1);
}

int main()
{_
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> k[i];
    }

    func(n);
}