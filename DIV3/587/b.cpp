#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#include <set>
#define ll long long
#define INF 99999999
#define MAX 300000
#define MOD 1000000007
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, arr[200001], k;
set<par> s;
ll resp;
set<par>::iterator it;

int main()
{_
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        s.insert(par(-arr[i], i + 1));
    }

    for (it = s.begin(); it != s.end(); it++)
    {
        resp += -(*it).first * (k++);
        resp++;
    }

    cout << resp << endl;

    while (!s.empty())
    {
        cout << (*s.begin()).second << ' ';
        s.erase(*(s.begin()));
    }

    cout << endl;
}