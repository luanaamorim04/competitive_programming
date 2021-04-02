#include <iostream>
#include <queue>
#include <map>
#define _ ios_base::sync_with_stdio(false); cin.tie(0);
#define mp make_pair

using namespace std;

queue<pair<int, int> > nivel;
int p, n, m, fs, sc, k;
map<int, int> passou;

int main()
{_
    while (1)
    {
        cin >> n >> m >> k;
        if (n == 0 && m == 0 && k == 0) return 0;
        nivel.push(mp(n, 0));

        while (k--)
        {
            cin >> p;
            passou[p] = 1;
        }
        
        while (1)
        {
            fs = nivel.front().first;
            sc = nivel.front().second;
            if (nivel.empty())
            {
                cout << -1 << endl;
                break;
            } 
            nivel.pop();

            if (fs > 100000 || fs <= 0) continue;

            if (passou[fs] == 1) continue;
            passou[fs] = 1;

            if (fs == m)
            {
                cout << sc << endl;
                break; 
            }

            nivel.push(mp(fs + 1, sc + 1));
            nivel.push(mp(fs - 1, sc + 1));
            nivel.push(mp(fs * 2, sc + 1));
            nivel.push(mp(fs * 3, sc + 1));
            if (fs % 2 == 0) nivel.push(mp(fs / 2, sc + 1));
        }

        while (!nivel.empty()) nivel.pop();
        passou.clear();
    }
}