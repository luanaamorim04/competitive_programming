#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#define ll long long
#define INF 99999999
#define MAX 300000
#define MOD 1000000007
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, resp, arr[200001];
string s;

int main()
{_
    cin >> n;
    cin >> s;
    s += 'c';
    for (int i = 0; i < n; i++)
        arr[i] = (s[i] == 'a');

    for (int i = 0; i < n; i+=2)
        if (s[i] == s[i + 1]) arr[i] ^= 1, resp++;

    cout << resp << endl;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]) cout << 'a';
        else cout << 'b';
    }

    cout << endl;
}