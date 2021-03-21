#include <iostream>
#include <queue>
#include <map>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int t, n, f, a , b;
string ans[20000];
queue<int> fila;
map<int, int> passou;

int main()
{_
    cin >> t;
    while (t--)
    {
        cin >> n;
        fila.push(1);
        ans[1] = "1";
        passou[1] = 1;

        while (!fila.empty())
        {
            f = fila.front(); fila.pop(); 
            if (!(f%n))
            {
                cout << ans[f] << endl;
                break;
            }
            a = (f * 10) % n;
            b = (f * 10 + 1) % n;
            if (!passou[a])
            {
                fila.push(a); 
                passou[a] = 1;
                ans[a] = ans[f] + '0';
            }
            if (!passou[b])
            {
                fila.push(b); 
                passou[b] = 1;
                ans[b] = ans[f] + '1';
            }
        }

        passou.clear();
        while (!fila.empty()) fila.pop();
    }
}