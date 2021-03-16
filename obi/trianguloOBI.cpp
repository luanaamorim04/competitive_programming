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

int arr[4], ok;

int check(int x)
{
    int maior, soma = 0;
    for (int i = 3; i >= 0; i--)
    {
        maior = i;
        if (i != x) break;
    }

    for (int i = 0; i < 4; i++)
    {
        if (i == x || i == maior) continue;
        soma += arr[i];
    }

    return soma > arr[maior];
}

int main()
{_
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];

    sort(arr, arr+4);

    for (int i = 0; i < 4; i++)
    {
        if (check(i)) 
        {
            cout << 'S';
            return 0;
        }
    }

    cout << 'N';
}