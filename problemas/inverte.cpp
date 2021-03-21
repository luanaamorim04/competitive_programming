#include <iostream>
#include <queue>
#include <vector>
#include <map>
#define _ ios_base::sync_with_stdio(false); cin.tie(0);
#define mp make_pair


using namespace std;

vector<int> inverte;
queue<pair<int, int> > nivel;
map<int, int> passou;

int inverter(int x)
{
    int res = 0, a = 1;
    while (x > 0)
    {
        inverte.push_back(x % 10);
        x /= 10;
    }
    for (int i = inverte.size() - 1; i >= 0; i--)
    {
        res += inverte[i] * a;
        a *= 10;
    }

    inverte.clear();
    return res;
}

int main()
{_
    int t, n, m, fs, sc;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        nivel.push(mp(n, 0));
        while(1)
        {
            fs = nivel.front().first;
            sc = nivel.front().second;
            nivel.pop();

            if (passou[fs] == 1) continue;
            passou[fs] = 1;

            if (fs == m)
            {
                cout << sc << endl;
                break;
            }

            nivel.push(mp(fs + 1, sc + 1));
            nivel.push(mp(inverter(fs), sc + 1));
        }

        while (!nivel.empty()) nivel.pop();
        passou.clear();
    }

}
    