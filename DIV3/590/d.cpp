#include <iostream>
#define lsb(x) ((x) & (-x))

using namespace std;

string s;
int q, ft[26][100009], n, x, a, b;
char c;

void update(int idx, int val, int k)
{
    while (idx <= n)
    {
        ft[k][idx] += val;
        idx += lsb(idx);
    }
}

int query(int idx, int k)
{
    int ans = 0;
    while (idx > 0)
    {
        ans += ft[k][idx];
        idx -= lsb(idx);
    }

    return ans;
}

int main()
{   
    cin >> s >> q;
    n = s.size();
    for (int i = 1; i <= s.size(); i++)
    {
        update(i, 1, s[i - 1] - 'a');
    }

    while (q--)
    {
        cin >> x;
        if (x == 1)
        {   
            cin >> a >> c;
            update(a, 1, c - 'a');
            update(a, -1, s[a - 1] - 'a');
            s[a - 1] = c;
        }
        else
        {
            cin >> a >> b;
            int ans = 0;
            for (int i = 0; i < 26; i++)
            {
                ans += (query(b, i) - query(a - 1, i) > 0);
            }
            cout << ans << endl;
        }
    }
}