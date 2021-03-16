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

int n, m, freq['z' + 1], resp['z' + 1];
string frutas[101], matrix[501];

int valido(string s, string k)
{
    int ok = 1;
    if (k.size() < s.size()) return 0;
    memset(freq, 0, sizeof(freq));
    memset(resp, 0, sizeof(resp));
    for (int i = 0; i < s.size(); i++)
    {
        freq[k[i]]++;
        resp[s[i]]++;
    }

    for (int j = 0; j < s.size(); j++)
    {
        if (freq[s[j]] != resp[s[j]]) ok = 0;
    }
    if (ok) return 1;


    for (int i = s.size(); i < k.size(); i++)
    {
        ok = 1;
        freq[k[i - s.size()]]--;
        freq[k[i]]++;
        for (int j = 0; j < s.size(); j++)
        {
            if (freq[s[j]] != resp[s[j]]) ok = 0;
        }
        if (ok) return 1;
    }
    return 0;
}

int main()
{_
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> frutas[i];
        transform(frutas[i].begin(), frutas[i].end(), frutas[i].begin(), ::tolower);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> matrix[i];
        transform(matrix[i].begin(), matrix[i].end(), matrix[i].begin(), ::tolower);
    }

    for (int i = 0; i < n; i++)
    {
        int ok = 0;
        for (int j = 0; j < m; j++)
            ok |= valido(frutas[i], matrix[j]);

        cout << (ok ? "Sheldon come a fruta " : "Sheldon detesta a fruta ") << frutas[i] << endl;
    }
}   