#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int ans = 1, k = 1;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1]) ans++;
        else ans = 1;
        k = max(k, ans);
    }

    cout << k << endl;
}