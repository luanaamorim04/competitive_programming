#include <cstdlib> 
#include <cstdio> 
#include <iostream>
#include <cstring> 
#include <bitset>

using namespace std;

bitset<30> row, d1, d2;
int row[15], n, t;
char tab[15][15];

int place(int r, int c) 
{
    if (tab[r][c] == '*') return 0;
    for (int prev = 0; prev < c; prev++) 
        if (row[prev] == r || (abs(row[prev] - r) == abs(prev - c)))
            return 0;
            
    return 1; 
}

int backtrack(int c) 
{
    int ans = 0;
    if (c == n) return 1;

    for (int r = 0; r < n; r++)
        if (place(r, c)) 
        {
            row[c] = r; 
            ans += backtrack(c + 1);
        }

    return ans;
}

int main() 
{ 
    while (cin >> n && n)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> tab[i][j];

        cout << "Case: " << ++t << ": " << backtrack(0) << endl;
    }
}