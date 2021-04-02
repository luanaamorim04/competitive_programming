#include <iostream>
#include <map>
#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

string s;
int psa[1000005], last, j;
long long ans;
map<int, long long> freq;

int main()
{_
    cin >> s;
    psa[0] = 0;
    j = 1;
    freq[0] = 1;
    for (int i = 0; i < s.size(); i++)
    {
        psa[j] = s[i] - '0';
        if (psa[j] > 9 || psa[j] < 0)
        {
            freq.clear();
            freq[0] = 1;
            j = 1;
        }
        else
        {
            psa[j] = (psa[j] + psa[j - 1]) % 3;
            ans += freq[psa[j]];
            freq[psa[j++]]++;
        }
    }

    cout << ans << endl;
}