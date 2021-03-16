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

int v[200009], N, ans, a[100009], soma, maior, resp, m2, s2;

int main()
{_
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
        v[i] = a[i] * -1;
        soma += v[i];
    }
	
	for(int i = 1; i <= N; i++)
    {
		maior=max(0,maior+v[i]);
		resp=max(resp,maior);

        m2 = max(0,m2+a[i]);
		s2=max(s2,m2);
	}

    cout << max(-(soma - resp), s2) << endl;
}