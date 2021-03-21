#include <iostream>
#include <set>

using namespace std;

int t, d1, d2, row, x;
set<string> val;
set<string>::iterator it;

int dif(string a, string b)
{
    int x = 0;
    for (int i = 0; i < a.size(); i++)
    {
        x += (a[i] != b[i]);
    }

    return x;
}

void ini(int linha, string s)
{
    if (linha == 8) 
    {
        val.insert(s);
        return;
    }
    for (int i = 0; i < 8; i++)
    {
        if (row & (1<<i) || d1 & (1<<(i - linha + 7)) || d2 & (1<<(linha + i))) continue;
        row |= (1<<i);
        d1 |= (1<<(i - linha + 7));
        d2 |= (1<<(linha + i));
        ini(linha + 1, s + (char) ('0' + i));
        row -= (1<<i);
        d1 -= (1<<(i - linha + 7));
        d2 -= (1<<(linha + i));
    }
}

int main()
{
    ini(0, "");

    while (cin >> x)
    {
        int ans = 10;
        string s;
        s += (char) (x + '0' - 1);
        for (int i = 1; i < 8; i++)
        {   
            cin >> x;
            s += (char) (x + '0' - 1);
        }

        for (it = val.begin(); it != val.end(); it++)
        {
            ans = min(ans, dif(s, *it));
        }
        
        cout << "Case " << ++t << ": " << ans << endl;
    }
}