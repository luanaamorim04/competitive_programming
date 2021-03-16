#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, res = 0;
    cin >> n;
    char s[101];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            cin >> s[i];
            if (s[i] == '{')
                res++;
            else if (s[i] == '}')
                res--;
            else if (s[i] == '\0')
                cout << 'a';
        }
    }

    cout << res << "\n\n";
}