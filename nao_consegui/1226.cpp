#include <iostream>
#include <queue>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath> 
#include <iomanip>
#include <map>
#define INF 99999999
#define MOD 1000000007
#define par pair<int, int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int N;
map<int, int> memo;

int f(int x)
{
    if (memo[x]) return memo[x];
    
}

int main()
{_
    cin >> N;
    cout << f(N) << endl;
}