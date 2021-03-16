#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#define INF 999999999
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int c, arr[10005], ans, pulo, zero, erro;

int main()
{_
    cin >> c;
    for (int i = 0; i < c; i++)
    {
        cin >> arr[i];
        if (!arr[i]) zero++;
        else zero = 0;
        if (zero == 2) erro = 1;
    }

    if (erro)
    {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < c - 1; i++)
    {
        ans++;
        if (i + 1 == c - 1 || i + 2 == c - 1) break;
        if (!arr[i + 1]) i++;
        else if (arr[i + 2]) i++;
    }

    cout << ans << endl;
}