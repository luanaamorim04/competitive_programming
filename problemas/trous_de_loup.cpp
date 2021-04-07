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
#define MAX (int) ((2e6) + 1)
#define MOD 1000000007
#define par pair<int, int>
#define all(v) v.begin(), v.end()
#define lsb(x) (x & -x)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

deque<int> maior;
int n, k, idx, resp, l, r;
ll d, soma, val[MAX], psa[MAX];

int main()
{_
	cin >> n >> d >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> psa[i];
		psa[i] += psa[i - 1];
	}

	l = 1, r = k;
	while (r <= n)
	{
		soma = psa[r] - psa[r - k];
		val[++idx] = soma;
		while (!maior.empty() && val[maior.front()] <= soma) maior.pop_front();
		while (!maior.empty() && maior.back() < l) maior.pop_back();
		maior.push_front(idx);

		while (d < (psa[r]-psa[l-1])-val[maior.back()]) l++;

		resp = max(resp, r-l+1);

		//cout << l << ' ' << r <<  ' ' << val[maior.back()] << endl;;
		++r;
	}
	cout << resp << endl;
}









