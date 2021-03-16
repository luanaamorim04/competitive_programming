#include <iostream>
#include <map>
#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int n, a, b;
char c;
pair<int, int> start;
map<pair<int, int>, char> mapa;
map<int, int> pecas;

int main()
{_
    cin >> n;
    while (n--)
    {
        cin >> a >> c >> b;
        mapa[make_pair(a, b)] = c;
        pecas[a] = b;
        if (a == 0)
        {
            start = make_pair(a, b);
            cout << c;
        }
        while (pecas[start.second])
        {
            start = make_pair(start.second, pecas[start.second]);
            cout << mapa[start];
        }
    }
    cout << endl;
}