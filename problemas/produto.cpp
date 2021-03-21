#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, arr[100009], k, a, b, ft_0[100009], ft_neg[100009];
char c;

int query_neg(int idx)
{
    int ans = 0;
    while (idx > 0)
    {
        ans += ft_neg[idx];
        idx -= lsb(idx);
    }

    return ans;
}

int query_0(int idx)
{
    int ans = 0;
    while (idx > 0)
    {
        ans += ft_0[idx];
        idx -= lsb(idx);
    }

    return ans;
}

void update_neg(int idx, int val)
{
    while (idx <= n)
    {
        ft_neg[idx] += val;
        idx += lsb(idx);
    }
}

void update_0(int idx, int val)
{
    while (idx <= n)
    {
        ft_0[idx] += val;
        idx += lsb(idx);
    }
}

int main()
{_
    while (cin >> n >> k)
    {
        for (int i = 0; i <= n; i++)
        {
            ft_0[i] = 0;
            ft_neg[i] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            if (arr[i] < 0) update_neg(i, 1);
            else if (!arr[i]) update_0(i, 1);
        }

        while (k--)
        {
            cin >> c >> a >> b;
            if (c == 'C')
            {
                if (b < 0) 
                {
                    if (arr[a] < 0) continue;
                    if (!arr[a]) update_0(a, -1);
                    update_neg(a, 1);
                }
                else if (b == 0) 
                {
                    if (!arr[a]) continue;
                    if (arr[a] < 0) update_neg(a, -1);
                    update_0(a, 1);
                }
                else
                {
                    if (arr[a] < 0) 
                        update_neg(a, -1);
                    else if (arr[a] == 0)
                        update_0(a, -1);
                }
                
                arr[a] = b;
            }
            else
            {
                if (query_0(b) - query_0(a - 1)) cout << '0';
                else if ((query_neg(b) - query_neg(a - 1)) % 2 == 0) cout << '+';
                else cout << '-';
            }
        }

        cout << endl;
    }
}