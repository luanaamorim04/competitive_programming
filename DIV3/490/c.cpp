#include <iostream>
#include <vector>

using namespace std;

int n, k, freq[1010], fs[1010], f[1010];
string s;

int main()
{
    cin >> n >> k;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        freq[s[i]]++;
    }

    for (int i = 'a'; i <= 'z'; i++)
    {
        if (k > 0) fs[i] = min(freq[i], k), k -= freq[i];
        freq[i] = 0;
    }

    for (int i = 0; i < s.size(); i++)
    {
        freq[s[i]]++;
        if (freq[s[i]] > fs[s[i]])
        cout << s[i];
    }

    cout << endl;
}