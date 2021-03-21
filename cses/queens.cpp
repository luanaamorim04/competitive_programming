#include <iostream>
#include <vector>

using namespace std;

char tab[9][9];
vector<int> queens;

int f(int mask, int idx)
{
    if (mask == (1<<8) - 1) 
    {
        int ok = 1;
        for (int i = 0; i < 8; i++)
            for (int j = i + 1; j < 8; j++)
                if (abs(i - j) == abs(queens[i] - queens[j])) ok = 0;
        return ok;
    }
    int ans = 0;
    for (int i = 0; i < 8; i++)
    {
        if ((mask) & (1<<i)) continue;
        if (tab[idx][i] == '*') continue;
        queens.push_back(i);
        ans += f(mask + (1<<i), idx + 1); 
        queens.pop_back();
    }

    return ans;
}

int main()
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            cin >> tab[i][j];

    cout << f(0, 0) << endl;
}