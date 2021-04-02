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

int n, errado[101], l, r, idx;
string k, s[101], ini, fim, h;
vector<string> meios;

void f()
{   
    r = k.size();
    if (k[0] != '*')
    {
        for (int i = 0; (i < k.size() && k[i] != '*'); i++)
            ini += k[i], l = i;
        l++;
    }
    if (k[k.size() - 1] != '*')
    {
        for (int i = k.size() - 1; (i >= 0 && k[i] != '*'); i--)
            fim += k[i], r = i;
        r--;
    }
    for (int i = l + 1; i < r; i++)
    {
        if (k[i] != '*') h += k[i];
        if (k[i] == '*' || i == r - 1) 
        {
            meios.push_back(h);
            h.clear();
        }
    }
}

int main()
{_
    cin >> k >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];

    f();

    for (int i = 0; i < n; i++)
    {
        if (s[i].size() < ini.size()) 
        {
            errado[i] |= 1;
            continue;
        }
        for (int j = 0; j < ini.size(); j++)
            if (s[i][j] != ini[j]) errado[i] |= 1;
    }

    for (int i = 0; i < n; i++)
    {
        if (s[i].size() < fim.size()) 
        {
            errado[i] |= 1;
            continue;
        }
        for (int j = 0; j < fim.size(); j++)
            if (s[i][s[i].size() - 1 - j] != fim[j]) errado[i] |= 1;
    }

    for (int i = 0; i < meios.size(); i++)
    {
        for (int j = 0; j < n; j++) 
            if (s[j].find(meios[i]) == string::npos) errado[j] |= 1;
    }

    for (int i = 0; i < n; i++)
    {
        if (errado[i]) continue;
        cout << s[i] << endl;
    }
}   
