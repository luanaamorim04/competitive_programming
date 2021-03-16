#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#define INF 999999999
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, c, I, p, x, foi[1009], zero[1009];

int main()
{_
    cin >> n >> c;
    for (int i = 0; i < c; i++)
    {
        cin >> p >> I;
        zero[i] = p;
        while (I--)
        {
            cin >> x;
            foi[x] = 1;
        }
    }

    sort(zero, zero+c);

    for (int i = 0; i < c; i++)
        if (!foi[zero[i]]) cout << zero[i] << endl;
}