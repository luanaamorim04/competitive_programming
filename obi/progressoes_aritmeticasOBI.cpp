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
#define ll long long
#define INF (1e9)
#define MAX (2e5)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

/*
	f(i, ini) = menor quantidade de partes que devemos separar o array a partir da posição i, 
	com i sendo o inicio da PA se ini == 1.
	resposta = f(0, 1);
*/
int n, arr[1<<20], memo[1<<20][1];

int f(int i, int ini)
{
	if (i >= n) return 1;
	if (~memo[i][ini]) return memo[i][ini];
	if (ini == 1) return memo[i][ini] = min(f(i+1, 1) + 1, f(i+2, 0));
	if (arr[i-1]-arr[i-2] == arr[i]-arr[i-1]) return memo[i][ini] = min(f(i+1, 1) + 1, f(i+1, 0));
	return memo[i][ini] = f(i, 1) + 1;
}

int main()
{_
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	memset(memo, -1, sizeof(memo));
	cout << f(0, 1) << endl;
}





