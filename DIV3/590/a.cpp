#include <iostream>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define MAXN 100009
#define lsb(x) ((x) & (-x))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, arr[101], sum, q;

int main()
{_  
    cin >> q;
    while (q--)
    {
        cin >> n;
        sum = 0;
        for (int i = 0; i < n; i++) 
        {
            cin >> arr[i];
            sum += arr[i];
        }

        cout << (sum + n - 1) / n << endl;
    }   
}