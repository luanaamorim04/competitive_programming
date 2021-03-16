#include <iostream> 

using namespace std;

int main()
{
    string s;
    int n;
    cin >> n;
    for (int h = 0; h < n; h++)
    {
        long long soma = 0;
        cin >> s;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '}' || s[i] == ']' || s[i] == ')')
            {
                soma = -999;
                break;
            }
            else if (s[i] != '{' && s[i] != '[' && s[i] != '(' )
                continue;

            soma++;
            for (int j = i + 1; j < s.size(); j++)
                if (s[j] == (s[i] + 2) || s[j] == (s[i] + 1))
                {   
                    soma--;
                    s[j] = '.';
                    break;
                }
        }

        if (soma != 0)
            cout << 'N' << endl;
        else
            cout << 'S' << endl;
    }
}