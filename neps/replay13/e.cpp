#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring>
#include <set>
#include <stack>
#include <bitset>
#define ll long long
#define INF (1e9)
#define MAX (int) (2e5 + 5)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define sz(x) (int) ((x).size())
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define lsb(x) (x & -x)
#define W(x) cout << #x << ": " << x << endl
#define Wii(x) cout << x.first << ' ' << x.second << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

string a, b;
int arr[1000], arr2[1000];

int main()
{_
	cin >> a >> b;
	if (a.size() > b.size()) swap(a, b);	
	for (int i = 0; i < a.size(); i++)
	{
		if ((arr[b[i]] != a[i] && arr[b[i]]) || (arr2[a[i]] != b[i] && arr2[a[i]]) ) 
		{
			cout << "Nao" << endl;
			return 0;
		}

		arr[b[i]] = a[i];
		arr2[a[i]] = b[i];
	}
	cout << "Sim" << endl;
}






