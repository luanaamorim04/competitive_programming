#include <iostream>
#include <vector>
#include <queue>
#define _ ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{_
    string res[] = {"Rudolph", "Dasher", "Dancer", "Prancer", "Vixen", "Comet", 
    "Cupid", "Donner", "Blitzen"};

    long long n = 9, x, a = 0;
    while (n--)
    {
        cin >> x;
        a += x % 9;
    }

    cout << res[(a % 9)] << endl;

}