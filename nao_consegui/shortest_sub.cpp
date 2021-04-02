#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring>
#define ll long long
#define INF 99999999
#define MAX 300000
#define MOD 1000000007
#define par pair<int, int>
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int ft[1<<20][4], resp, tmp, n, letra[4], freq[4], r, R;
string s, k;

int query(int idx, int letra)
{   
    int ans = 0;
    while (idx > 0)
    {
        ans += ft[idx][letra];
        idx -= lsb(idx);
    }
    return ans;
}

void update(int idx, int val, int letra)
{
    while (idx < n)
    {
        ft[idx][letra] += val;
        idx += lsb(idx);
    }
}

int main()
{_  
    s = " ";
    cin >> k;
    s += k;
    n = s.size();
    for (int i = 1; i < n; i++)
    {
        if (s[i] == 'T') s[i] = 'B';
        else if (s[i] == 'G') s[i] = 'D';
        freq[s[i] - 'A']++;
        update(i + 1, 1, s[i] - 'A');
        letra[s[i] - 'A'] = i;
    }

    resp = INF;
    for (int i = 0; i < 4; i++)
    {
        s = (char) ('A' + i);
        if (!letra[i])
        {
            k = s;
            resp = 0;
            break;
        }
        tmp = INF;
        for (int j = 0; j < 4; j++)
        {
            if (tmp > query(letra[i], j))
            {
                r = j;
                tmp = query(letra[i], j);
            }
        }
        if (resp > tmp + 2)
        {
            k = s;
            R = r;
            resp = tmp + 2;
        }
    }

    if (R == 1) R = 'T' - 'A';
    else if (R == 3) R = 'G' - 'A';

    cout << k;
    for (int i = 1; i <= resp; i++)
    {
        cout << (char)('A' + R);
    }
    cout << endl;
}
