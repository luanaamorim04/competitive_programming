#include <iostream>
#include <map>
#define i long long

using namespace std;

i n, k, s, x, ans;
map<i, i> freq;

int main()
{
    cin >> n >> k;
    freq[0] = 1;
    while (n--){
        cin >> x;
        s += x;
        ans += freq[s-k];
        ++freq[s];
    }
    cout << ans << endl;
    return 0;
}

