#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <iomanip>
#define vii vector< pair<int, int> >
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define f first
#define s second

using namespace std;

map<string, double> frutas;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        double price, res = 0;
        int m, qnt;
        cin >> m;
        string fruit;
        for (int j = 0; j < m; j++)
        {
            cin >> fruit >> price;
            frutas[fruit] = price;
        }
        int p;
        cin >> p;
        for (int j = 0; j < p; j++)
        {
            cin >> fruit >> qnt;
            res += frutas[fruit] * qnt;
        }
        cout << "R$ " << fixed << setprecision(2) << res << endl;
    }
}