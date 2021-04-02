#include <iostream>
#include <queue>
#include <map>
#define mp make_pair
#define _ ios_base::sync_with_stdio(false), cin.tie(0);


using namespace std;

int n, m, fs, sc;
map<int, int> passei;
queue<pair<int, int> > nivel;

int main()
{_
    cin >> n >> m;
    nivel.push(mp(n, 0));
    while (1)
    {
        fs = nivel.front().first;
        sc = nivel.front().second;
        nivel.pop();

        if (passei[fs] == 1) continue;

        if (fs == m)
        {
            cout << sc << endl;
            return 0;
        }

        nivel.push(mp(fs * 2, sc + 1));
        nivel.push(mp(fs * 3, sc + 1));
        nivel.push(mp(fs + 7, sc + 1));
        nivel.push(mp(fs - 7, sc + 1));
        nivel.push(mp(fs / 2, sc + 1));
        nivel.push(mp(fs / 3, sc + 1));

        passei[fs] = 1;
    }
}