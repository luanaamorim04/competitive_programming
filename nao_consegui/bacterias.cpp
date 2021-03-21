#include <iostream>
#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, d, c;

struct bac
{
    int id, dias, qnt;
};

int main()
{_
    cin >> n;
    bac bacterias[n], tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> d >> c;
        tmp.id =  i;
        tmp.dias = d;
        tmp.qnt = c;
        bacterias[i] = tmp;
    }

    
}