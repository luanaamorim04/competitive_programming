#include <iostream>
#include <map>
#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, soma, res[6];

int main()
{_
    cin >> n;
    res[0] = n/100;
    n -= 100*res[0];
    res[1] = n/50;
    n -= 50*res[1];
    res[2] = n/25;
    n -= 25*res[2];
    res[3] = n/10;
    n -= 10*res[3];
    res[4] = n/5;
    n -= 5*res[4];
    res[5] = n;

    for (int i = 0; i <= 5; i++)
        soma += res[i];

    cout << soma << endl;

    for (int i = 0; i <= 5; i++)
        cout << res[i] << endl;
}